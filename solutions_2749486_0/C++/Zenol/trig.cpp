#include <iostream>
#include <cmath>

void compute(int x, int y)
{
    // int s = std::abs(x) + std::abs(y);
    // int n = sqrt(1.f + 8.f * s) / 2;

    std::string answer;
    int xp = 0;
    int yp = 0;
    // int s = std::abs(x) + std::abs(y);
    // int n = sqrt(1.f + 8.f * s) / 2;

    // std::string answer;
    // int xp = 0;
    // int yp = 0;

    // //We try to reach x, y
    // for (int i = n; i > 0; i--)
    // {
    //     if (std::abs(x - xp) >= std::abs(y - yp))
    //     {
    //         // case x
    //         if (xp > x)
    //         {
    //             xp -= n;
    //             answer = std::string("W").append(answer);
    //         }
    //         else
    //         {
    //             xp += n;
    //             answer = std::string("E").append(answer);
    //         }
    //     }
    //     else
    //     {
    //         // case y
    //         if (yp > y)
    //         {
    //             yp -= n;
    //             answer = std::string("S").append(answer);
    //         }
    //         else
    //         {
    //             yp += n;
    //             answer = std::string("N").append(answer);
    //         }
    //     }
    // }
    //We are probably not done, but we are near!

    while (xp > x)
    {
        xp -= 1;
        answer.append("EW");
    }
    while (xp < x)
    {
        xp += 1;
        answer.append("WE");
    }
    while (yp > y)
    {
        yp -= 1;
        answer.append("NS");
    }
    while (yp < y)
    {
        yp += 1;
        answer.append("SN");
    }

    std::cout << answer;
}

int main(void)
{
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        std::cout << "Case #" << (i + 1) << ": ";
        int x, y;
        std::cin >> x >> y;
        compute(x, y);
        std::cout << "\n";
    }
}
