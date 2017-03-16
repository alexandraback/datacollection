#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

vector <int> adj[1000];
int color[1000];

bool dfs1(int u)
{
    color[u] = 1; // gray
    for (int i = 0; i < (int)adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (color[v] == 0)
        {
            if (dfs1(v)) return true;
        }
        else if (color[v] == 2)// dia
        {
            return true;
        }
    }
    color[u] = 2; // black
    return false;
}

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int no = 1; no <= t; no++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int mi;
            scanf("%d", &mi);
            for (int j = 0; j < mi; j++)
            {
                int a;
                scanf("%d", &a);
                adj[i].push_back(a-1);
            }
        }

        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            memset(color, 0, sizeof(color));
            if (dfs1(i))
            {
                flag = true;
                break;
            }
        }
        if (flag) printf("Case #%d: Yes\n", no);
        else printf("Case #%d: No\n", no);

        for (int i = 0; i < n; i++) adj[i].clear();
    }
}
