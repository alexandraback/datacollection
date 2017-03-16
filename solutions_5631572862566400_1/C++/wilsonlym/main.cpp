#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int fa[1005], g[1005];
bool flag[1005];

int tryy(int x, int len)
{
    while (!flag[x])
    {
        flag[x] = true;
        len++;
        g[x] = max(g[x], len);
        if (fa[fa[x]] == x) break;
        x = fa[x];
    }
}

int main()
{
    freopen("x.in", "r", stdin);
    freopen("x.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        int n, ans = 0, ans2 = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &fa[i]); /// 1-based
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) flag[j] = false;
            flag[i] = true;
            int cur = fa[i], len = 1;
            while (!flag[cur])
            {
                flag[cur] = true;
                len++;
                if (fa[cur] == i) ans = max(ans, len);
                else              cur = fa[cur];
            }
        }

        for (int i = 1; i <= n; i++) g[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) flag[j] = false;
            tryy(i, 0);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
                if (fa[i] == j && fa[j] == i)
                {
                    ans2 += g[i] + g[j];
                }
        }
        ans = max(ans2, ans);
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
