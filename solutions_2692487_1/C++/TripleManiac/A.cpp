#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
int n,m,i,j,stop,cas,tst;
int a[120];
int ans=0,an;
int x;
int main()
{
    scanf("%d",&tst);
    for (cas=1;cas<=tst;cas++)
    {
        scanf("%d%d",&m,&n);
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("Case #%d: ",cas);
        if (m==1)
        {
           printf("%d\n",n);
           continue;
        }
        sort(a,a+n);
        ans=0x7fffffff;
        for (stop=0;stop<=n;stop++)
        {
            x=m;
            an=n-stop;
            for (i=0;i<stop;i++)
            {
                while (x<=a[i])
                {
                      x+=x-1;
                      an++;
                }
                x+=a[i];
            }
            if (an<ans) ans=an;
        }
        printf("%d\n",ans);
    }
//    system("PAUSE");
    return 0;
}
