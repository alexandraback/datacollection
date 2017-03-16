#include<cstdio>
using namespace std;

int a[205];
double ans[205],t[205];
bool f[205];

int main ()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int tot,n,sum,tsum,num;
    double key;
    scanf("%d",&tot);
    for(int cas=1; cas<=tot; cas++)
    {
        scanf("%d",&n);
        sum=0;
        for(int j=1; j<=n; ++j)
        {
            f[j]=1;
            scanf("%d",&a[j]);
            sum+=a[j];
        }
        tsum=sum;
        num=n;
        printf("Case #%d:",cas);
        for(int j=1; j<=n; ++j)
            t[j]=double(a[j])/sum;
        key=2/double(n);
        for(int j=1; j<=n; ++j)
            if(key<=t[j])
            {
                ans[j]=0;
                f[j]=0;
                --num;
                tsum-=a[j];
            }
        key=double(sum+tsum)/num;
        for(int j=1;j<=n;++j)
            if(f[j])
            {
                ans[j]=(key-a[j])/sum;
            }
        for(int j=1; j<=n; ++j)
            printf(" %.6lf",ans[j]*100);
        printf("\n");
    }
    return 0;
}



