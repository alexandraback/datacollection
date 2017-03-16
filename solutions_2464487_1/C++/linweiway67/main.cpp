#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,ta=1;
    double r,t,delta,ans;
    long long n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf",&r,&t);
        delta = (2*r-1)*(2*r-1)+8*t;
        double d = sqrt(delta);
        ans = (-(2*r-1)+sqrt(delta)) / 4;
        n = (long long)ans;
        long long i;
        for(i=-1; i<=2; i++)
            if(2*(n+i)*(n+i)+(2*r-1)*(n+i) > t)
               break;
        printf("Case #%d: %I64d\n",ta++,n+i-1);
    }
    return 0;
}
