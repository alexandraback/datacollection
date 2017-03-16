#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <string>

using namespace std;

struct pos{
    int y,next;
};

const int maxn=1000*2;
int first[maxn];
bool mm[maxn];
int mark[maxn];
pos g[maxn*20];
int tot;

void addedge(int x,int y)
{
    //printf("H %d %d\n",x,y);
    g[++tot].y=y;
    g[tot].next=first[x];
    first[x]=tot;
}

bool dfs(int u,int x)
{
    for (int tmp=first[u];tmp!=-1;tmp=g[tmp].next)
    {
        int v=g[tmp].y;
        //printf("%d %d\n",u,v);

        if (mark[v]==x) return true;
        mark[v]=x;
        //printf("u=%d d=%d\n",v,x);
        if (dfs(v,x)) return true;
    }
    return false;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T,N,t,kk;
    scanf("%d",&T);
    for (int times=1;times<=T;times++)
    {
        scanf("%d",&N);
        tot=0;
        //printf("%d\n",N);
        memset(first,-1,sizeof(first));
        memset(mark,0,sizeof(mark));
        memset(mm,false,sizeof(mm));
        for (int i=1;i<=N;i++)
        {
            scanf("%d",&t);
            //printf("%d\n",t);
            if (t==0) mm[i]=true;
            for (int j=1;j<=t;j++)
            {
                scanf("%d",&kk);
                addedge(kk,i);
            }
        }
        //return 0;
        printf("Case #%d: ",times);
        bool pp=false;
        for (int i=1;i<=N;i++)
            if (mm[i])
            {
                //printf("!%d",i);
                if (dfs(i,i)) {
                    printf("Yes\n");
                    pp=true;
                    break;
                }
            }
        if (!pp) printf("No\n");
    }
}

