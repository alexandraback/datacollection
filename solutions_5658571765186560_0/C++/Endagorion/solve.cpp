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

void answer(int t, bool yes) {
    printf("Case #%d: %s\n", t, yes ? "RICHARD" : "GABRIEL");
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;

    int T;
    cin >> T;
    for1(t, T) {
        int x, r, c;
        cin >> x >> r >> c;
        if (r > c) swap(r, c);
        if (x >= 7 || x > c || (x + 1) / 2 > r || (r * c) % x) {
            answer(t, true);
        } else if (x <= 3) {
            answer(t, false);
        } else if (x == 4) {
            answer(t, r == 2);
        } else if (x == 5) {
            answer(t, false);
        } else if (x == 6) {
            answer(t, r == 3);
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
