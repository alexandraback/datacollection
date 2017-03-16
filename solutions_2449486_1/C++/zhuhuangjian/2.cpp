#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int map[110][110];
int t,n,m;
int hmax[110];
int lmax[110];
int main()
{
    int k=1;
    //freopen("B.txt","r",stdin);
   // freopen("1.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(hmax,0,sizeof(hmax));
        memset(lmax,0,sizeof(lmax));
        int i;
        int j;
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        scanf("%d",&map[i][j]);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                hmax[i]=max(hmax[i],map[i][j]);
            }
        }
        for(j=1;j<=m;j++)
        {
            for(i=1;i<=n;i++)
            {
                lmax[j]=max(lmax[j],map[i][j]);
            }
        }
        int flag=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(map[i][j]<lmax[j]&&map[i][j]<hmax[i])
                {
                    flag=0;
                    break;
                }
            }
            if(!flag)
            break;
        }
        printf("Case #%d: %s\n",k++,flag?"YES":"NO");
    }
}
