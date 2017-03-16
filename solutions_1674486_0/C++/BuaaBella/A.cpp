#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int map[1010][1010];
bool vis[1010];
bool yes;

void dfs(int s)
{
    vis[s] = true;
    for (int i = 1; i <= n; ++i)
        if (s != i && map[s][i])
        {
            if (vis[i])
            {
                yes = true;
                return;
            }else dfs(i);
        }
}
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int T;
    scanf("%d",&T);
    for (int ca = 1; ca <= T; ca++)
    {
        scanf("%d",&n);
        int x,y;yes = false;
        memset(map,0,sizeof(map));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d",&x);
            for (int j = 1; j <= x; ++j)
            {
                scanf("%d",&y);
                map[i][y] = 1;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            memset(vis,false,sizeof(vis));
            dfs(i);
        }
        printf("Case #%d: ",ca);
        if (yes)    printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
