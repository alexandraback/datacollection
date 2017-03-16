#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

int mult(int a, int b)
{
    static const int table[4][4] =
    {
        { 1,  2,  3,  4 },
        { 2, -1,  4, -3 },
        { 3, -4, -1,  2 },
        { 4,  3, -2, -1 }
    };

    if ((a > 0 && b > 0) || (a < 0 && b < 0))
    {
        return table[std::abs(a) - 1][std::abs(b) - 1];
    }
    else
    {
        return -table[std::abs(a) - 1][std::abs(b) - 1];
    }
}

bool compute(int L, int X, const std::string& str)
{
    // Convert
    std::vector<int> original;
    for (int i = 0; i < X; ++i)
    {
        for (auto c : str)
        {
            original.push_back(c - 103);
        }
    }

    // Forward compute
    std::vector<int> fromStart(original.size(), 0);
    for (size_t i = 0; i < original.size(); ++i)
    {
        fromStart[i] = (i == 0)
            ? original[i]
            : mult(fromStart[i - 1], original[i]);
    }

    // Reverse compute
    std::vector<int> toEnd(original.size(), 0);
    for (int i = original.size() - 1; i >= 0; --i)
    {
        toEnd[i] = (i == original.size() - 1)
            ? original[i]
            : mult(original[i], toEnd[i + 1]);
    }

    // Find splits
    for (size_t i = 0; i < original.size(); ++i)
    {
        if (fromStart[i] == 2 /* i */)
        {
            int x = 0;
            for (size_t j = i + 1; j < original.size(); ++j)
            {
                x = (x == 0) ? original[j] : mult(x, original[j]);
                if (x == 3 /* j */ && j + 1 < original.size() && toEnd[j + 1] == 4 /* k */)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    int T;
    std::cin >> T;

    for (int i = 1; i <= T; ++i)
    {
        int L, X;
        std::string str;

        std::cin >> L >> X;
        std::cin.get();
        std::getline(std::cin, str);

        std::cout << "Case #" << i << ": " << (compute(L, X, str) ? "YES" : "NO") << std::endl;
    }

    return 0;
}
