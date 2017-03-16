#include <algorithm>
#include <cstdio>

using namespace std;

int N;
int s[256];
int a[256];
double r[256];
int S;

double g(double pts, int v) {
    int prev = 0;
    int pc = 0;

    for (int i = 0; i < N; ++i) {
        if (a[i] == v && (i == 0 || a[i] != a[i - 1])) continue;
        if (pc * (a[i] - prev) > pts) break;
        pts -= pc * (a[i] - prev);
        prev = a[i];
        ++pc;
    }

    return prev + pts / pc;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);
        S = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d", s + i);
            a[i] = s[i];
            S += s[i];
        }
        sort(a, a + N);
        for (int i = 0; i < N; ++i) {
            double lo = 0.0, hi = 1.0;

            for (int j = 40; j > 0; --j) {
                double mid = 0.5 * (lo + hi);
                if (g((1.0 - mid) * S, s[i]) > s[i] + mid * S) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            r[i] = hi;
        }

        printf("Case #%d:", t);
        for (int i = 0; i < N; ++i) printf(" %.6f", 100 * r[i]);
        printf("\n");
    }

    return 0;
}
