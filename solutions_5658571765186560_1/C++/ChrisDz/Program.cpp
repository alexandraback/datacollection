#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

bool win(int X, int height, int gap, int incr, int maxHeight)
{
    for (int i = 0; i <= (maxHeight - height); ++i)
    {
        if (((i * incr) + gap) % X == 0)
        {
            return false;
        }
    }

    return true;
}

bool compute(int X, int R, int C)
{
    switch (X)
    {
    case 1:
        return false;

    case 2:
        return (R * C) % 2 != 0;

    case 3:
        return (R * C) % 3 != 0
            || std::min(R, C) < 2;

    case 4:
        return (R * C) % 4 != 0
            || std::min(R, C) < 2

            || (std::min(R, C) == 2 && win(X, 2, 0, std::min(R, C), std::max(R, C)))

            || (std::min(R, C) == 2 && win(X, 3, 0, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 2 && win(X, 3, 1, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 2 && win(X, 3, 2, std::min(R, C), std::max(R, C)));

    case 5:
        return (R * C) % 5 != 0
            || std::min(R, C) < 3

            || (std::min(R, C) == 3 && win(X, 3, 0, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 3 && win(X, 3, 1, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 3 && win(X, 3, 2, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 3 && win(X, 3, 3, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 3 && win(X, 3, 4, std::min(R, C), std::max(R, C)));

    case 6:
        return (R * C) % 6 != 0
            || std::min(R, C) < 3

            || (std::min(R, C) == 3 && win(X, 3, 0, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 3 && win(X, 3, 1, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 3 && win(X, 3, 2, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 3 && win(X, 3, 3, std::min(R, C), std::max(R, C)))

            || (std::min(R, C) == 3 && win(X, 4, 0, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 3 && win(X, 4, 1, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 3 && win(X, 4, 2, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 3 && win(X, 4, 3, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 3 && win(X, 4, 4, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 3 && win(X, 4, 5, std::min(R, C), std::max(R, C)))
            || (std::min(R, C) == 3 && win(X, 4, 6, std::min(R, C), std::max(R, C)));

    default:
        return true;
    }
}

int main()
{
    int T;
    std::cin >> T;

    for (int i = 1; i <= T; ++i)
    {
        int X, R, C;
        std::cin >> X >> R >> C;

        std::cout << "Case #" << i << ": " << (compute(X, R, C) ? "RICHARD" : "GABRIEL") << std::endl;
    }

    return 0;
}
