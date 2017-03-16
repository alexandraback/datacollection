#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int>q[1010];
bool vis[1010];
bool flag;
int x0[1010];
void dfs(int n)
{
    if(flag) return;
//    if(vis[n])
//    {
//        flag = 1;
//        return;
//    }
    vis[n] = 1;
    x0[n]++;
    if(x0[n]>=2)
    {
        flag = 1;
        return;
    }
    int size = q[n].size();
    for(int i=0; i<size; i++)
    dfs(q[n][i]);
}
int main()
{
    //freopen("in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cas = 0;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            int k,x;
            scanf("%d",&k);
            while(k--)
            {
                scanf("%d",&x);
                q[i].push_back(x);
            }
        }
        flag = 0;
        memset(vis,0,sizeof(vis));

        for(int i=1; !flag&&i<=n; i++)
        if(!vis[i])
        {
            memset(x0,0,sizeof(x0));
            dfs(i);
        }
        printf("Case #%d: ",++cas);
        if(flag)
        printf("Yes\n");
        else
        printf("No\n");
        for(int i=1; i<=n; i++)
        q[i].clear();
    }
    return 0;
}
