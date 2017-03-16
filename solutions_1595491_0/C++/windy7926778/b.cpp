#include <stdio.h>

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int c = 0, o = 0, i = 0, n = 0, s = 0, p = 0, x = 0, tol = 0, ans = 0;
    scanf("%d", &c);
    for (o = 1; o <= c; o ++) {
        ans = tol = 0;
        scanf("%d%d%d", &n, &s, &p);
        for (i = 0; i < n; i ++) {
            scanf("%d", &x);
            if (p >= 1 && p + p - 1 + p - 1 <= x || p == 0 && p * 3 <= x) {
                ans ++;
            }
            else if (p >= 2 && p + p - 2 + p - 2 <= x) {
                tol ++;
            }
        }
        if (tol < s) {
            ans += tol;
        }
        else {
            ans += s;
        }
        printf("Case #%d: %d\n", o, ans);
    }
    return 0;
}
