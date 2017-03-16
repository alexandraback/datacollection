#include <cstdio>
#include <cassert>
#include <algorithm>

int main() {
    int nt;
    assert(scanf("%d", &nt) == 1);
    for (int tt = 1; tt <= nt; tt++) {
        double c, f, x;
        assert(scanf("%lf%lf%lf", &c, &f, &x) == 3);
        double y = 1e23;
        double ct = 0;
        double rate = 2.0;
        for (int it = 0; it <= 100000; it++) {
            y = std::min(y, ct + (x / rate));
            ct += c / rate;
            rate += f;
        }
        printf("Case #%d: %.7lf\n", tt, y);
    }
    return 0;
}
