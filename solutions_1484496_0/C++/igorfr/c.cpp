#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

// Problem C

int main (void)
{
    int casos;
    scanf ("%d", &casos);

    for (int caso = 1; caso <= casos; ++caso)
    {
        printf ("Case #%d:\n", caso);

        int n;
        scanf ("%d", &n);

        map<int,int> m;
        vector<int> s;
        for (int i = 0; i < n; ++i)
        {
            int x;
            scanf ("%d", &x);
            s.push_back(x);
        }

        sort(s.begin(), s.end());

        int mask = 0;
        while (mask < (1<<n))
        {
            int sum = 0;
            for (int i = 0; i < n; ++i)
            {
                if (mask & (1<<i)) sum += s[i];
            }

            map<int,int>::iterator it = m.find(sum);
            if (it != m.end())
            {
                bool flag = false;
                int mask1 = it->second;
                for (int i = 0; i < n; ++i)
                {
                    if (mask1 & (1<<i))
                    {
                        if (flag) printf (" ");
                        else flag = true;
                        printf ("%d", s[i]);
                    }
                }
                printf ("\n");
                flag = false;
                for (int i = 0; i < n; ++i)
                {
                    if (mask & (1<<i))
                    {
                        if (flag) printf (" ");
                        else flag = true;
                        printf ("%d", s[i]);
                    }
                }
                printf ("\n");
                break;
            }
            else
            {
                m[sum] = mask;
            }

            ++mask;
        }
    }

    return 0;
}

