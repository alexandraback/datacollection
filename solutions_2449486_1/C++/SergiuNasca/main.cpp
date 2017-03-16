#include <stdio.h>
using namespace std;
int t,n,m,a[105][105];
int main()
{
    freopen("sergiu.in","r",stdin);
    freopen("sergiu.out","w",stdout);
    scanf("%d",&t);
    bool rezultat;
    bool pot1;
    bool pot2;
    for(int k=1;k<=t;++k)
    {
        rezultat=false;
        pot1=true;
        pot2=true;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                scanf("%d",&a[i][j]);
            }
        }
        if(n==1||m==1)
        {
            printf("Case #%d: YES\n",k);
            rezultat=true;
        }
        if(!rezultat)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=m;++j)
                {
                    pot1=true;
                    pot2=true;
                    for(int s=1;s<=m;s++)
                    {
                        if(a[i][s]>a[i][j])
                        {
                            pot1=false;
                            break;
                        }
                    }
                    for(int s=1;s<=n;++s)
                    {
                        if(a[s][j]>a[i][j])
                        {
                            pot2=false;
                            break;
                        }
                    }
                    if(!pot1&&!pot2)break;
                }
                if(!pot1&&!pot2)break;
            }
            if(!pot1&&!pot2)
            {
                printf("Case #%d: NO\n",k);
            }
            else printf("Case #%d: YES\n",k);
        }
    }
    return 0;
}
