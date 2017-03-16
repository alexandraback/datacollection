#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
bool use[1005];
vector<int> mtx[1005];
bool check(int u)
{
    queue<int> q;
    memset(use,0,sizeof(use));
    use[u]=1;
    q.push(u);
    while(q.size())
    {
        int v=q.front();q.pop();
        int sz=mtx[v].size();
        for(int i=0;i<sz;i++)
        {
            int x=mtx[v][i];
            if(use[x])return 1;
            q.push(x);
            use[x]=1;
        }
    }
    return 0;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            mtx[i].clear();
            int m;
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                int x;
                scanf("%d",&x);
                mtx[i].push_back(x);
            }
        }
        bool flag=0;
        for(int i=1;i<=n;i++)
            if(check(i))
            {
                flag=1;
                break;
            }
        if(!flag)
            printf("Case #%d: No\n",++cas);
        else
            printf("Case #%d: Yes\n",++cas);
    }
    return 0;
}
