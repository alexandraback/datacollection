#include<stdio.h>
#include<algorithm>
using namespace std;
int a,b,c,d,e,f,g,ans;
int zz[1000005],zz2[1000005];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    scanf("%d",&a);
    for (b=1;b<=a;b++)
    {
        scanf("%d %d",&c,&d);
        for (e=1;e<=d;e++)
        {
            scanf("%d",&zz[e]);
        }
        sort(zz+1,zz+d+1);
        if (c==1){
            printf("Case #%d: %d\n",b,d);
            continue;
        }
        for (e=1;e<=d;e++)
        {
            f=0;
            while(c<=zz[e])
            {
                c+=c-1;
                f++;
            }
            c+=zz[e];
            zz2[e]=f;
        }
        f=ans=g=0;
        for (e=d;e>=1;e--)
        {
            f++;
            g+=zz2[e];
            if (f<g)
            {
                ans+=f;
                f=0;
                g=0;
            }
        }
        if (g>0) ans+=g;
        printf("Case #%d: %d\n",b,ans);
    }
    return 0;
}
