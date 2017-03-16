#include<iostream>
using namespace std;

const int maxn = 100000 + 100;
double p[maxn];
double f[maxn];
int T, a, b;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    scanf("%d", &T);
    f[0] = 1;
    for (int test = 1; test <= T; test++) {
        scanf("%d%d", &a, &b);
        for (int i = 1; i <= a; i++) {
            scanf("%lf", &p[i]);
            f[i] = f[i - 1] * p[i];
        }
        double ans = b + 2;
        for (int i = 0; i <= a; i++) {
            double temp = a - i + f[i] * (b - i + 1) + (1 - f[i])*(2 * b - i + 2);
            ans = temp < ans ? temp : ans;
        }
        printf("Case #%d: %.6f\n", test, ans);
    }
    return 0;
}