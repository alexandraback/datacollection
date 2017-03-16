#include <stdint.h>
#include <stdio.h>
#include <set>

using namespace std;

int32_t main() {
    int32_t cas;
    scanf("%d", &cas);
    for (int32_t ic = 1; ic <= cas; ic ++) {
        double c, f, x;
        scanf("%lf%lf%lf", &c, &f, &x);
        double t = 0.0;
        double best = x / 2.0;
        int32_t i = 0;
        while (t < best) {
            double current = t + x / (2.0 + i * f);
            if (current < best) {
                best = current;
            }
            t += c / (2.0 + i * f);
            i++;
        }
        printf("Case #%d: %.7lf\n", ic, best);
    }
    return 0;
}
