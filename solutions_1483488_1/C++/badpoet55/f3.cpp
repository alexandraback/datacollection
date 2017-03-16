//GCJ Q p3 f3

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool c[20000100];
int t, a, b, n, i, j, k, ans, g[10], gn;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> a >> b;
        ans = 0;
        memset(c, 0, sizeof(c));
        for (int i = a; i <= b; i++)
            if (!c[i])
            {
                memset(g, 0, sizeof(g));
                c[i] = true;
                j = i, gn = 0, k = 1;
                while (j)
                {
                    g[gn++] = j % 10;
                    j /= 10;
                }
                for (j = 0; j < gn; j++)
                {
                    if (!g[j]) continue;
                    int jj = j, tmp = 0;
                    while (true)
                    {
                        tmp = tmp * 10 + g[jj];
                        if (--jj < 0) jj = gn - 1;
                        if (jj == j) break;
                    }
                    if (!c[tmp])
                    {
                        c[tmp] = true;
                        if (tmp <= b && tmp >= a) k++;
                    }
                }
                ans += k * (k - 1) / 2;
            }
        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}
