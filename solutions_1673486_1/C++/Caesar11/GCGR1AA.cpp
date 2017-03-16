#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstring>
#define N 200000
#define oo 1e20
using namespace std;

double p[N];
double sum[N];

int main()
{
    int t,a,b,n,i,j,ys;
    double e1,e2,e3,tmp,ans;


    freopen("A-large.in","r",stdin);
    freopen("data.out","w",stdout);

    scanf("%d",&t);
    ys=0;
    while (t--)
    {
        scanf("%d%d",&a,&b);
        sum[0]=1;
        for (i=1;i<=a;i++)
        {
            scanf("%lf",&p[i]);
            sum[i]=sum[i-1]*p[i];
        }

        e1=sum[a]*(b-a+1)+(1.0-sum[a])*(b-a+1+b+1);

        e2=oo;
        for (i=1;i<=a;i++)
        {
            tmp=sum[a-i]*(2*i+b-a+1)+(1.0-sum[a-i])*(2*i+b-a+1+b+1);
            e2=min(e2,tmp);
        }

        e3=b+2;

        ans=oo;

        ans=min(ans,e1);
        ans=min(ans,e2);
        ans=min(ans,e3);

        printf("Case #%d: %.6f\n",++ys,ans);
    }

    return 0;
}


