#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include <locale>
#include <iterator>
#include <valarray>
#include <complex>

using namespace std;

main()
{
    freopen("a.in","r",stdin);freopen("a.out","w",stdout);
    double a,b,c,d,e,f,g,h,x,y,z;
    double ar[300],ar1[300],po[300];
    long p,q,r,s,t;
    scanf("%ld",&p);
    for(t=1;t<=p;t++)
    {
        scanf("%ld",&q);
        a=0;
        for(s=0;s<q;s++)
        {
            scanf("%lf",&ar[s]);
            a+=ar[s];
            ar1[s]=ar[s];
        }
        sort(ar,ar+q);
        printf("Case #%ld:",t);
        for(r=0;r<q;r++)
        {
            b=1;
            c=0;
            d=(b+c)/2.0;
            while(c<d)
            {
                //printf("%lf %lf %lf\n",b,c,d);
                e=0;
                f=ar1[r]+(a*d);
                //printf("%lf\n",f);
                g=1-d;
                h=0;
                for(s=0;s<q;s++)
                {
                    if(ar[s]==ar1[r])h++;
                    if((ar[s]!=ar1[r] || ( ar[s]==ar1[r] && h>1)) && ar[s]+a*(g)>=f)
                    {
                        g-=(f-ar[s])/a;
                    }
                    else if((ar[s]!=ar1[r] || ( ar[s]==ar1[r] && h>1))) g=-1;
                }
                //printf("%lf %lf %lf\n",g,b,f);
                if(g>=0)
                {
                    e++;
                    c=d;
                }
                else b=d;
                d=(b+c)/2;
                if(b==d)break;
            }
            printf(" %lf",d*100);
        }
        printf("\n");
    }
}
