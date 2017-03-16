#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

#define MP make_pair
#define PB push_back

const int V = 1100;

int n;
vector<int> adj[V];
bool bo[V], vis[V];

bool dfs(int v)
{
    bo[v] = true;
    for (int i=0;i<adj[v].size();i++)
    {
        if (!bo[ adj[v][i] ]) 
        {
            if (dfs(adj[v][i])) return true;
        }else
            return true;
    }
    return false;
}
int main()
{
    int test;
    scanf("%d",&test);
    for (int cas=1;cas<=test;cas++)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++) adj[i].clear();
        
        for (int i=0;i<n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            for (int j=0;j<tmp;j++)
            {
                int b;
                scanf("%d",&b);
                b--;
                adj[i].PB(b);
            }
        }
        bool yes = false;
        for (int i=0;i<n;i++) vis[i] = false;
        for (int i=0;i<n;i++)
        if (!vis[i])
        {
            for (int j=0;j<n;j++) bo[j] = false;
            if (dfs(i)) 
            {
                yes = true;
                break;
            }
            for (int j=0;j<n;j++) vis[j] |= bo[j];
        }
        printf("Case #%d: %s\n",cas, yes ? "Yes" : "No");
    }
}

