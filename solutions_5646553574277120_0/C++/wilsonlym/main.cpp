#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <cstring>

using namespace std;

int f[100];

int main()
{
    freopen("x.in", "r", stdin);
    freopen("x.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        int C, D, V;
        scanf("%d%d%d", &C, &D, &V);
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 0; i < D; i++)
        {
            int x;
            scanf("%d", &x);
            for (int j = 1; j <= C; j++)
            {
                for (int k = V; k > 0; k--)
                    if (k >= x *j) f[k] |= f[k - x * j];
            }
        }
        int ans = 0;
        for (int i = 0; i <= V; i++)
        {
            if (f[i] == 1) continue;
            ans++;
            for (int j = 1; j <= C; j++)
            {
                for (int k = V; k > 0; k--)
                    if (k >= i *j) f[k] |= f[k - i * j];
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
