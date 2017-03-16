#include <stdio.h>
#include <stdlib.h>
#define eps 1e-7

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long double c, f, x;
    long double rate, ans;
    int T, t;

    scanf("%d", &T);
    for (t=1; t<=T; t++) {
        rate = 2;
        ans = 0;

        scanf("%Lf %Lf %Lf", &c, &f, &x);
        while (c/rate + x/(f+rate) < x/rate) {
            ans += c/rate;
            rate += f;
        }
        ans += x/rate;

        printf("Case #%d: %Lf\n", t, ans);
    }

    return 0;
}
