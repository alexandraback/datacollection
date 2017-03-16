#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<iostream>
#include<cstdlib>
#include<queue>
#include<sstream>
#include<queue>
#include<ctype.h>
#include<cstring>


using namespace std;

#define re return
#define co continue
#define pb push_back
#define br break
#define sz size


#define pf printf
#define sf scanf

int main()
{
    //freopen("sample.in","r",stdin);

    freopen("b.in","r",stdin);
    freopen("b.ans","w",stdout);
    int kase=1;
    int t;
    sf("%d",&t);
    while ( t--)
    {
        pf("Case #%d:\n",kase++);
        double d;
        sf("%lf",&d);
        int n;
        int A;
        sf("%d %d",&n,&A);

        double t0,x0;
        double t1,x1;
        sf("%lf %lf",&t0,&x0);
        if ( n==2)
            sf("%lf %lf",&t1,&x1);
        double timeCross;
        double frontSpeed = (x1-x0)/(t1-t0);
        if ( n==2)
        {
            timeCross = (d-x0)/frontSpeed;
        }
        while ( A--)
        {
            double acc;
            sf("%lf",&acc);
            double t;
            if (n==1 || timeCross <= 0 )
            {
                t =sqrt(2.0*d/acc);

            }
            else
            {
                double backCrossTime = sqrt(2.0*d/acc);
                if (  backCrossTime<timeCross)
                {
                    double b,c,a;
                    a = 0.5*acc;
                    b = -frontSpeed;
                    c = -x0;
                    t = (-b + sqrt(b*b-4.0*a*c) )/(2.0*a);
                    double meetx = 0.5*acc*t*t;
                    t = t + (d-meetx)/frontSpeed;
                }
                else
                {
                    t = sqrt(d*2/acc);
                }
            }
            pf("%.9lf\n",t);
        }

    }
    return 0;
}
