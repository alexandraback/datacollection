#include <iostream>

void pick_tiles(int K, int C, int S)
{
    if (K == 1)
    {
        std::cout << " 1" << std::endl;
        return;
    }
    if (C == 1 && K > S)
    {
        std::cout << " IMPOSSIBLE" << std::endl;
        return;
    }
    if (K == S)
    {
        for (int i = (C == 1) ? 1: 2; i <= K; ++i)
        {
            std::cout << " " << i;
        }
        std::cout << std::endl;
        return;
    }
    std::cout << " IMPOSSIBLE" << std::endl;
}

int main()
{
    int num_cases;
    std::cin >> num_cases;

    for (int current = 1; current <= num_cases; ++current)
    {
        int K, C, S;
        std::cin >> K >> C >> S;
        std::cout << "Case #" << current << ":";
        pick_tiles(K, C, S);
    }
    return 0;
}
