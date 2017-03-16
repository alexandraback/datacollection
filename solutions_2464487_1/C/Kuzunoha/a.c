#include<stdio.h>
#include<math.h>

double f(double r, long long N)
{
    double n = (double)N;
    //double PI = acos(-1.0);
    return ((2.0*n*(n+1.0)) + (((2.0*r)-3.0)*n));
}

int main()
{
    int T,tc,i;
    long long awl,akh,tgh;
    double r,t;
    scanf("%d",&T);
    for(tc=1;tc<=T;tc++)
    {
        scanf("%lf%lf",&r,&t);
        awl = 0LL;
        akh = 1000000000000000000LL;
        i = 100;
        while(i--)
        {
            tgh = (awl+akh)/2LL;
            if(f(r,tgh)>t) akh = tgh;
            else awl = tgh;
        }
        printf("Case #%d: %lld\n",tc,tgh);
    }
    return 0;
}
