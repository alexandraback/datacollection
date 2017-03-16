#include <cstdio>
#include <iostream>
#define MAXN 20
using namespace std;

int s[MAXN+1],p[MAXN+1];
int n;

int DFS(int k,int c1,int c2)
{
    if((c1!=0)&&(c2!=0)&&(c1==c2))
    {
        return 1;
    }
    if(k==n)
    {
        return 0;
    }
    p[k]=1;
    if(DFS(k+1,c1+s[k],c2)==1)
    {
        return 1;
    }
    p[k]=2;
    if(DFS(k+1,c1,c2+s[k])==1)
    {
        return 1;
    }
    p[k]=0;
    if(DFS(k+1,c1,c2)==1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    int k,t,i;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        memset(p,0,sizeof(p));
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&s[i]);
        }
        printf("Case #%d:\n",k+1);
        if(DFS(0,0,0)==1)
        {
            for(i=1;i<=n;i++)
            {
                if(p[i]==1)
                {
                    printf("%d ",s[i]);
                }
            }
            printf("\n");
            for(i=1;i<=n;i++)
            {
                if(p[i]==2)
                {
                    printf("%d ",s[i]);
                }
            }
            printf("\n");
        }
        else
        {
            printf("Impossible\n");
        }
    }
    return 0;
}
