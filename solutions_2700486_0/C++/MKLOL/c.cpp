#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <string>

int x;
int N,X,Y,ind,T;
double a;

double calc1()
{
    double put=1;
    for(int i=1;i<=2*abs(Y) + 2 - a; ++i)
        put*=2;
    return 1/put;
}
double calc2()
{
    double put = 1;
    for(int i=1;i<=abs(a-2*abs(Y));++i)
        put*=2;
    return 1 - 1/put;
}
int main()
{
freopen("c.in","r",stdin);
freopen("c.out","w",stdout);
scanf("%d",&T);
    while(T--)
    {++ind;
    scanf("%d%d%d",&N,&X,&Y);
        for(int i=1;i<=N+5;++i)
        {
            if((i+1)*(2*i+1) <= N)
                x=i;
        }

    if(abs(X)==0 && abs(Y) == 2*x+2)
    {
         printf("Case #%d: %lf\n",ind,(double)0.0);
         continue;
    }
    if(abs(X) + abs(Y) <= 2 * x)
        {
            printf("Case #%d: %lf\n",ind,(double)1.0);
            continue;
        }
        if(abs(X) + abs(Y) >= 2 * x + 4)
        {
            printf("Case #%d: %lf\n",ind,(double)0.0);
            continue;
        }
    a=N-(x+1) * (2*x+1);
    if(a<=Y)
        {
            printf("Case #%d: %lf\n",ind,0);
            continue;
        }
    if(a>=abs(Y)+1 && a<= 2*abs(Y))
        {
            printf("Case #%d: %lf\n",ind,(double) calc1());
            continue;
        }
    if(a>=2*abs(Y)+1 && a <= x + 2 + abs(Y))
        {
            printf("Case #%d: %f\n",ind,(double) calc2());
            continue;
        }
        printf("Case #%d: 1.0\n",ind);
    }
}
