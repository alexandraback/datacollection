#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl

template<typename T> inline int sz(const T& x) { return (int) x.size(); }
template<typename T> inline void mn(T& x, const T& y) { if (y < x) x = y; }
template<typename T> inline void mx(T& x, const T& y) { if (x < y) x = y; }

typedef long long ll;

const double PI = 2 * acos(0);

// <---------------- actual solution begins here ---------------->

void solve() {
    int d;
    cin >> d;
    vector<int> p(d);
    forn (i, d) {
        cin >> p[i];
    }
    int ans = 1000;
    for (int x = 1; x <= 1000; ++x) {
        int current = 0;
        forn (i, d) {
            current += (p[i] + x - 1) / x - 1;
        }
        ans = min(ans, current + x);
    }
    cout << ans << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    freopen("B-large.in.txt", "r", stdin);
    freopen("B.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}