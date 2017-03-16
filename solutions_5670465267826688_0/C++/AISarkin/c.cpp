#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

const int mul[4][4] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};
const int sign[4][4] = {{1, 1, 1, 1}, {1, -1, 1, -1}, {1, -1, -1, 1}, {1, 1, -1, -1}};

int val(char c) {
    if (c == '1') {
        return 0;
    }

    return c - 'i' + 1;
}

int main() {
    int tests;

    cin >> tests;

    for (int test_id = 1; test_id <= tests; test_id++) {
        int x, l;
        string s;

        cin >> l >> x >> s;

        int whole = 0, w_sgn = 1;

        for (int i = 0; i < l; i++) {
            w_sgn *= sign[whole][val(s[i])];
            whole = mul[whole][val(s[i])];
        }

        int ww = 0, ww_sgn = 1;

        for (int i = 0; i < x % 4; i++) {
            ww_sgn *= sign[ww][whole] * w_sgn;
            ww = mul[ww][whole];
        }

        int prefix = 0, sgn = 1;
        long long mn_pref = 1e18;

        for (int i = 0; i < l; i++) {
            sgn *= sign[prefix][val(s[i])];
            prefix = mul[prefix][val(s[i])];

            for (int j = 0; j < 10; j++) {
                int pp = 0, ss = 1;

                for (int k = 0; k < j; k++) {
                    ss *= sign[pp][whole] * w_sgn;
                    pp = mul[pp][whole];
                }

                ss *= sign[pp][prefix] * sgn;
                pp = mul[pp][prefix];

                if (pp == 1 && ss == 1) {
                    mn_pref = min(mn_pref, i + (long long)j * l);
                }
            }
        }

        int suffix = 0;
        sgn = 1;
        long long mx_suffix = -1;

        for (int i = l - 1; i >= 0; i--) {
            sgn *= sign[val(s[i])][suffix];
            suffix = mul[val(s[i])][suffix];

            for (int j = 0; j < 10; j++) {
                int pp = 0, ss = 1;

                for (int k = 0; k < j; k++) {
                    ss *= sign[pp][whole] * w_sgn;
                    pp = mul[pp][whole];
                }

                ss *= sign[suffix][pp] * sgn;
                pp = mul[suffix][pp];

                if (pp == 3 && ss == 1) {
                    mx_suffix = max(mx_suffix, (long long)x * l - (l * j + (l - i)));
                }
            }
        }

        bool good = true;
        if (mx_suffix == -1 || mn_pref == 1e18 || mx_suffix <= mn_pref) {
            good = false;
        } else if (ww != 0 || ww_sgn != -1) {
            good = false;
        }

        cout << "Case #" << test_id << ": ";

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
