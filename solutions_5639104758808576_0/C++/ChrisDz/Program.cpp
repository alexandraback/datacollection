#include <iostream>

int main()
{
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        int Smax;
        std::cin >> Smax;
        std::cin.get();

        int standing = 0;
        int friends = 0;
        for (int s = 0; s <= Smax; s++)
        {
            int n = std::cin.get() - 48;
            if (n == 0) continue;

            if (standing < s)
            {
                friends  += s - standing;
                standing += s - standing;
            }

            standing += n;
        }

        std::cout << "Case #" << (i + 1) << ": " << friends << std::endl;
    }

    return 0;
}
