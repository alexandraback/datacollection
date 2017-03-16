#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

double chance, corr[100010], wrong[100010], scorr[100010], sfw[100010];
double backspace[1000010];

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    int T, a, b, x, i, t, j, k;
    double ans;
    int firstwrong;

    scanf("%d", &T);

    for (t=1; t<=T; ++t) {
        scanf("%d %d", &a, &b);
        x = b-a;

        scorr[0] = 1.;
        for (i=1; i<=a; i++) {
            scanf("%lf", &corr[i]);
            scorr[i] = scorr[i-1] * corr[i];
            wrong[i] = 1 - corr[i];
        }

        for (i=0; i<=a; i++) backspace[i] = 0;
        // for (i=1; i<=a; i++) {
        //     firstwrong[i] = scorr[i-1] * wrong[i];
        // }

        for (i=0; i<(1<<a); ++i) {
            firstwrong = -1; chance = 1;
            for (j=1; j<=a; j++) {
                if ( ( 1<<(j-1) ) & i ) {
                    if ( firstwrong == -1 ) firstwrong = j;
                    chance = chance * wrong[j];
                    /* printf("X"); */
                }
                else {
                    chance = chance * corr[j];
                    /* printf("O"); */
                }
            }
            for (k=0; k<=a; k++) {
                if ( a-k >= firstwrong && firstwrong != -1 ) {
                    backspace[k] += chance * (2*k + x + 1 + b + 1);
                }
                else {
                    backspace[k] += chance * (2*k + x + 1);
                }
            }
        }
        ans = 20000010;
        for (i=0; i<=a; i++) {
            
            if ( backspace[i] < ans ) ans = backspace[i];
            /* printf("%lf\n", backspace[i]); */
        }

        if ( 2 + b < ans ) ans = 2 + b;
        printf("Case #%d: %lf\n", t, ans);
    }

    return 0;
}
