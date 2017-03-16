#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

// 1: 1, 2: i, 3: j, 4: k
int m[4][4] = {
    {1,2,3,4},
    {2,-1,4,-3},
    {3,-4,-1,2},
    {4,3,-2,-1}
};

int mul(int x, int y) {
    int sgn = 1;
    if (x<0) x = -x, sgn = -sgn;
    if (y<0) y = -y, sgn = -sgn;
    return m[x-1][y-1] * sgn;
}

i64 x;
string s;
int n;
int a(i64 idx) {
    assert(idx >= 0 && idx < (i64)s.length() * x);
    switch (s[idx % s.length()]) {
        case 'i': return 2;
        case 'j': return 3;
        case 'k': return 4;
    }
    assert(false);
}

bool solve() {
    cin >> n >> x >> s;
    n = s.length();
//     if(0)
    {
        int t = 1;
        forn(i, n) t = mul(t, a(i));
        int tt = 1;
        forn(i, x%4) tt = mul(tt, t);
        if (tt != -1) {
//             cerr << "." << endl;
            return false;
        }
    }

    i64 p1 = -1, p2 = -1;
    int t = 1;
    for (i64 i = 0; i < (i64)(min(x, 5ll) * s.length()); ++i) {
        t = mul(t, a(i));
        if (t == 2) {
            p1 = i;
            break;
        }
    }
    if (p1 == -1) {
//         cerr << ".." << endl;
        return false;
    }
    t = 1;
    for (i64 i = x * s.length() - 1; i >= (i64)(max(0ll, x-5) * s.length()); --i) {
        t = mul(a(i), t);
        if (t == 4) {
            p2 = i;
            break;
        }
    }
    if (p2 == -1) {
//         cerr << ".." << endl;
        return false;
    }
//     cout << p1 << " " << p2 << endl;
    return p1 + 1 < p2;
    return true;
}

int main() {
#ifdef HOME
//     freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    fore(i, 1, t) {
//         solve();
        cout << "Case #" << i << ": " << (solve()?"YES":"NO") << endl;
    }

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
