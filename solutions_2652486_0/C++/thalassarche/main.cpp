#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;

vector<int> factors(int j) {
    vector<int> r(6, 0);
    for (int i = 2; i <= m; ++i) {
        while ((j % i) == 0) {
            j = j / i;
            ++r[i];
        }
    }
    return r;
}

void solve()
{
    vector<int> products(k);
    for (int i = 0; i < k; ++i) cin >> products[i];

    vector<int> needed(m + 1, 0);
    for (int i: products) {
        auto f = factors(i);
        for (int j: {3, 5}) {
            needed[j] = max(needed[j], f[j]);
        }
        int cnt = 0;
        for (int j = 2; j <= m; ++j) cnt += f[j];
        needed[4] = max(needed[4], cnt - n);
    }

    int cnt = 0;
    for (int i: {3, 4, 5}) cnt += needed[i];

    for (int i = 0; i < n - cnt; ++i) cout << 2;
    for (int i: {3, 4, 5}) {
        for (int j = 0; j < needed[i]; ++j) cout << i;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    int r;
    cin >> r >> n >> m >> k;
    cout << "Case #1: " << endl;
    while (r--) solve();
    return 0;
}
