#include <iostream>
#include <cstdio>
#include <cmath>
#define M 100003
using namespace std;

double num[M];
double cu[M];
int ex[M];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out1.out","w",stdout);
    int cas,n,m,icas;
    double jilu,rating;
    scanf("%d",&cas);
    for(icas=1; icas<=cas; icas++)
    {
        int i,j,k;
        jilu = 1;
        scanf("%d%d",&n,&m);
        rating = m+1+1;
        for(i=0; i<n; i++)
        {
            scanf("%lf",&num[i]);
        }
        for(i=0; i<n; i++)
        {
            jilu *= num[i];
            cu[i] = 1-jilu;
        }
        for(i=0; i<n; i++)
        {
            double tt = 1;
            tt = (i*2 + m-n+1)*(1-cu[n-i-1]) + (i*2 + m-n+1 + m+1)*cu[n-i-1];
            rating = rating>tt?tt:rating;
        }
        printf("Case #%d: %.6lf\n",icas,rating);
    }
    return 0;
}
