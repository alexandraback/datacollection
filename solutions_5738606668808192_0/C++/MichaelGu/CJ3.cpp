// CJ3.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <math.h>

unsigned __int64 getDivisor(unsigned __int64 n)
{
    unsigned __int64 sq = sqrt(n) + 2;

    for (unsigned __int64 i = 2; i < sq; i++)
    {
        if (0 == n % i)
            return i;
    }

    return 0;
}

unsigned __int64 getNumBaseOn(unsigned num, int base)
{
    if (2 == base)
        return num;

    unsigned __int64 tmp = 1;
    unsigned __int64 result = 0;
    while (num > 0)
    {
        result = result + tmp*(num%2);
        tmp = tmp * base;
        num = num >> 1;
    }

    return result;
}

int main(void)
{
    int t = 0;
    std::cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n = 0;
        int j = 0;

        std::cin >> n;
        std::cin >> j;

        std::cout << "Case #" << i << ":\n";

        unsigned int low = 1 << (n-2);
        unsigned int high = 1 << (n-1);
        int count = 0;
        for (unsigned int k = low; k < high && count < j; k++)
        {
            unsigned int raw = (k << 1) + 1;

            int base = 2;
            unsigned __int64 div[11] = {0};
            for (; base <= 10; base++)
            {
                unsigned __int64 tmp = getNumBaseOn(raw, base);
                div[base] = getDivisor(tmp);
                if (0 == div[base])
                    break;
            }

            if (base > 10)
            {
                for (int m = 0; m < n; m++)
                {
                    std::cout << ((raw & (1<<(n-m-1))) >> (n-m-1));
                }

                for (int base = 2; base <= 10; base++)
                    std::cout << " " << div[base];
                std::cout << std::endl;

                count++;
            }
        }
    }

	return 0;
}

