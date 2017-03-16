#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EPS 1e-9

double prop[100010];
double ans;

int main()
{
    double t;
    int a, b, i, aa, nn, j;
    scanf("%d",&nn);
    prop[0] = 1;
    for ( aa = 1; aa <= nn; ++aa ) {
        scanf("%d %d",&a,&b);
        ans = b+2;
        for ( i = 1; i <= a; ++i ) {
            scanf("%lf",&prop[i]);
            prop[i] *= prop[i-1];
        }
        // backspace count
        for ( i = 0, j = a; i <= a; i++, j-- ) {
            t = prop[j] * (b-a+1+i+i); // correct
            t += (1-prop[j]) * (i+i+b-a+2+b);
            if ( t < ans ) ans = t;
        }
        ans += EPS;
        printf("Case #%d: %.6lf\n",aa,ans);
    }
    return 0;
}

