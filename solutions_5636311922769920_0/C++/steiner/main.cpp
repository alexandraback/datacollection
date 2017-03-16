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
    int64 k, c, s;
    cin >> k >> c >> s;
    int64 answer = (k + c - 1) / c;
    if (answer > s) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (int64 i = 0; i < answer; ++i) {
        vector<int64> digits;
        for (int64 j = 0; j < c; ++j) {
            digits.pb((i * c + j) % k);
        }
        int64 deg = 1;
        int64 result = 0;
        for (int64 j = 0; j < c; ++j) {
            result += digits[j] * deg;
            deg *= k;
        }
        cout << result + 1 << " ";
    }
    cout << endl;
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
