#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 100000
using namespace std;

double p[MAXN+1];
int a,b;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int k,t,i;
    double r;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        scanf("%d %d",&a,&b);
        p[0]=1.0;
        for(i=1;i<=a;i++)
        {
            scanf("%lf",&p[i]);
            p[i]=p[i]*p[i-1];
        }
        r=b+2;
        for(i=0;i<=a;i++)
        {
            r=min(r,p[a-i]*(2*i+b-a+1)+(1.0-p[a-i])*(2*i+2*b-a+2));
        }
        printf("Case #%d: %.6f\n",k+1,r);
    }
    return 0;
}
