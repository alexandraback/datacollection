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

int64 _abs(int64 x) {
    if (x < 0)
         return -x;
    return x;
}

void solve() {
    int64 x, y;
    cin >> x >> y;
    int64 n = 1;
    while (n * (n + 1) / 2 < _abs(x) + _abs(y))
        ++n;
    while ((n * (n + 1) / 2 + x + y) % 2 != 0)
        ++n;
    string ans;
    for (int64 i = n; i > 0; --i) {
        if (_abs(x - i) + _abs(y) <= i * (i - 1) / 2) {
             x -= i;
             ans.pb('E');
             continue;
        }
        if (_abs(x + i) + _abs(y) <= i * (i - 1) / 2) {
             x += i;
             ans.pb('W');
             continue;
        }
        if (_abs(x) + _abs(y - i) <= i * (i - 1) / 2) {
             y -= i;
             ans.pb('N');
             continue;
        }
        if (_abs(x) + _abs(y + i) <= i * (i - 1) / 2) {
             y += i;
             ans.pb('S');
             continue;
        }
    }
    reverse(all(ans));
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
