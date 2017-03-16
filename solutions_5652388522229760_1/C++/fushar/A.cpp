#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll N;

void solve() {
    if (N == 0) {
        cout << "INSOMNIA" << endl;
        return;
    }

    int mask = 0;
    for (ll i = N;; i += N) {
        ll num = i;
        while (num) {
            ll bit = num % 10;
            mask |= 1LL<<bit;
            num /= 10;
        }

        if (mask == (1LL<<10)-1) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cout << "Case #" << tc << ": ";
        cin >> N;
        solve();
    }
}
