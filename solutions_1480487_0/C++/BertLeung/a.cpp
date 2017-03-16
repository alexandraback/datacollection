#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

double list[210];
int mark[210];

#define eps 1e-8

int main()
{
    double sum, t, tt, sum2, tmp, m;
    int aa, nn, n, i, c, j;
    scanf("%d",&nn);
    for ( aa = 1; aa <= nn; ++aa ) {
        scanf("%d",&n);
        sum = 0;
        for ( i = 0; i < n; ++i ) {
            scanf("%lf",&list[i]);
            sum += list[i];
            mark[i] = 0;
        }
        c = n;
        while ( 1 ) {
            m = 0;
            for ( i = 0; i < n; i++ ) {
                if (mark[i]) continue;
                if ( list[i] > m ) {
                    m = list[i];
                    j = i;
                }
            }
            sum2 = sum;
            for ( i = 0; i < n; i++) {
                if (mark[i] || i == j ) continue;
                sum2 -= (m-list[i]);
            }
            if ( sum2 >= 0 ) break;
            mark[j] = 1;
            c--;
        }
        sum2 = 0;
        for ( i = 0; i < n; i++ ) {
            if (mark[i]) continue;
            sum2 += list[i];
        }
        tt = (sum+sum2)/c;
        printf("Case #%d:",aa);
        for ( i = 0; i < n; i++ ) {
            if (mark[i])
                t = 0;
            else
                t = (tt-list[i])/sum*100;
            printf(" %.6lf",t+eps);
        }
        printf("\n");
    }
    return 0;
}

