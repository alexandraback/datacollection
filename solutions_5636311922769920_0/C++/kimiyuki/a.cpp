#include <iostream>
#include <vector>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
typedef long long ll;
using namespace std;
template <class T> ostream & operator << (ostream & out, vector<T> const & a) { bool i = false; for (T const & it : a) { if (i) out << ' '; else i = true; out << it; } return out; }
void solve() {
    int k, c, s; cin >> k >> c >> s;
    vector<ll> ans;
    int cnt = 0;
    repeat (s_,s) {
        if (cnt >= k) break;
        ll p = 0;
        repeat (i,c) {
            p *= k;
            p += min(k-1, cnt ++);
        }
        ans.push_back(p + 1);
    }
    if (cnt < k) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans << endl;
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
