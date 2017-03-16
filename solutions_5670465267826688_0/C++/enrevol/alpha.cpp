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

int a[N], prefix[N], suffix[N];

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
    int tn;
    cin >> tn;
    for (int ti = 1; ti <= tn; ++ti) {
        memset(a, 0, sizeof(a));
        memset(prefix, 0, sizeof(prefix));
        memset(suffix, 0, sizeof(suffix));
        int n, k;
        string s;
        cin >> n >> k >> s;
        string t = s;
        for (int i = 1; i < k; ++i) {
            t += s;
        }
        n = t.size();
        assert(n == int(s.size() * k));
        for (int i = 1; i <= n; ++i) {
            a[i] = t[i - 1] - 'i' + 1;
        }
        for (int i = 1; i <= n; ++i) {
            prefix[i] = mul[prefix[i - 1]][a[i]];
        }
        for (int i = n; i >= 1; --i) {
            suffix[i] = mul[a[i]][suffix[i + 1]];
        }
        bool found = false;
        for (int i = 1; i + 2 <= n; ++i) {
            if (prefix[i] == _i) {
                int v = _1;
                for (int j = i + 1; j < n; ++j) {
                    v = mul[v][a[j]];
                    if (suffix[j + 1] == _k && v == _j) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
        }
        cout << "Case #" << ti << ": " << (found ? "YES" : "NO") << '\n';
    }
}
