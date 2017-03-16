#include <cstdio>
#include <algorithm>
using namespace std;

#define N 1005

int n, s;
int a[N];

int main() {
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        double s = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            s += a[i];
        }
        double l = 0, r = s * 2;
        for (int ci = 0; ci < 100; ++ci) {
            double mid = (l + r) * 0.5, sum = 0;
            for (int i = 0; i < n; ++i)
                sum += max(0.0, (mid - a[i]) / s);
            if (sum > 1)
                r = mid;
            else
                l = mid;
        }
        double p = (l + r) * 0.5;
        //printf(" %.4f\n", p);
        printf("Case #%d:", ++cas);
        for (int i = 0; i < n; ++i)
            printf(" %.10f", max(0.0, (p - a[i]) / s * 100.0));
        puts("");
    }
    return 0;
}
