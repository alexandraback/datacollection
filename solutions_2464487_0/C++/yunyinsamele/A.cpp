#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>

int calc(double a,double b,double c)
{
    double ans = -1*b+sqrt(b*b-4*a*c);
    ans = ans/(2*a);
    return ans;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T,r,t;
    scanf("%d",&T);
    int cnt = 1;
    while(T--)
    {
        scanf("%d%d",&r,&t);
        printf("Case #%d: %d\n",cnt++,calc(2,(2*r-1),-1*t));
    }
    return 0;
}
