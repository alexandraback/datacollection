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

struct solver {

    solver() {
    }

    void solve(bool process, istream &cin, ostream &cout) {
        int len, rep;
        cin >> len >> rep;
        string s;
        cin >> s;

        LOGIC;

        vector<int> arr(len * rep);
        for (int at = 0, j = 0; j < rep; j++) {
            for (int i = 0; i < len; i++) {
                arr[at++] = parse(s[i]);
            }
        }

        vector<int> suffix(len * rep);
        suffix[len * rep - 1] = arr[len * rep - 1];
        for (int i = len * rep - 2; i >= 0; i--) {
            suffix[i] = mul(arr[i], suffix[i+1]);
        }

        bool possible = false;
        int a = ONE;
        for (int i = 0; i < len * rep - 2; i++) {
            a = mul(a, arr[i]);
            int b = ONE;
            for (int j = i + 1; j < len * rep - 1; j++) {
                b = mul(b, arr[j]);
                int c = suffix[j+1];
                if (a == I && b == J && c == K) {
                    possible = true;
                }
            }
        }

        OUTPUT;

        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
};

// see https://github.com/SuprDewd/GoogleCodeJamRunner
#include "../../lib/gcj.h"
