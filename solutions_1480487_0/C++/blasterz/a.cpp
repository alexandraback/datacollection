#include <cstdio>
#include <cstring>
#define eps 1e-7
#include <cmath>

int a[300];
int n;
int T;

double w[300];
int isok(double X, double p) {
    int i;
    double s = 0.0;
    for (i = 1; i<=n; ++i) {
        w[i] = (p - (double) (a[i])) / X;
        s += w[i];
    }
    if (fabs(s - 1.0) < eps || s > 1.0)
        return 1;
    return 0;
}


void solve(int test) {
    double X = 0;
    int i;
    for (i = 1;i <= n; ++i)
        X += a[i];
    double cnt, I;
    /*for (I = 100.0, cnt = 64.0; fabs (cnt) > eps; cnt /= 2.0)
        if (I - cnt > 0) {
            if (isok(X, I - cnt))
                I -= cnt;
        }
    */
    I = 0.0;
    for (i = 1; i <= n; ++i)
        I += (double)a[i];
    I /= (double) n;
    I *= 2.0;
    printf ("Case #%d:", test);
    for (i = 1; i <= n; ++i) {
        w[i] = (I - (double) a[i]) / X;
        printf (" %.7lf", fabs(100.0 * w[i]));
    }
    printf("\n");
}

int main() {
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    scanf ("%d\n", &T);
    for (int test = 1; test <= T; ++test) {
        scanf ("%d ", &n);
        int i;
        for (i = 1; i <= n; ++i)
            scanf ("%d ", &a[i]);
        solve (test);
    }

}
