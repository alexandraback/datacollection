
#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <cstdio>
#include <cstdint>
#include <cmath>

typedef long long ll;

using namespace std;

void solve(int)
{
    ll k, c, s;
    cin >> k >> c >> s;

    ll lenght = 1;
    for (ll i = 0; i < c; ++i) lenght *= k;

    vector<ll> v;
    ll check = 0;
    while (check < k) {
        ll x = 0;
        for (ll i = 0; i < c && check < k; ++i) {
            x = x * k + check;
            ++check;
        }
        v.push_back(x);
    }

    if (v.size() > s) cout << "IMPOSSIBLE" << endl;
    else {
        for (ll i: v) cout << i + 1 << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve(i);
    }
}
