#include "../../lib/include.h"

#define ONE 1
#define I 2
#define J 3
#define K 4

int mul_table[4][4] = {
    {ONE,I,J,K},
    {I,-ONE,K,-J},
    {J,-K,-ONE,I},
    {K,J,-I,-ONE}
};

int mul(int a, int b) {
    int sign = (a < 0 ? -1 : 1) * (b < 0 ? -1 : 1);
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;

    return mul_table[a-1][b-1] * sign;
}

int parse(char c) {
    if (c == 'i') return I;
    if (c == 'j') return J;
    if (c == 'k') return K;
    assert(false);
}

int mypow(int a, int k) {
    int res = ONE;
    for (int i = 0; i < k; i++) {
        res = mul(res, a);
    }
    // int res = ONE;
    // while (k) {
    //     if (k & 1) {
    //         res = mul(res, a);
    //     }
    //     a = mul(a, a);
    //     k >>= 1;
    // }
    return res;
}

struct solver {

    solver() {
    }

    void solve(bool process, istream &cin, ostream &cout) {
        int len;
        ll rep;
        cin >> len >> rep;
        string s;
        cin >> s;

        LOGIC;

        vector<int> arr(len),
                    prefix(len),
                    suffix(len);

        int x = ONE;
        for (int i = 0; i < len; i++) {
            arr[i] = parse(s[i]);
            x = mul(x, arr[i]);
        }

        int **rng = new int*[len];
        for (int i = 0; i < len; i++) {
            rng[i] = new int[len];
            rng[i][i] = arr[i];
            for (int j = i+1; j < len; j++) {
                rng[i][j] = mul(rng[i][j-1], arr[j]);
            }
        }

        suffix[len - 1] = arr[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            suffix[i] = mul(arr[i], suffix[i+1]);
        }

        prefix[0] = arr[0];
        for (int i = 1; i < len; i++) {
            prefix[i] = mul(prefix[i-1], arr[i]);
        }

        bool possible = false;

        vii is, ks;
        for (int xcnt = 0; xcnt < 4; xcnt++) {
            for (int i = 0; i < len; i++) {
                if (mul(mypow(x, xcnt), prefix[i]) == I) {
                    is.push_back(ii(xcnt, i));
                }
            }
        }

        for (int xcnt = 0; xcnt < 4; xcnt++) {
            for (int k = 0; k < len; k++) {
                if (mul(suffix[k], mypow(x, xcnt)) == K) {
                    ks.push_back(ii(xcnt, k));
                }
            }
        }

        for (int i = 0; i < size(is) && !possible; i++) {
            for (int k = 0; k < size(ks) && !possible; k++) {

                // cout << is[i].first << " " << is[i].second << ", " << ks[k].first << " " << ks[k].second << endl;

                if (is[i].first + ks[k].first + 1 > rep) {
                    continue;
                } else if (is[i].first + ks[k].first + 1 == rep) {
                    if (is[i].second + 1 <= ks[k].second - 1 && rng[is[i].second + 1][ks[k].second - 1] == J) {
                        possible = true;
                        break;
                    }
                } else {
                    int between = ((rep - ks[k].first - 1) - is[i].first - 1) % 4;
                    int l = is[i].second == len - 1 ? ONE : suffix[is[i].second + 1];
                    int r = ks[k].second == 0 ? ONE : prefix[ks[k].second - 1];
                    // cout << "XX " << between << " " << l << " " << r << endl;
                    if (mul(l, mul(mypow(x, between), r)) == J) {
                        possible = true;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < len; i++) {
            delete[] rng[i];
        }

        delete[] rng;

        OUTPUT;

        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
};

// see https://github.com/SuprDewd/GoogleCodeJamRunner
#include "../../lib/gcj.h"
