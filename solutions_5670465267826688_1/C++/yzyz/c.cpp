#include <iostream>
#include <cstdlib>
#include <algorithm>
#define MAXN 10010

using namespace std;

const int I = 2;
const int J = 3;
const int K = 4;

int M[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, I, J, K},
    {0, I,-1, K,-J},
    {0, J,-K,-1, I},
    {0, K, J,-I,-1}
};

int sign(int a) {
    return a < 0 ? -1 : 1;
}

int mult(int a, int b) {
    return sign(a) * sign(b) * M[abs(a)][abs(b)];
}

int qpow(int a, long long b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mult(res,a);
        a = mult(a,a);
        b >>= 1;
    }
    return res;
}

long long n,x;
string s;

bool ok() {
    int cur = 1;
    for (int i = 0; i < n; i++) {
        s[i] = s[i] - 'i' + I;
        cur = mult(cur, s[i]);
    }
    if (qpow(cur,x) != -1) return 0;
    cur = 1;
    for (int i = 0; i < 4*n; i++) {
        cur = mult(cur, s[i % n]);
        if (cur == I) {
            cur = 1;
            for (int j = 1; j <= 4*n; j++) {
                cur = mult(cur, s[(i+j) % n]);
                if (cur == J) {
                    return i + j < n * x;
                }
            }
            return 0;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cerr << TC << endl;
        cin >> n >> x >> s;
        cerr << n << ' ' << x << endl;
        cout << "Case #" << TC << ": ";
        cout << (ok() ? "YES" : "NO") << '\n';
    }
}
