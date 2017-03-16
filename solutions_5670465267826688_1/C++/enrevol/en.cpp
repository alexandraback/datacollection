#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

enum { _1, _i, _j, _k, _11, _ii, _jj, _kk };

int mul[8][8] = {
    { _1, _i , _j , _k  },
    { _i, _11, _k , _jj },
    { _j, _kk, _11, _i  },
    { _k, _j , _ii, _11 },
};

const int N = 10101;

int neg(int x) {
    return (x + 4) % 8;
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    for (int i = 0; i < 4; ++i)
        for (int j = 4; j < 8; ++j) {
            mul[i][j] = neg(mul[i][j - 4]);
        }
    for (int i = 4; i < 8; ++i)
        for (int j = 0; j < 8; ++j) {
            mul[i][j] = neg(mul[i - 4][j]);
        }
    int _ijk = mul[mul[_i][_j]][_k];
    int tn;
    cin >> tn;
    for (int ti = 1; ti <= tn; ++ti) {
        int n;
        long long k;
        string s;
        cin >> n >> k >> s;
        long long _n = n * k;
        int tt = 0;
        for (int i = 0; i < n; ++i) {
            tt = mul[tt][s[i] - 'i' + 1];
        }
        bool found = false;        
        int r = k % 4;
        int v = 0;
        for (int i = 0; i < r; ++i) {
            v = mul[v][tt];
        }
        if (v == _ijk) {
            long long idx_i = -1;
            long long idx_k = -1;
            string sub;
            for (int i = 0; i < 4 && i < k; ++i) {
                sub += s;
            }
            int sz = sub.size();
            for (int i = 1, x = 0; i + 2 <= _n && i <= sz; ++i) {               
                x = mul[x][sub[i - 1] - 'i' + 1];
                if (x == _i) {
                    idx_i = i;
                    break;
                }
            }
            for (int i = 1, x = 0; i + 2 <= _n && i <= sz; ++i) {
                x = mul[sub[sz - i] - 'i' + 1][x];
                if (x == _k) {
                    idx_k = _n - i + 1;
                    break;
                }
            }
            if (idx_i != -1 && idx_k != -1)
                if (idx_i + 2 <= idx_k) {
                    found = true;
                }
        }
        cout << "Case #" << ti << ": " << (found ? "YES" : "NO") << '\n';
    }
}
