#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

#define MaxN 210

int n;
int T;
int s[MaxN];
int sum;
int ret[MaxN];

bool Prezivi( int id, double x )
{
    double t = s[id] + sum*x;
    double preostalo = 1.0 - x;

    for (int i = 0; i < n; ++i)
        if ( i != id ) {

            if ( s[i] > t ) continue;

            double p = ( t - s[i] ) / double(sum);

            if ( p > preostalo ) return true;
            preostalo -= p;
        }

    return false;
}

int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);

    scanf("%d",&T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d",&n);

        sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d",&s[i]);
            sum += s[i];
        }


        printf("Case #%d:",t);
        for (int i = 0; i < n; ++i) {

            double left = 0.0;
            double right = 1.0;
            while ( right - left > (1e-9) ) {
                double mid = ( right + left ) / 2.0;

                if ( !Prezivi( i, mid ) ) left = mid;
                else                     right = mid;
            }

            printf(" %lf",left*100);

        }
        printf("\n");
    }

    return 0;
}
