#include <SFML/Graphics.hpp>

const float PI = acos(0.0f) * 2;

void drawCircle(sf::RenderWindow& window, float x, float y, float r)
{
    sf::Vertex point;
    point.color = sf::Color::White;

    float X = x
        , Y = y;

    for (float a = 0.0f; a < 2 * PI; a += 0.01f)
    {
        x = r * cos(a);
        x += X;
        y = r * sin(a);
        point.position = sf::Vector2f(x, y);

        window.draw(&point, 2, sf::Points);
    }
    
    if (r > 2.0f)
    {
        drawCircle(window, X + r, Y, r * 0.5f);
        drawCircle(window, X - r, y, r * 0.5f);
    }
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 10;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Drawing Circles with Recursion", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    
    float radius = 100.0f;

    sf::View view = window.getDefaultView();
    view.setCenter(radius * 4.0f, 0.0f);
    window.setView(view);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        drawCircle(window, 400, 300, radius);

        window.display();
    }

    return 0;
}
