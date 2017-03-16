#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int   maxn = 100 + 10;
int         n, s, p, t, a[maxn];

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d", &t);
    for (int l = 1; l <= t; ++l)
    {
        scanf("%d%d%d", &n, &s, &p);
        for (int i = 1; i <= n; ++i)
            scanf("%d", a + i);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] - p < 0)
                continue;
            a[i] = (a[i] - p) / 2;
            if (a[i] >= p - 1)
                ++ans;
            else
                if (a[i] == p - 2 && s)
                    ++ans, --s;
        }
        printf("Case #%d: %d\n", l, ans);
    }
    return 0;
}
