#include <iostream>
#include <cmath>
#define rep(i, s, t) for (int i = s; i <= t; i++)

using namespace std;

double c[3001][3001];

int main() {
    rep (i, 0, 3000) {
        c[i][0] = 1;
        c[i][i] = 1;
    }
    rep (i, 1, 3000) {
        rep (j, 1, i) {
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
    int T;
    cin >> T;
    rep (ca, 1, T) {
        int n, x, y;
        cin >> n >> x >> y;
        int cnt = 0;
        for (cnt = 0; cnt * (2 * cnt - 1) <= n; cnt++);
        cnt--;
        int r = n - cnt * (2 * cnt - 1);
        int req = (abs(x) + abs(y)) / 2 + 1;
        cout << "Case #" << ca << ": ";
        if (req <= cnt) {
            cout << "1.0\n";
            continue;
        }
        if (req > cnt + 1 || x == 0) {
            cout << "0.0\n";
            continue;
        }
        req = y + 1;
        cnt++;
        //cout << cnt << " " << r << " " << req << "\n";
        if (r >= req + 2 * cnt - 2) {
            cout << "1.0\n";
            continue;
        }
        double ans = 0;
        rep (i, req, r) {
            ans += c[r][i];
        }
        while (r > 0) {
            ans /= 2.0;
            r--;
        }
        cout << ans << "\n";
    }
    return 0;
}
