#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 1000
#define MAXM 10000
using namespace std;

int head[MAXN+1],othr[MAXM+1],next[MAXM+1],used[MAXN+1],que[MAXN+1];
int n,m,e;

void addedge(int x,int y)
{
    othr[e]=y;
    next[e]=head[x];
    head[x]=e++;
}

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int k,t,i,j,x,y,f,qh,qt;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        memset(head,-1,sizeof(head));
        scanf("%d",&n);
        e=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(j=1;j<=m;j++)
            {
                scanf("%d",&x);
                addedge(x,i);
            }
        }
        f=0;
        for(i=1;(i<=n)&&(f==0);i++)
        {
            memset(used,0,sizeof(used));
            used[i]=1;
            que[0]=i;
            qh=0;
            qt=1;
            while(qh<qt)
            {
                x=que[qh++];
                for(j=head[x];j!=-1;j=next[j])
                {
                    y=othr[j];
                    if(used[y]==0)
                    {
                        used[y]=1;
                        que[qt++]=y;
                    }
                    else
                    {
                        f=1;
                        break;
                    }
                }
            }
        }
        printf("Case #%d: ",k+1);
        if(f==1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
