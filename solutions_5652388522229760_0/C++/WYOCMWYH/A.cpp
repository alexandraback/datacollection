#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MAXI = 1e5;

void Solve(int test_num) {
    cout << "Case #" << test_num << ": ";
    ll ans = 0;
    ll n; cin >> n;
    set<int> k;
    for (int i = 0; i < 10; ++i) k.insert(i);
    for (int i = 0; i < MAXI; ans += n, ++i) {
        ll m = ans;
        while(m) {
            k.erase(m % 10);
            m /= 10;
        }
        if (k.empty()) {
            cout << ans << "\n";
            return; 
        }
    }
    cout << "INSOMNIA\n";
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; cin >> t;
    for (int i = 1; i <= t; ++i) Solve(i);
}
