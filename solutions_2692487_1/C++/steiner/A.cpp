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
    int64 x, n;
    cin >> x >> n;
    vector<int64> a(n);
    for (int64 i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    if (x == 1) {
        cout << n << endl;
        return;
    }
    int64 ans = n;
    for (int64 i = 0; i < n; ++i) {
        int64 res = n - i - 1;
        int64 y = x;
        for (int64 j = 0; j <= i; ++j) {
            while (y <= a[j]) {
                 y *= 2;
                 y -= 1;
                 ++res;        
            }
            y += a[j];
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
