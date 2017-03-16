#include <stdio.h>
int adj[1010][1010], vis[1010], in_deg[1010];
int dfs(int cur, int cnt)
{
    for (int i = 1; i <= adj[cur][0]; i++)
        if (vis[adj[cur][i]] != cnt)
        {
            vis[adj[cur][i]] = cnt;
            if (dfs(adj[cur][i], cnt))
                return 1;
        }
        else
            return 1;
    return 0;
}
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("a_large_out.txt", "w", stdout);
    int T, tcnt = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            in_deg[i] = 0;
        for (int i = 0; i < n; i++)
        {
            int m;
            scanf("%d", &m);
            adj[i][0] = m;
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &adj[i][j + 1]);
                adj[i][j + 1]--;
                in_deg[adj[i][j + 1]]++;
            }
        }
        for (int i = 0; i < n; i++)
            vis[i] = -1;
        int i;
        for (i = 0; i < n; i++)
            if (in_deg[i] == 0 && dfs(i, i))
                break;
        printf("Case #%d: %s\n", ++tcnt, i < n ? "Yes" : "No");
    }
    return 0;
}
