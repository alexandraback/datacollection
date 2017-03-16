#include <cstdio>
#include <cstdlib>

typedef long double LD;

int main() {
    int t;
    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        printf("Case #%d: ", cs);
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        x = abs(x);
        int c = x + y;
        for (int i = 0; i < c; i += 2)
            n -= (i << 1) + 1;
        int m = (c << 1) + 1;
        if (n < 0)
            puts("0.0");
        else if (n > m)
            puts("1.0");
        else if (!x)
            if (n == m)
                puts("1.0");
            else
                puts("0.0");
        else
            if (n - c > y)
                puts("1.0");
            else {
                LD d = 1, ans = 0;
                for (int i = 1; i <= n; ++i)
                    d *= i * 0.5;
                for (int i = 1; i <= y; ++i)
                    d /= i;
                for (int i = 1; i <= n - y; ++i)
                    d /= i;
                for (int i = y + 1; i <= n; ++i) {
                    d *= LD(n - i + 1) / i;
                    ans += d;
                }
                printf("%.8lf\n", double(ans));
            }
    }
    return 0;
}
