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
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    int sum = 0;
    for (int i = 0; i <= n; ++i) {
        int count = s[i] - '0';
        if (count > 0) {
            ans = max(ans, i - sum);
        }
        sum += count;
    }
    cout << ans << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    freopen("A-large.in.txt", "r", stdin);
    freopen("A.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}