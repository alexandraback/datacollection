#include <stdio.h>
#include <string.h>

int p[10],vis[2000003];

int main()
{
    freopen("c.txt","r",stdin);
    freopen("c.out","w",stdout);
    int test,cas,a,b,i,len,ans,j,k;
    p[0]=1;
    for (i=1;i<=8;i++) p[i]=p[i-1]*10;
    scanf("%d",&test);
    for (cas=1;cas<=test;cas++)
    {
        scanf("%d%d",&a,&b);
        memset(vis,0,sizeof(vis));
        for (i=0;p[i]<=a;i++) ;
        len=i;
        ans=0;
        for (i=a;i<=b;i++)
        {
            for (j=1;j<len;j++)
            {
                k=(i%p[j])*p[len-j]+(i/p[j]);
                if (k>i&&k<=b&&vis[k]!=i)
                {
                    ans++;
                    vis[k]=i;
                }
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
