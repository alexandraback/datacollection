#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int ans, pos[20], bff[20], n, T, anspos[20];
bool v[20];
void check()
{
    pos[0] = pos[n];
    pos[n + 1] = pos[1];
    int tmp = 0;
    for (int i = 1; i <= n; ++i)
    {
        tmp += (bff[pos[i]] == pos[i - 1] || bff[pos[i]] == pos[i + 1]);
    }

    if (ans < tmp)
    {
        ans = tmp;
        for (int i = 1; i <= n; ++i)
        {
            anspos[i] = pos[i];
        }
    }
}
void dfs(int x)
{
    for (int i = 1; i <= n; ++i)
    {
        if (!v[i])
        {
            v[i] = 1;
            pos[x] = i;
            if (x < n) dfs(x + 1);
            else check();
            v[i] = 0;
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        printf("Case #%d: ", cas);
        scanf("%d", &n);
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &bff[i]);
        }
        dfs(1);
        printf("%d\n", ans);
        for (int i = 1; i <= n; ++i)
        {
            printf("%d ", anspos[i]);
        }
        printf("\n");
    }
    return 0;
}
