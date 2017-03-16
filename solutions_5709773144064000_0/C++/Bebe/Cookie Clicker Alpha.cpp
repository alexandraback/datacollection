#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    freopen("B-small-attempt0.in.","r",stdin);
    freopen("Bans","w",stdout);
    int t, T;
    double C, F, X, time, t1, t2, cookie;
    scanf("%d",&T);
    for ( t = 0 ; t < T ; t ++ )
    {
        time = 0;
        cookie = 2;
        scanf("%lf %lf %lf",&C,&F,&X);
        while (1)
        {
            t1 = X/cookie;
            t2 = (C/cookie)+(X/(cookie+F));
            if ( t1 <= t2 )
            {
                break;
            }
            else
            {
                time += C/cookie;
                cookie += F;
            }
        }
        time += X/cookie;

        printf("Case #%d: %.7lf\n",t+1,time);
    }

    return 0;
}
