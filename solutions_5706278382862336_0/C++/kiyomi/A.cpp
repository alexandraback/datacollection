#include <cstdio>
#include <string>

using namespace std;

const double eps = 1e-11;

int T;

long long gcd(long long p, long long q) {
    while (q > 0) {
        long long t = p % q;
        p = q;
        q = t;
    }
    return p;
}

char c;
long long a, b;

void solve() {
    long long g = gcd(a, b);
    a /= g;
    b /= g;
    int cnt = 0;
    double f = a / (double) b;
    while (cnt < 40 && 0.5 - f > 0.0) {
        cnt++;
        f *= 2.0;
    }
    long long p = 2;
    //printf("%f\n", f);
    for (int i = 0; i < 40; i++) {
        double ff = 1.0 / p;
        if (f - ff >= 0.0)
            f -= ff;
        if (f == 0.0) {
            printf("%d\n", cnt + 1);
            return;
        }
        //printf("%f %f\n", f, ff);
        p *= 2;
    }
    printf("Impossible\n");
}

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%lld %c %lld", &a, &c, &b);
        printf("Case #%d: ", t);
        solve();
    }

    return 0;

}
