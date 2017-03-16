#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int nxt[1111],type[1111],n,ans,maxCir,Max[1111];
bool vis[1111];
vector<int> edge[1111];

int go(int i)
{
    if (vis[i]) return i;
    vis[i]=1;
    return go(nxt[i]);
}

void go(int i,int tp,int &x)
{
    if (type[i]!=0) return;
    ++x;
    type[i]=tp;
    go(nxt[i],tp,x);
}

void dfs(int i)
{
    Max[i]=1;
    for (vector<int>::iterator j=edge[i].begin();j!=edge[i].end();++j)
        if (type[*j]==0)
        {
            type[*j]=3;
            dfs(*j);
            Max[i]=max(Max[i],Max[*j]+1);
        }
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        scanf("%d",&n);
        fill(edge,edge+n+1,vector<int>());
        for (int i=1;i<=n;++i)
        {
            scanf("%d",nxt+i);
            edge[nxt[i]].push_back(i);
        }
        printf("Case #%d: ",cas);
        memset(type,0,sizeof(type));
        maxCir=0;
        for (int i=1;i<=n;++i)
            if (type[i]==0)
            {
                if (nxt[nxt[i]]==i) type[i]=type[nxt[i]]=1;
                else
                {
                    memset(vis,0,sizeof(vis));
                    int tmp=0;
                    if (go(i)==i) go(i,2,tmp);
                    maxCir=max(tmp,maxCir);
                }
            }
        memset(Max,0,sizeof(Max));
        ans=0;
        for (int i=1;i<=n;++i)
            if (type[i]==1)
            {
                dfs(i);
                ans+=Max[i];
            }
        ans=max(ans,maxCir);
        printf("%d\n",ans);
    }
    return 0;
}
