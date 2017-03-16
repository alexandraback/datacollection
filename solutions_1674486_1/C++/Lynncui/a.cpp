#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> mat[1100];
int mk[1002][1002];
bool pu[1002];
bool pv[1002];

void dfs1(int u)
{
    if (pu[u])return;
    pu[u] = true;
    for (int j = 0; j < mat[u].size(); j++)
    {
        int v = mat[u][j];
        if (mk[u][v])continue;
        dfs1(v);
    }
}

void dfs2(int u)
{
    if (pv[u])return;
    pv[u] = true;
    if (pu[u])return;
    for (int j = 0; j < mat[u].size(); j++)
    {
        int v = mat[u][j];
        if (mk[u][v])continue;
        dfs2(v);
    }
}

void run()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        mat[i].clear();
    }
    
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int v;
            cin >> v;
            mat[i].push_back(v);
        }
    }
    
    memset(mk, false, sizeof(mk));
    
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            memset(pu, false, sizeof(pu));
            memset(pv, false, sizeof(pv));
            int u = i, v = mat[i][j];
            mk[u][v] = true;
            dfs1(u);
            dfs2(v);
            mk[u][v] = false;
            for (int k = 1; k <= n; k++)
            {
                if (pv[k] && pu[k])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)break;
        }
        if (flag)break;
    }
    
    printf("%s\n", flag ? "Yes" : "No");
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("a.out", "w", stdout);
    
    int N = 0;
    scanf("%d", &N);
    getchar();
    for (int k = 1; k <= N; k++)
    {
        printf("Case #%d: ", k);
        run();
    }
    return 0;
}
