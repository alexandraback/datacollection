#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

double f[3333][3333];

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int k = (abs(x) + abs(y)) / 2;
//    cout << k << endl;
    if (n < y + k *(2*k - 1) + 1) {
        cout << 0.0;
        return;
    }
    if (x == 0) {
        cout << 1.0;
        return;
    }
    int rem = n - k*(2*k - 1);
//    cout << rem << endl;
    if (rem >= y + 1 + 2*k) {
        cout << 1.0;
        return;
    }

    int a = y;
    int b = (rem - 1) - y;
//    cout << a << " " << b << endl;
    double res = 0;
    for (int i = 0; i <= b; i++)
        res += f[a][i];
//    cout << res << endl;
    res *= 0.5;
    printf("%.9lf", res);
//    double a, b;
//    if (rem <= 2*k)
//        b = rem + 1;
//    else
//        b = 4*k - rem + 1;
//    a = min(rem, 2*k) - y;
//    printf("%.9lf", a / b);
}

int main() {

    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);

    f[0][0] = 1;
    f[0][1] = f[1][0] = 0.5;
    for (int i = 0; i <= 3000; i++)
        for (int j = 0; j <= 3000; j++) {
            if (i + j <= 1) continue;
            if (i > 0)
                f[i][j] += f[i - 1][j];
            if (j > 0)
                f[i][j] += f[i][j - 1];
            f[i][j] *= 0.5;
        }

//    for (int i = 0; i <= 10; i++) {
//        for (int j = 0 ; j <= 10 ; j++)
//            printf("%.6lf ", f[i][j]);
//        cout << endl;
//    }

    int T, cnt = 0;
    cin >> T;
    while (T > 0) {
        cout << "Case #" << ++cnt << ": ";
        solve();
        cout << endl;
        --T;
    }
}
