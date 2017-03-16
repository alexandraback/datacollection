#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>

typedef long long LL;
using namespace std;
const int maxn = 1005;
int n,m;
vector<int>V[maxn];
bool vis[maxn];
bool flag;
int sum[maxn];

void DFS(int x)
{
    int i;

    if(flag) return;
    vis[x] = 1;
    sum[x] ++;

    if(sum[x] >= 2)
    {
        flag = true; return;
    }
    for(i=(int)V[x].size()-1; i>=0; i--)
    {
        DFS(V[x][i]);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int cas,ta=1;
    cin >> cas;
    while(cas--)
    {
        cin >> n;
        int i;

        for(i=1; i<=n; i++)
           V[i].clear();

        for(i=1; i<=n; i++)
        {
            cin >> m;
            while(m--)
            {
                int x;
                cin >> x;
                V[i].push_back(x);
            }
        }

        flag = 0;
        memset(vis,0,sizeof(vis));
        for(i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                memset(sum,0,sizeof(sum));
                DFS(i);
            }

            if(flag)
              break;
        }
        printf("Case #%d: ",ta++);
        if(i <= n) puts("Yes");
        else puts("No");
    }
    return 0;
}
