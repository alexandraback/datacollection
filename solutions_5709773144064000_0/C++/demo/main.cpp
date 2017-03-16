#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int t;
    double buycost,add,x;
    scanf("%d",&t);
    int cs=0;
    while(t--)
    {
        scanf("%lf%lf%lf",&buycost,&add,&x);
        double rate=2;
        double own=0;
        double tt=0;
        while(own<x)
        {
            double t=0;
            if(x<=buycost)
            {
                tt+=x/2;
                break;
            }
            if(own<buycost) t=(buycost-own)/rate;
            tt+=t;
            double t1=(x-buycost)/rate;
            double t2=x/(rate+add);
            if(t1<t2)
            {
                tt+=t1;
                break;
            }
            else
            {
           //     tt+=t2;
                own=0;
                rate+=add;
            }
       //     printf("%.6f\n",tt);
        }
        printf("Case #%d: ",++cs);
        printf("%.7f\n",tt);
    }
    return 0;
}













