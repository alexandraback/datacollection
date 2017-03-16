#include<cstdio>
#include<algorithm>
using namespace std;
double a[3],bs[3];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int cas=1; cas<=t; cas++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        for (int i=0; i<m; i++)
            scanf("%lf",&a[i]);
        double kt=0;
        for (int i=0; i<m; i++)
            bs[i]=0;
        for (int i=0; i<(1<<m); i++)
        {
            double p=1;
            for (int j=0; j<m; j++)
                if (1&(i>>j))
                    p*=a[j];
                else
                    p*=1-a[j];
            if (i+1==(1<<m))
                kt+=(n-m+1)*p;
            else
                kt+=(n-m+1+n+1)*p;
            for (int j=0; j<m; j++)
            {
                bool flag=1;
                for (int k=0; k<m-j-1; k++)
                    if (!(1&(i>>k)))
                        flag=0;
                if (flag)
                    bs[j]+=p*(j+1+n-m+j+1+1);
                else
                    bs[j]+=p*(j+1+n-m+j+1+1+n+1);
            }
        }
        double ans=min(n+2.0,kt);
        for (int i=0; i<m; i++)
            ans=min(bs[i],ans);
        printf("Case #%d: %f\n",cas,ans);
    }
    return 0;
}
