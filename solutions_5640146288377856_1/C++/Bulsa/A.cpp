#include <bits/stdc++.h>

#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)

using namespace std;

using ll = long long;
using pll = pair<ll,ll>;

static ll C, R, W;

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    FOR(tc,1,T+1) {
        cin >> R >> C >> W;
        ll detect = R*(C/W);
        cerr << detect << endl;
        ll res = detect + W -1;
        cout << "Case #" << tc << ": " << res << endl;
    }
}
