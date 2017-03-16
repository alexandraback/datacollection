#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int ans, pos[20], bff[20], n, T, anspos[20];
bool v[20];
void check(int x)
{
    pos[0] = pos[x];
    pos[x + 1] = pos[1];
    int tmp = 0;
    for (int i = 1; i <= x; ++i)
    {
        tmp += (bff[pos[i]] == pos[i - 1] || bff[pos[i]] == pos[i + 1]);
    }
    if (tmp == x)
    {
        ans = max(tmp, ans);
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
            check(x);
            if (x < n) dfs(x + 1);
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
    }
    return 0;
}
