// CJ4.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <math.h>

#include <vector>

void printdemo()
{
    int k = 4;
    int c = 3;
    unsigned int top = 1 << k;

    std::vector<std::string> orig;
    std::vector<std::string> comp;
    for (int i = 0; i < top; i++)
    {
        std::string str = "";
        for (int j = k-1; j >= 0; j--)
        {
            if (0 == (i & (1 << j)))
                str.append("0");
            else
                str.append("1");
        }

        orig.push_back(str);
        comp.push_back(str);
    }

    for (int i = 0; i < orig.size(); i++)
    {
        for (int j = 1; j < c; j++)
        {
            std::string tmp = "";
            for (int y = 0; y < comp[i].size(); y++)
            {
                if ('0' == comp[i][y])
                {
                    for (int x = 0; x < k; x++)
                        tmp.append("0");
                }
                else
                    tmp.append(orig[i]);
            }

            comp[i] = tmp;
        }
    }

    for (int i = 0; i < orig.size(); i++)
    {
        std::cout << orig[i].c_str() << " " << comp[i].c_str() << std::endl;
    }
}

int main(void)
{
    //printdemo();

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
        
        if (1 == s && c < k)
        {
            std::cout << " IMPOSSIBLE" << std::endl;
            continue;
        }

        if (s + c < k)
        {
            std::cout << " IMPOSSIBLE" << std::endl;
            continue;
        }

        if (1 == s)
        {
            std::cout << " 2" << std::endl;
            continue;
        }

        unsigned __int64 ceil = pow(k, c);
        int tot = 0;
        int j = 2;
        while (tot < s)
        {
            std::cout << " " << j;
            tot++;
            if (tot >= s)
                break;

            std::cout << " " << ceil-j+1;
            tot++;

            j++;
        }
        std::cout << std::endl;
    }

	return 0;
}

