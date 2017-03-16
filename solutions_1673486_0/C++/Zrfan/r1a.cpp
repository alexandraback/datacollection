#include<iostream>
using namespace std;
double ans,ans2,t1,f[100005];
int a,b,t,i;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&t);
    for (int i1=1;i1<=t;i1++)
    {
        scanf("%d %d",&a,&b);
        t1=1.0;
        for (i=1;i<=a;i++)
        {
            scanf("%lf",&f[i]);
            t1=t1*f[i]*1.0;
        }
        ans=(b-a+1)*1.0*(t1)+(b-a+1+b+1)*1.0*(1.0-t1);
        if (a==b)
        {
            ans2=t1*1.0+(1+b+1)*(1.0-t1);
        }
        else
        {
            ans2=b+2;
        }
        if ((ans-ans2)>1e-10) ans=ans2*1.0;
        t1=1.0;
        for (i=1;i<=a;i++)
        {
            t1=t1*f[i];
            ans2=(a-i+b-i+1)*t1+(a-i+b+1+b+1-i)*(1-t1);
            if ((ans-ans2)>1e-10) ans=ans2*1.0;
        }
        printf("Case #%d: %.6lf\n",i1,ans);
    }
    return 0;
}
