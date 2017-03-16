#include <iostream>
#include <array>
#include <algorithm>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
typedef long long ll;
using namespace std;
void solve() {
    ll n; cin >> n;
    if (n == 0) {
        cout << "INSOMNIA" << endl;
    } else {
        array<bool,10> used = {};
        int i = 1;
        while (true) {
            for (ll t = i * n; t; t /= 10) used[t % 10] = true;
            if (not count(used.begin(), used.end(), false)) break;
            ++ i;
        }
        cout << i * n << endl;
    }
}
int main() {
    int t; cin >> t;
    repeat (i,t) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}
