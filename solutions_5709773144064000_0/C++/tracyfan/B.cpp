#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    freopen("B-s.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        double c, f, x;
        scanf("%lf%lf%lf", &c, &f, &x);
        double mi = 1e9;
        double t = 0;
        for (int i = 0; i <= 100000; i++) {
            mi = min(mi, t + x / (2.0 + i * f));
            t += c / (2 + f * i);
        }
        printf("Case #%d: %.7f\n", cas, mi);
    }
}
