#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

double A,B;
double p[10];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int cas,ta = 1;
    cin >> cas;
    while(cas--)
    {
        int i;
        double pp[10],ans;
        scanf("%lf%lf",&A,&B);

        for(i=0; i<A; i++)
          scanf("%lf",p+i);

        if(A == 1)
        {
            ans = min( B*p[0]+(2*B+1)*(1-p[0]), B+2 );
        }
        else
        if(A == 2)
        {
            ans = B + 2;
            pp[0] = p[0] * p[1];
            pp[1] = p[0] * (1 - p[1]);
            pp[2] = (1 - p[0]) * p[1];
            pp[3] = (1 - p[0]) * (1 - p[1]);

            ans = min(ans,(B-1)*pp[0]+2*B*(1-pp[0]) );
            ans = min(ans,(B+1)*(pp[0]+pp[1])+(2*B+2)*(1-pp[0]-pp[1]));
        }
        else
        {
            ans = B + 2;
            ans = min(ans,(B-2)*p[0]*p[1]*p[2]+(2*B-1)*(1-p[0]*p[1]*p[2]));
            ans = min(ans,B*p[0]*p[1]+(2*B+1)*(1-p[0]*p[1]));
        }

        printf("Case #%d: %lf\n",ta++,ans);
    }
    return 0;
}
