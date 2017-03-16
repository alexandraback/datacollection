#include <iostream>
#include <stdio.h>
#include <algorithm>
#define s(n) scanf("%lld", &n)
#define lli long long int

using namespace std;

int main() {
    lli t, j, p, s, k;
    lli ans[10000];
    lli num = 0;
    s(t);
    lli i, a, b, c;
    lli jp[200], ps[200], sj[200];
    for (i = 1; i <= t; i++) {
        s(j);
        s(p);
        s(s);
        s(k);
        num = 0;
        for (a = 0; a < 200; a++) {
            jp[a] = 0;
            ps[a] = 0;
            sj[a] = 0;
        }

        for (a = 1; a <= j; a++) {
            for (b = 1; b <= p; b++) {
                for (c = 1; c <= s; c++) {
                    if (jp[11 * a + b] < k && ps[11 * b + c] < k && sj[11 * c + a] < k) {
                        jp[11 * a + b]++;
                        ps[11 * b + c]++;
                        sj[11 * c + a]++;
                        ans[num * 3] = a;
                        ans[num * 3 + 1] = b;
                        ans[num * 3 + 2] = c;
                        num++;
                    }
                }
            }
        }
        printf("Case #%lld: %lld\n", i, num);
        for (a = 0; a < num; a++) {
            printf("%lld %lld %lld\n", ans[a * 3], ans[a * 3 + 1], ans[a * 3 + 2]);
        }
    }
    return 0;
}
