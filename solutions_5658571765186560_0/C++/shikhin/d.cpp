#include <iostream>

int main()
{
    int T; std::cin >> T;
    for (int test = 0; test < T; test++) {
        int X, R, C; std::cin >> X >> R >> C;

        if ((R * C) % X) goto richard;
        if (X > R && X > C) goto richard;
        if (X > 2 && ((R == 1) || (C == 1))) goto richard;

        if (X == 4) {
            if (R * C == 8) goto richard;
        }

        gabriel:
            std::cout << "Case #" << test + 1 << ": GABRIEL" << std::endl;
            continue;

        richard:
            std::cout << "Case #" << test + 1 << ": RICHARD" << std::endl;
            continue;
    }
}