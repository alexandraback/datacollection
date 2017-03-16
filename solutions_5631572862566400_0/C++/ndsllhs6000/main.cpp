#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>

#define maxn 1000000
using namespace std;
const int inf = 10000;

int n;
int vis[1010];
int bff[1010];

int dfs(int u, int st, bool f)
{
    //printf("%d %d  ", u, f);
    int ret = 0;
    if (f)
    {
        int v = bff[u];
        if (v == st) return 0;
        if (vis[v]) return -1;
        if (bff[v] == u)
        {
            vis[v] = 1;
            ret = dfs(v, st, false)+1;
            vis[v] = 0;
            if (ret == 0) return -inf;
            return ret;
        }
        else
        {
            vis[v] = 1;
            ret = dfs(v, st, true)+1;
            vis[v] = 0;
            if (ret == 0) return -1;
            return ret;
        }
    }
    else
    {
        for (int i=1;i<=n;i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                if (bff[i] == u)
                {
                    int temp = dfs(i, st, false)+1;
                    ret = max(ret, temp);
                }
                else
                {
                    int temp = dfs(i, st, true)+1;
                    ret = max(ret, temp);
                }
                vis[i] = 0;
            }
        }
        return ret;
    }
}
int main()
{
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int kase=1;kase<=T;kase++)
    {
        scanf("%d", &n);
        for (int i=1;i<=n;i++) vis[i] = 0;
        for (int i=1;i<=n;i++)
        {
            int v;
            scanf("%d", &v);
            bff[i] = v;
        }
        int ans = 0;
        for (int i=1;i<=n;i++)
        {
            vis[i] =1;
            ans = max(dfs(i, i, true) + 1, ans);
            vis[i] = 0;
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}
