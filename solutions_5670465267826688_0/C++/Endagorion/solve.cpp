#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int table[4][4] = {{0, 1, 2, 3}, {1, 4, 3, 6}, {2, 7, 4, 1}, {3, 2, 5, 4}};

int mul(int x, int y) {
    int t = (x ^ y) & 4;
    return table[x & 3][y & 3] ^ t;
}

void answer(int t, bool yes) {
    printf("Case #%d: %s\n", t, yes ? "YES" : "NO");
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;

    int T;
    cin >> T;
    for1(t, T) {
        i64 l, x;
        cin >> l >> x;
        string s;
        cin >> s;
        int p = 0;
        forn(i, s.size()) p = mul(p, s[i] - 'h');
        int pp = 0;
        forn(i, x % 4) pp = mul(pp, p);
        if (pp != mul(1, mul(2, 3))) {
            answer(t, false);
            continue;
        }
        i64 lft = 1e18, rgt = 1e18;
        for (int p = 0, i = 0; i < min(x, 4LL) * l; p = mul(p, s[i % l] - 'h'), ++i) {
            if (p == 1) {lft = i; break; }
        }
        for (int p = 0, i = 0; i < min(x, 4LL) * l; p = mul(s[l - i % l - 1] - 'h', p), ++i) {
            if (p == 3) {rgt = i; break; }
        }
        answer(t, lft + rgt <= l * x);
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
