#include <iostream>
#include <algorithm>

using namespace std;

int m[5][5], l, x, dp[5][5][5];
string s;

void init() {
    // i = 2, j = 3, k = 4
    m[1][1] = 1;
    m[1][2] = 2;
    m[1][3] = 3;
    m[1][4] = 4;
    m[2][1] = 2;
    m[2][2] = -1;
    m[2][3] = 4;
    m[2][4] = -3;
    m[3][1] = 3;
    m[3][2] = -4;
    m[3][3] = -1;
    m[3][4] = 2;
    m[4][1] = 4;
    m[4][2] = 3;
    m[4][3] = -2;
    m[4][4] = -1;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
}

int main() {
    freopen("c_small.in", "r", stdin);
    freopen("c_small.out", "w", stdout);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        init();
        cin >> l >> x >> s;
        int a = 1;
        int b;
        int c = 1;
        int sign = 1;
        bool ijk = false;
        int location = 0;
        for (int i = 0; i < min(x, 99) * l; i++) {
            // cout << a << " " << c << " " << sign << endl;
            b = s[(i % l)] - 'i' + 2;
            int r = m[a][b];
            if (r == 0) {
                break;
            }
            if (r < 0) {
                r *= -1;
                sign *= -1;
            }
            if (r == c + 1) {
                a = 1;
                c += 1;
            } else {
                a = r;
            }
            if (c == 4) {
                ijk = true;
                location = i+1;
                break;
            }
        }
        bool yes = false;
        if (ijk) {
            b = 1;
            int sign2 = 1;
            for (int i = 0; i < l; i++) {
                int r = m[b][s[i] - 'i' + 2];
                if (r < 0) {
                    r *= -1;
                    sign2 *= -1;
                }
                b = r;
            }
            a = 1;
            sign = 1;
            int step = 0;
            for (int i = 0; i < 10; i++) {
                int r = m[a][b];
                if (r < 0) {
                    r *= -1;
                    sign *= -1;
                }
                a = r;
                sign *= sign2;
                if (a == 1 && sign == -1) {
                    step = i + 1;
                    break;
                }
            }
            if (step && x % step == 0 && (x / step) % 2) {
                yes = true;
            }
        }
        if (yes) {
            cout << "Case #" << t << ": YES" << endl;
        } else {
            cout << "Case #" << t << ": NO" << endl;
        }
    }
}
