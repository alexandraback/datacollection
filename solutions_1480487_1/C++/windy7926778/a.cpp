#include <stdio.h>

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    
    int c = 0, o = 0, i = 0, n = 0, sum = 0, s[256] = { 0 }, T = 0;
    double p = 0., q = 0., mid = 0., now = 0.;

    scanf("%d", &c);
    for (o = 1; o <= c; o ++) {
        scanf("%d", &n);
        sum = 0;
        for (i = 0; i < n; i ++) {
            scanf("%d", s + i);
            sum += s[i];
        }
        p = 0.;
        q = sum + sum;
        T = 300;
        while (T --) {
            mid = (p + q) * .5;
            now = 0.;
            for (i = 0; i < n; i ++) {
                if (s[i] < mid) {
                    now += mid - s[i];
                }
            }
            if (now > sum) {
                q = mid;
            }
            else {
                p = mid;
            }
        }
        
        p = (p + q) * .5;
        //printf("### %lf\n", p);
        
        printf("Case #%d:", o);
        for (i = 0; i < n; i ++) {
            if (p < s[i]) {
                printf(" %.12lf", 0. * 100.);
            }
            else {
                printf(" %.12lf", (p - s[i]) / sum * 100.);
            }
        }
        printf("\n");
    }
    
    return 0;
}
