#include <bits/stdc++.h>
using namespace std;

int TC, N;

int main() {
    freopen("C6.in", "r", stdin);
    freopen("C6.out", "w", stdout);
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d", &N);
        int d1, h1, m1, d2, h2, m2;
        if (N == 1) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            d1 = d2 = a;
            h1 = h2 = 1;
            m1 = c;
            m2 = c+1;
        }
        else scanf("%d%d%d%d%d%d", &d1, &h1, &m1, &d2, &h2, &m2);
        int follow;
        if ((long long)(360 - d1) * m1 > (long long)(360 - d2) * m2) follow = 1;
        else if ((long long)(360 - d1) * m1 == (long long)(360 - d2) * m2) {
            printf("Case #%d: 0\n", tc);
            continue;
        }
        else follow = 2;
        if (follow == 1) {
            if ((long long)(360 - d1) * m1 >= (long long)(720 - d2) * m2) printf("Case #%d: 1\n", tc);
            else printf("Case #%d: 0\n", tc);
        }
        else if (follow == 2) {
            if ((long long)(360 - d2) * m2 >= (long long)(720 - d1) * m1) printf("Case #%d: 1\n", tc);
            else printf("Case #%d: 0\n", tc);
        }
    }
}
