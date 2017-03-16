#include <cstdio>

int a[300];
int S, N;

bool check(double p) {
    double Y = 0.0;
    for (int i = 0; i < N; ++i) {
        if (p > a[i]) {
            Y += (p - a[i]) / S;
        }
    }
    return Y <= 1.0;
}

int main() {
    int T; scanf("%d", &T);

    for (int tt = 1; tt <= T; ++tt) {
        scanf("%d", &N);
        S = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &a[i]);
            S += a[i];
        }

        double l = 0.0, r = S;

        for (int itr = 0; itr <= 100; ++itr) {
            double p = (l + r) / 2.0;

            if (check(p)) {
                l = p;
            } else {
                r = p;
            }
        }

        printf("Case #%d:", tt);
        for (int i = 0; i < N; ++i) {
            printf(" %lf", (l < a[i]) ? 0 : 100.0 * (l - a[i]) / S);
        }
        printf("\n");
    }
    return 0;
}
