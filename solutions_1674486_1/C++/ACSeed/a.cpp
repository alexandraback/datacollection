#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;

const int MAX = 1010;

int vis[MAX];
int g[MAX][MAX], len[MAX];

bool dfs(int x)
{
    vis[x] = 1;
    for(int i = 0; i < len[x]; ++i)
    {
        if(vis[g[x][i]]) return true;
        else if(dfs(g[x][i])) return true;
    }
    return false;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for(int id = 1; id <= t; ++id)
    {
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n; ++i)
        {
            int m;
            scanf("%d",&m);
            len[i] = m;
            for(int j = 0; j < m; ++j)
            {
                scanf("%d",&g[i][j]);
                g[i][j]--;
            }
        }
        bool ans = false;
        for(int i = 0; i < n; ++i)
        {
            memset(vis, 0, sizeof(vis));
            ans = dfs(i);
            if(ans) break;
        }
        if(ans)
        {
            printf("Case #%d: Yes\n",id);
        }
        else printf("Case #%d: No\n",id);
    }
    return 0;
}
