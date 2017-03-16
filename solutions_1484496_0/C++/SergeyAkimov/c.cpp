#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forv(i, v) forn(i, v.size())

const double EPS = 1e-9;

using namespace std;

int n;
int s[1000];
int d[3000000];


pair<int, int> solve()
{
    forn(i, 3000000)
        d[i] = -1;

    forn(i, n)
        d[s[i]] = (1 << i);

    forn(i, 3000000)
    {
        if (d[i] == -1)
            continue;

        forn(j, n)
        {
            if ((d[i] >> j) & 1)
                continue;

            int new_mask = d[i] | (1 << j);
            if (d[i + s[j]] != -1 && d[i + s[j]] != new_mask)
            {
                return make_pair(d[i + s[j]], new_mask);
            }

            d[i + s[j]] = new_mask;
        }
    }

    return make_pair(-1, -1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    scanf("%d\n", &tests);
    forn(test, tests)
    {
        scanf("%d", &n);
        forn(i, n)
            scanf("%d", &s[i]);


        printf("Case #%d:\n", test + 1);
        pair<int, int> ans = solve();
        
        if (ans.first == -1)
        {
            printf("Impossible\n");
            continue;
        }

        forn(i, n)
            if ((ans.first >> i) & 1)
                printf("%d ", s[i]);
        printf("\n");
        forn(i, n)
            if ((ans.second >> i) & 1)
                printf("%d ", s[i]);

        printf("\n");    
    }


    return 0;
}