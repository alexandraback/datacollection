#include <cstdio>
#include <algorithm>
using namespace std;
long long c[21][21];
double solve() {
    int n, m = -1, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int p = (x + y) / 2;
    p = (2 * p + 1) * (p + 1);
    if (n >= p) return 1.0f;
    else {
        int t = (x + y) / 2 - 1;
        t = (2 * t + 1) * (t + 1);
        if (n <= t) return 0.0f;
        n -= t;
    }
    if (x == 0) return 0.0f;
    long long a = 0, b = 0;
    for (int i = 0 ; i <= min(n, x + y) ; ++i) {
        if (n - i <= x + y) {
            a += c[n][i];
            if (i >= y + 1) b += c[n][i];
        }
    }
    if (a == 0) a = 1;
    return double(b) / a;
}
int main() {
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    for (int i = 0 ; i <= 20 ; ++i) for (int j = 0 ; j <= 20 ; ++j) c[i][j] = 0;
    for (int i = 0 ; i <= 20 ; ++i) {
        c[i][0] = 1;
        for (int j = 1 ; j <= 20 ; ++j)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    scanf("%d" ,&t);
    for (int i = 1 ; i <= t ; ++i)
        printf("Case #%d: %lf\n", i, solve());
    fclose(stdin);
    fclose(stdout);
    return 0;
}
