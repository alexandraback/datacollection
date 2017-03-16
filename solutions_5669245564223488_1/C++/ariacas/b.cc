#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
const int mod = 1000000007;

int main() {
    vl fac(10000000, 1);
    for (int i = 2; i < fac.size(); ++i)
        fac[i] = fac[i-1] * i % mod;
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        printf("Case #%d: ", test);
        int n;
        cin >> n;
        vector<string> v(n);
        vi was(26), wasl(26), wasr(26), ones(26);
        bool fail = 0;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            v[i] += s[0];
            for (int j = 1; j < s.size(); ++j) if (s[j] != s[j-1])
                v[i] += s[j];
            for (int j = 1; j + 1 < v[i].size(); ++j) {
                int pos = v[i][j] - 'a';
                ++was[pos];
                if (was[pos] > 1) {
                    fail = 1;
                }
            }
            if (v[i].size() > 1) {
                int pos = v[i][0] - 'a';
                if (wasl[pos]) {
                    fail = 1;
                }
                wasl[pos]++;
                pos = v[i][v[i].size() - 1] - 'a';
                if (wasr[pos]) {
                    fail = 1;
                }
                wasr[pos]++;
            } else {
                int pos = v[i][0] - 'a';
                ++ones[pos];
            }
        }
        for (int i = 0; i < n; ++i) {
            int pos = v[i][0] - 'a';
            if (was[pos]) {
                fail = 1;
                break;
            }
            pos = v[i][v[i].size() - 1] - 'a';
            if (was[pos]) {
                fail = 1;
                break;
            }
        }
        if (fail) {
            printf("0\n");
            continue;
        }
        ll res = 1;
        for (int i = 0; i < 26; ++i) {
            res = res * fac[ones[i]] % mod;
        }
        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            if (ones[i] && !wasr[i] && !wasl[i]) {
                ++cnt;
            }
        }
        for (int i = 0; i < n; ++i) {
            int pos = v[i][0] - 'a';
            if (v[i].size() != 1 && !wasr[pos]) {
                ++cnt;
            }
        }
        if (cnt == 0) {
            cout << 0 << endl;
        } else {
            cout << res * fac[cnt] % mod << endl;
        }
    }
    return 0;
}
