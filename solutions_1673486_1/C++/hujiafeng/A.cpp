#include<iostream>
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<cmath>
using namespace std;
double a[100005];
double p[100005];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A.out","w",stdout);
    int T,A,B;
    double ans=0;
    int i ;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        printf("Case #%d: ",cas);
        scanf("%d%d",&A,&B);
        p[0]=1;
        for(i=1;i<=A;i++)
        {
            scanf("%lf",&a[i]);
            p[i]=p[i-1]*a[i];
        }
        ans=B+2;
        ans=min(ans, p[A]*(B-A+1)+(1-p[A])*(2*B-A+2));
        for(i=1;i<=A;i++)
        {
            ans=min(ans,p[A-i]*(2*i+B-A+1)+(1-p[A-i])*(2*i+B-A+1+B+1));
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}
