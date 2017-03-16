#include<cstdio>
using namespace std;
int a[205];
double q[205],tt[205];
bool s[205];
int main ()
{
    freopen("A-small-attempt5.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,n,sum,tsum,num;
    double k;
    scanf("%d",&t);
    for(int i=1; i<=t; ++i)
    {
        scanf("%d",&n);
        sum=0;
        for(int j=1; j<=n; ++j)
        {
            s[j]=1;
            scanf("%d",&a[j]);
            sum+=a[j];
        }
        tsum=sum;
        num=n;
        printf("Case #%d:",i);
        for(int j=1; j<=n; ++j)
            tt[j]=double(a[j])/sum;
        k=2/double(n);
        for(int j=1; j<=n; ++j)
            if(k<=tt[j])
            {
                q[j]=0;
                s[j]=0;
                --num;
                tsum-=a[j];
            }
        k=double(sum+tsum)/num;
        for(int j=1;j<=n;++j)
            if(s[j])
            {
                q[j]=(k-a[j])/sum;
            }
        for(int j=1; j<=n; ++j)
            printf(" %.6lf",q[j]*100);
        printf("\n");
    }
    return 0;
}
