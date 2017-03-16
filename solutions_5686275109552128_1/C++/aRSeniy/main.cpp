#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

void precalc() {

}

int fun(const map<int, int>& mp, int k) {
    int res = 0;
    for (const auto& i : mp) {
        int p = (i.first / k) + ((i.first % k) != 0) - 1;
        res += p * i.second;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    int mx = 0;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        ++mp[t];
        mx = max(mx, t);
    }

    int best = 999999999;
    for (int i = 1; i <= mx; ++i) {
        best = min(best, i + fun(mp, i));
    }
    cout << best << endl;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    precalc();

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
