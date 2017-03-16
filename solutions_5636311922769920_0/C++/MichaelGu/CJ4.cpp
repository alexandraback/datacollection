// CJ4.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <math.h>

int main(void)
{
    int t = 0;
    std::cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int k, c, s = 0;
        std::cin >> k >> c >> s;

        std:: cout << "Case #" << i << ":";

        if (s < k && c < 2)
        {
            std::cout << " IMPOSSIBLE" << std::endl;
            continue;
        }

        if (1 == c)
        {
            for (int j = 1; j <= k; j++)
                std::cout << " " << j;
            std::cout << std::endl;

            continue;
        }

        if (1 == k)
        {
            std::cout << " " << 1 << std::endl;
            continue;
        }
        
        for (int j = 1; j < s; j++)
        {
            std::cout << " " << j+1;
        }

        std::cout << std::endl;
    }

	return 0;
}

