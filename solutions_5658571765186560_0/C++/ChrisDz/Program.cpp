#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

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
            || (R * C) == 3;

    case 4:
        return (R * C) % 4 != 0
            || (R * C) == 4
            || (R * C) == 8;

    default:
        return false;
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
