#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    map < char, char > mymap;
    int case_all, case_count = 1;
    scanf("%d\n", &case_all);
    for (case_count = 1; case_count <= case_all; case_count += 1)
    {
        int n, s, p, m, res = 0;
        scanf("%d %d %d", &n, &s, &p);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &m);
            if (m == 0)
            {
                if (p == 0)
                {
                    ++res;
                }
                continue;
            }
            if (m % 3 == 0)
            {
                if (m / 3 >= p)
                {
                    ++res;
                    continue;
                }
                else
                {
                    if (m / 3 + 1 >= p && s >= 1)
                    {
                        ++res;
                        --s;
                        continue;
                    }
                }
            }
            if (m % 3 == 1)
            {
                if (m / 3 + 1 >= p)
                {
                    ++res;
                    continue;
                }
            }
            if (m % 3 == 2)
            {
                if (m / 3 + 1 >= p)
                {
                    ++res;
                    continue;
                }
                else
                {
                    if (m / 3 + 2 >= p && s >= 1)
                    {
                        ++res;
                        --s;
                        continue;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", case_count, res);
    }
    return 0;
}
