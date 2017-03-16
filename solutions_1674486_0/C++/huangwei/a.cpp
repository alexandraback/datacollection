#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define maxn 1005
#define maxm 1005*1005


struct node{
    int u,v,next;
}edge[maxm];

int head[maxn],tot;
bool mark[maxn];

void addedge(int a,int b)
{
    edge[tot].u=a;
    edge[tot].v=b; edge[tot].next=head[a]; head[a]=tot++;
}

bool dfs(int x)
{
    // printf("%d\n",x);
    if (mark[x]) return true;
    mark[x]=true;
    //printf("%d %d\n",x,head[x]);
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        if (dfs(edge[i].v)) return true;
    }
    return false;
}

int main()
{
    int t,i,j,a,b,m,n,cas=0;

    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        tot=0;
        memset(head,-1,sizeof(head));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&a);
                addedge(i+1,a);
            }
        }
        //for(i=0;i<tot;i++) printf("%d %d %d\n",i,edge[i].u,edge[i].v);
        for(i=1;i<=n;i++)
        {
            memset(mark,0,sizeof(mark));
            if (dfs(i))
            {
                printf("Case #%d: Yes\n",++cas);
                //printf("%d\n",i);
                break;
            }
        }
        if (i>n)
            printf("Case #%d: No\n",++cas);
    }
    return 0;
}
