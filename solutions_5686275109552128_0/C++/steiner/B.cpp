#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
 
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
 
typedef long long int64;
 
using namespace std;

void solve() {
    int D;
    cin >> D;
    vector<int> P(D);
    for (int i = 0; i < D; ++i) cin >> P[i];
    int ans = 1000;
    for (int d = 1; d <= 1000; ++d) {
        int res = d;
        for (int i = 0; i < D; ++i) {
            if (P[i] <= d) {
                continue;
            }
            res += (P[i] - 1) / d;
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
