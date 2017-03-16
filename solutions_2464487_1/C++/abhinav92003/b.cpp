#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
double MOD(double num)
{
    if(num>=0)
        return num;
    return -1*num;
}
using namespace std;
double root(double num)
{
    if(num==1)
        return 1;
    double est=num/2,nextest;
   // printf("est*est is %lf num is %lf diff is %lf\n",est*est,num,MOD(est*est-num));
    while(MOD(est*est-num)>=0.01)
    {
     //    printf("old est %lf\n",est);
        est=est-((est*est-num)/(2*(double)num));
      //  printf("new est %lf\n",est);
    }
    return est;
}
int main()
{
    /*while(1)
    {
        double a;
        long long b;
        scanf(" %lf",&a);
     //   b=(long long)a;
        printf("%lf\n",root(a));
    }*/
    int t=1,T;
    int r,paint;
    scanf(" %d",&T);
    while(t<=T)
    {
        scanf(" %d %d",&r,&paint);
        long long now=(r+1)*(r+1)-r*r,tot=0,sq=r+2;
        while(paint>0)
        {
            paint-=now;
            if(paint>=0)
                tot++;
            now=sq*sq;
            now*=-1;
            now+=((sq+1)*(sq+1));
            sq+=2;
        }
        printf("Case #%d: %lld\n",t,tot);
        t++;
    }
	return 0;
}
