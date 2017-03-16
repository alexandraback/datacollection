#include <bits\stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl
#define PATH "C:\\Users\\valenkof\\Desktop\\cpp\\"

template<typename T> inline void mx(T& x, const T& y) { if (x < y) x = y; }
template<typename T> inline void mn(T& x, const T& y) { if (y < x) x = y; }
template<typename T> inline int sz(const T& x) { return (int) x.size(); }

// SOLUTION BEGINS HERE

const int INF = 1000;

int solve(int r, int w) {
    vector<int> check(r + 1, INF);
    vector<int> solve(r + 1, INF);
    
    for (int i = 0; i < w; ++i) {
        check[i] = 0;
        solve[i] = INF;
    }
    check[w] = 1;
    solve[w] = w;
    for (int i = w + 1; i <= r; ++i) {
        for (int l = 0; l < i; ++l) {
            mn(check[i], check[l] + check[i - 1 - l] + 1);
            mn(solve[i], check[l] + solve[i - 1 - l] + 1);
        }
    }
    return solve[r];    
}

void solve() {
    int r, c, w;
    cin >> r >> c >> w;
    int x = (c + 2 * w - 2) / (2 * w - 1);
    cout << (r - 1) * x + solve(c, w) << endl;
    // cout << solve(c, w) << endl;
}

int main() {
    // freopen(PATH"in.txt", "r", stdin);
    freopen(PATH"A-large.in", "r", stdin);
    freopen(PATH"A.txt", "w", stdout);
    int t;
    cin >> t;
    forn (i, t) {
        cout << "Case #" << (i + 1) << ": ";
        solve();
    }
    return 0;
}