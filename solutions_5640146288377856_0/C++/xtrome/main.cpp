#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr<<"‌";
#define rep(i, n) for(int i = 0; i < (n); i++)
#define F first
#define S second
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
using namespace std;

const ll N = 1e5 + 9;
ll t;

int main()
{_
    freopen("A-small-attempt0.in.txt", "r", stdin);
    freopen("Ae", "w", stdout);
    
    cin >> t;
    rep(test, t) {
        ll r, c, w;
        cin >> r >> c >> w;
        ll ans = w - 1 + (c + w - 1) / w;
        cout << "Case #" << test + 1 << ": " << ans << endl;
    }
}