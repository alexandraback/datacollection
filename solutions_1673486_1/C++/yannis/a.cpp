#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

long double chance[100010], corr[100010], wrong[100010], firstwrong[100010], scorr[100010], sfw[100010];
long double backspace;

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, a, b, x, i, t;
    long double ans;

    scanf("%d", &T);

    for (t=1; t<=T; ++t) {
        scanf("%d %d", &a, &b);
        x = b-a;

        scorr[0] = 1.;
        for (i=1; i<=a; i++) {
            scanf("%Lf", &corr[i]);
            scorr[i] = scorr[i-1] * corr[i];
            wrong[i] = 1 - corr[i];
        }

        for (i=1; i<=a; i++) {
            firstwrong[i] = scorr[i-1] * wrong[i];
        }

        for (i=1; i<=a; ++i ) {
            sfw[i] = sfw[i-1] + firstwrong[i];
        }

        // for (i=1; i<=a+1; ++i ) backspace[i] = 0;

        ans = 20001010;
        for (i=0; i<=a; ++i) {
            backspace = sfw[a-i] * (2*i + x + 1 + b + 1);
            /* printf("-> %lf %lf\n", backspace, (1-sfw[a-i]) * (i*2 + x + 1)); */
            backspace += (1-sfw[a-i]) * (i*2 + x + 1);
            /* printf("%lf\n", backspace); */
            if ( backspace < ans ) ans = backspace;
        }

        if ( 2 + b < ans ) ans = 2 + b;
        printf("Case #%d: %Lf\n", t, ans);
    }

    return 0;
}
