#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

void solve()
{
    int n;
    int m1, d1, m2, d2;

    scanf("%d", &n);
    if (n == 4)
    {
        for (int i = 0; i < 4; i++)
            scanf("%*d%*d%*d");
        printf("0\n");
        return;
    }
    else if (n == 0)
    {
        printf("0\n");
        return;
    }
    else if (n == 1)
    {
        int d, h, m;
        scanf("%d%d%d", &d, &h, &m);
        if (h == 1)
        {
            printf("0\n");
            return;
        }
        m1 = m;
        m2 = m + 1;
        d1 = d2 = d;
    }
    else
    {
        scanf("%d%*d%d", &d1, &m1);
        scanf("%d%*d%d", &d2, &m2);
    }

    if (d1 > d2 || (d1 == d2 && m1 < m2))
    {
        swap(d1, d2);
        swap(m1, m2);
    }

    int ans = 0;
    if (m1 == m2)
    {
    }
    else if (m1 > m2)
    {
        int D = (360 - d2) + d1;
        if ((long long)d1 * (m1 - m2) + (long long)D * m2 <= 360LL * (m1 - m2))
            ans = 1;
    }
    else
    {
        int D = 360 + (d2 - d1);
        if ((long long)d2 * (m2 - m1) + (long long)D * m1 <= 360LL * (m2 - m1))
            ans = 1;
    }

    printf("%d\n", ans);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: ", i + 1);
        solve();
    }

    eprintf("time = %.3lf\n", (double) clock() / CLOCKS_PER_SEC);

    return 0;
}
