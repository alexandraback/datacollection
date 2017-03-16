#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std; 

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    vector<string> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    vector<int> dp((1 << n), 0);
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                 set<string> a_set;
                 set<string> b_set;
                 for (int k = 0; k < n; ++k) {
                     if (k == j) continue;
                     if (i & (1 << k)) {
                         a_set.insert(a[k]);
                         b_set.insert(b[k]);
                     }
                 }
                 if (a_set.find(a[j]) != a_set.end() && b_set.find(b[j]) != b_set.end()) {
                     dp[i] = max(dp[i], dp[i ^ (1 << j)] + 1);
                 }
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int t;
    cin >> t;
    for (int test = 1; test <= t; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
