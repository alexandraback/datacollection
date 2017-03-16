#include <iostream>

int solve(int R, int C, int W)
{
    int result = R * (C / W);
    if (C % W == 0)
        result += W - 1;
    else
        result += W;
    return result;
}

int main()
{
    int T;
    std::cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int R, C, W;
        std::cin >> R >> C >> W;
        std::cout << "Case #" << t << ": " << solve(R, C, W) << "\n";
    }

    return 0;
}
