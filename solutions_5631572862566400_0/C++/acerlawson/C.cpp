//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<bitset>
#include<time.h>

#define Msn(x,y) (memset((x),0,sizeof((x[0]))*(y+1)))
#define msn(x) (memset((x),0,sizeof((x))))
#define msx(x) (memset((x),0x7f,sizeof((x[0]))))
#define fuck(x) cerr << #x << " <- " << x << endl
#define acer cout<<"sb"<<endl
#define mkp(x,y) (make_pair(x,y))
#define fi first
#define se second
#define ture true
#define lch  (id<<1)
#define rch (id<<1|1)

typedef long long ll;
using namespace std;
const int maxn=1003;

vector<int>g[maxn];

int n;
int vis[maxn],depth[maxn];
int anc[maxn];
int max_circle=0;

void dfs(int u,int fa,int id,int d)
{
    depth[u]=d;
    vis[u]=id;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)continue;
        if(vis[v]==id)
        {
            max_circle=max(max_circle,d-depth[v]+1);
            return;
        }
        dfs(v,u,id,d+1);
    }
}

int dfs2(int u,int fa)
{
    int maxx=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)continue;
        maxx=max(dfs2(v,u),maxx);
    }
    return maxx+1;
}
int main()
{
     freopen("C-small-attempt0.in","r",stdin);
    freopen("Cans.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        max_circle=0;
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)g[i].clear();
        for(int u=1;u<=n;u++)
        {
            int v;
            scanf("%d",&v);
            anc[u]=v;
            g[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])dfs(i,-1,i,0);
        }
//        printf("%d\n",max_circle);
        memset(vis,0,sizeof(vis));
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            int a=anc[i];
            if(anc[a]==i)
            {
                vis[i]=vis[a]=1;
                int l1=dfs2(i,a);
                int l2=dfs2(a,i);
                sum+=l1+l2;
            }
        }
        printf("Case #%d: %d\n",cas,max(max_circle,sum));
    }
    return 0;
}
