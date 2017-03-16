// CJ2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <stack>

void flip(bool pans[100], int len)
{
    for (int i = 0; i <= len-i; i++)
    {
        bool tmp = !pans[i];
        pans[i] = !pans[len-i];
        pans[len-i] = tmp;
    }
}

int main(void)
{
    int t = 0;
    std::cin >> t;

    for (int i = 1; i <= t; i++)
    {
        std::string str;
        std::cin >> str;

        bool pans[100];
        int len = str.size();
        for (int j = 0; j < len; j++)
        {
            if ('-' == str.at(j))
                pans[j] = false;
            else
                pans[j] = true;
        }

        int n  = 0;
        std::stack<int> trace;
        trace.push(len-1);

        while (!trace.empty())
        {
            bool side = (1 == (trace.size() % 2));
            int top = trace.top();

            int j = top;
            for (; j >= 0; j--)
            {
                if (pans[j] != side)
                {
                    int k = j-1;
                    for (; k >= 0; k--)
                    {
                        if (pans[k] == side)
                        {
                            trace.push(j-1);
                            break;
                        }
                    }

                    if (k < 0)
                    {
                        flip(pans, j);
                        n++;
                    }

                    break;
                }
            }

            if (j < 0)
                trace.pop();
        }

        std::cout << "Case #" << i << ": " << n << std::endl;
    }

	return 0;
}

