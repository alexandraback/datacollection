#include <cstdio>
#include <cmath>

int main() {
    int t;
    scanf("%d", &t);
    for (int ca = 0; ca < t; ca++) {
        double c, f, x;
        scanf("%lf %lf %lf", &c, &f, &x);
        double y = 0;
        double q = 2;
        double lq = (x * f - c * f) / c;
        if (lq <= q) {
            y = x / q;
        } else {
            int steps = ceil((lq - q) / f);
            for (int i = 0; i < steps; i++) {
                y += c / (f * i + q);
            }
            y += x / (steps * f + q);
        }
        printf("Case #%d: %.7lf\n", ca + 1, y);
    }
    return 0;
}