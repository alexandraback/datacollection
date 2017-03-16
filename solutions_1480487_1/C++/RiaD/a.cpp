#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int sc[203];

int main()
{
    freopen("a.txt","r",stdin);
    freopen("a.out","w",stdout);
    int test,cas,n,i,j,c1;
    double x,lo,hi,mid,req,sum;
    scanf("%d",&test);
    for (cas=1;cas<=test;cas++)
    {
        scanf("%d",&n);
        x=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&sc[i]);
            x+=sc[i];
        }
        printf("Case #%d:",cas);
        for (i=0;i<n;i++)
        {
            lo=0.0;
            hi=1.0;
            c1=0;
            while (c1<100)
            {
                c1++;
                mid=(lo+hi)/2.0;
                req=sc[i]+x*mid;
                sum=0.0;
                for (j=0;j<n;j++)
                {
                    if (i==j) continue;
                    sum+=max((req-sc[j])/x,0.0);
                }
                if (1.0-mid>sum) lo=mid;
                else hi=mid;
            }
            printf(" %.10lf",((lo+hi)/2.0)*100.0);
        }
        printf("\n");
    }
    return 0;
}
