#include <bits/stdc++.h>

typedef long long ll;

constexpr ll inf = std::numeric_limits<ll>::max() / 4;

using namespace std;

void solve(int)
{
    ll b, m;
    cin >> b >> m;

    if (m > (1ll << (b - 2))) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << "POSSIBLE" << endl;

        vector<vector<char>> slide(b, vector<char>(b, false));
        for (int i = 0; i < b - 1; ++i) {
            for (int j = 0; j < i; ++j) {
                slide[j][i] = true;
            }
        }

        if (m == (1ll << (b - 2))) slide[0].back() = true;
        for (ll i = 1; i < b - 1; ++i) {
            if (m & (1ll << (i - 1)) || m == (1ll << (b - 2))) slide[i].back() = true;
        }

        for (auto& v: slide) {
            for (bool i: v) cout << i;
            cout << endl;
        }
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
