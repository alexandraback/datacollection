#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

char a[50][50];
int r, c, m;

void print()
{
    for (int i = 0 ; i < r ; ++i)
    {
        for (int j = 0 ; j < c ; ++j)
        {
            std::cout << a[i][j];
        }
        std::cout << '\n';
    }
}

void imp()
{
    std::cout << "Impossible\n";
}

int main()
{
	int T;
	std::cin >> T;
	for (int t = 1 ; t <= T ; ++t)
	{
        std::cin >> r >> c >> m;
        int min = std::min(r, c);
        int minm = min == 1 ? 2 : 4;
        int empty = r * c - m;
        std::cout << "Case #" << t << ":" 
            //<< " " << r << " " << c << " " << m 
            << "\n";
        if (empty > 1 
            && (empty < minm || (min == 2 && empty % 2 == 1)
                || (min > 2 && empty < 8 && empty % 2 == 1)))
        {
            imp();
        }
        else
        {
            for (int i = 0 ; i < r ; ++i)
                for (int j = 0 ; j < c ; ++j)
                    a[i][j] = '*';

            a[0][0] = 'c';
            --empty;

            if (min == 1)
            {
                for (int i = 0 ; i < r && empty ; ++i)
                    for (int j = 0 ; j < c && empty ; ++j)
                        if (i > 0 || j > 0)
                        {
                            a[i][j] = '.';
                            --empty;
                        }
            }
            else if (empty)
            {
                a[0][1] = '.';
                --empty;
                a[1][0] = '.';
                --empty;
                a[1][1] = '.';
                --empty;

                int s = 2;
                int rr = r - 1;
                int cc = c - 1;
                bool ok = false;
                while (empty > 1)
                {
                    /*bool bad = false;
                    if (empty == s)
                    {
                        bad = true;
                        empty -= 2;
                    }*/
                    for (int i = 0 ; i < r && empty ; ++i)
                    {
                        if (i == s && empty == 1)
                        {
                            ok = true;
                            rr = i - 1;
                            cc = s;
                            break;
                        }
                        for (int j = 0 ; j < c && empty ; ++j)
                            if (std::max(i, j) == s && a[i][j] == '*')
                            {
                                a[i][j] = '.';
                                empty--;
                            }
                    }
                    ++s;
                    if (ok)
                        break;
                    /*if (bad)
                        empty += 2;*/
                }
                if (empty == 1)
                {
                    rr = std::min(rr, s - 1);
                    cc = std::min(cc, s - 1);
                    a[rr][cc] = '*';
                    ++empty;
                    if (ok)
                        --s;
                    for (int i = 0 ; i < r && empty ; ++i)
                        for (int j = 0 ; j < c && empty ; ++j)
                            if ((i != rr || j != cc) && std::max(i, j) == s && a[i][j] == '*')
                            {
                                a[i][j] = '.';
                                --empty;
                            }
                }
            }

            print();
        }
	}
	return 0;
}

