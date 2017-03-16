// CJ1.cpp : Defines the entry point for the console application.
//

#include <iostream>

int main(void)
{
    int t = 0;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        unsigned int n = 0;
        std::cin >> n;

        if (0 == n)
        {
            std::cout << "Case #" << i+1 << ": " << "INSOMNIA" << std::endl;
            continue;
        }

        unsigned int last = 0;
        unsigned int flag = 0x3FF;
        while (0 != flag)
        {
            if (last+n < last)
            {
                std::cout << "Case #" << i+1 << ": " << "INSOMNIA" << std::endl;
                break;
            }

            last += n;

            unsigned int tmp = last;
            while (0 != tmp)
            {
                flag = flag & (~(1 << (tmp%10)));
                tmp = tmp / 10;
            }

            if (0 == flag)
                std::cout << "Case #" << i+1 << ": " << last << std::endl;
        }
    }

	return 0;
}

