#include<stdio.h>
#include<iostream>
using namespace std;
int t;
double c,f,x,base,ans;
double ar[100005],sum[100005];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);

    scanf("%d",&t);
    for (int l=1;l<=t;l++)
    {
        scanf("%lf %lf %lf",&c,&f,&x);

        base=2.0;
        sum[0]=0;
        for (int i=1;i<=100000;i++)
        {
            ar[i]=c/base;
            sum[i]=sum[i-1]+ar[i];
            base+=f;
        }

        ans=1000000000;
        base=2.0;
        for (int i=0;i<=100000;i++)
        {
            ans=min(ans,sum[i]+(x/base));
            base+=f;
        }

        printf("Case #%d: %.7lf\n",l,ans);
    }
    return 0;
}
