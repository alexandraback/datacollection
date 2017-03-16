#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool flag;
vector<int> vec[1005];
bool vis[1005];

void dfs(int u)
{
    if (flag) return;
    vis[u] = 1;
    for (int i = 0; i < vec[u].size(); i++)
    {
        int v = vec[u][i];
        if (vis[v])
        {
            flag = 1;
            break;
        }
        dfs(v);
    }
}



int main ()
{
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int cas;
    scanf("%d", &cas);
    int K = 0;
    while (cas--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            vec[i].clear();
        }
        for (int i = 0; i < n; i++)
        {
            int m;
            scanf("%d", &m);
            for (int j = 0; j < m; j++)
            {
                int t;
                scanf("%d", &t);
                t--;
                vec[i].push_back(t);
            }
        }
        flag = false;
        for (int k = 0; k < n; k++)
        {
            memset(vis, 0, sizeof(vis));
            dfs(k);
            if (flag) break;
        }
        printf("Case #%d: ", ++K);
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
