#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    const int MAXF = 101;
    const int MOD = (int)1e+9 + 7;
    cerr << MOD << endl;
    ull fact[MAXF];
    fact[0] = 1;
    for (int i = 1; i < MAXF; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n, m;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            for (size_t j = 0; j < s[i].size(); ++j) {
                s[i][j] -= 'a';
            }
        }
        bool ok;

        int equals[26];
        memset(equals, 0, sizeof(equals));
        m = 0;
        for (int i = 0; i < n; ++i) {
            ok = true;
            for (size_t j = 1; j < s[i].size(); ++j)
                if (s[i][j] != s[i][0]) {
                    ok = false;
                    break;
                }
            if (ok) {
                equals[(int)s[i][0]] += 1;
            } else {
                s[m++] = s[i];
            }
        }
        n = m;

        set <int> sets[26];
        int pref[26];
        int suff[26];
        for (int i = 0; i < 26; ++i) {
            pref[i] = suff[i] = -1;
        }
        ok = true;
        for (int i = 0; i < n && ok; ++i) {
            //cerr << "\t" << i << endl;
            for (size_t l = 0, r = 0; l < s[i].size() && ok; l = r) {
                while (r < s[i].size() && s[i][l] == s[i][r]) ++r;
                //cerr << "\t\t" << l + 1 << " " << r << endl;
                int c = s[i][l];
                if (sets[c].size()) {
                    ok = false;
                }
                if (l != 0 && r != s[i].size()) {
                    sets[c].insert(i);
                } else {
                    if ((pref[c] != -1 && l == 0) || (suff[c] != -1 && r == s[i].size())) {
                        ok = false;
                    }
                    (l == 0? pref[c] : suff[c]) = i;
                }
            }
        }
        for (int i = 0; i < 26 && ok; ++i)
            if (equals[i] && sets[i].size()) {
                ok = false;
            }
        int k = 0;
        for (int i = 0; i < 26 && ok; ++i)
            if (suff[i] == -1 && pref[i] == -1 && equals[i]) {
                ++k;
            }
        cerr << ok << endl;
        for (int i = 0; i < 26 && ok; ++i)
            if (suff[i] == -1 && pref[i] != -1) {
                ++k;
                int x = i;
                while (pref[x] != -1) {
                    int &y = pref[x];
                    x = s[y][s[y].size() - 1];
                    y = -1;
                    suff[x] = -1;
                }
            }
        for (int i = 0; i < 26 && ok; ++i) {
            ok &= suff[i] == -1 && pref[i] == -1;
        }
        ull ans = fact[k];
        for (int i = 0; i < 26; ++i) {
            (ans *= fact[equals[i]]) %= MOD;
        }
        cout << (ok? ans : 0) << endl;
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
