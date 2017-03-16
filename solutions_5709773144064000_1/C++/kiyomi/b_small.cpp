#include <iostream>
#include <cstdio>

using namespace std;

const double eps = 1e-11;

int T;
double c, f, x;

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> c >> f >> x;
        double p = 2.0;
        double ans = 0.0;
        while (true) {
            double x1 = x / p;
            double x2 = (c / p) + (x / (p + f));
            if (x1 - x2 < eps) {
                ans += x / p;
                break;
            } else {
                ans += c / p;
                p += f;
            }
        }
        printf("Case #%d: %.7f\n", t, ans);
    }

    return 0;

}
