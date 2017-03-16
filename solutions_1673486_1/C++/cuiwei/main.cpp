#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main() {
    static double p[100001], ans, ep, wa, best;
    int tc, a, b, i, c = 0;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &a, &b);
        for (i = 0; i < a; i++)
            scanf("%lf", p + i);
        ans = a + b + 1;
        for (ep = wa = 1, i = 0; i < a; i++) {
            ans = min(ans, ep * (((a - i) << 1) + b - a + 1)+(1 - ep)*(((a - i) << 1) + b - a + b + 2));
            ep *= p[i];
        }
        best = min(ep * (b - a + 1)+(1 - ep)*(b - a + 2 + b), 2.0 + b);
        printf("Case #%d: %.6lf\n", ++c, min(ans, best));
    }
}