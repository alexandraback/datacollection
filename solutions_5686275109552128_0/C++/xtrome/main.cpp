#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr<<"‌";
#define rep(i, n) for(int i = 0; i < (n); i++)
#define F first
#define S second
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef long long ll;
using namespace std;

const ll N = 11;
ll t, d;
ll p[N];

int main()
{_
//    freopen("B-small-attempt0.in.txt", "r", stdin);
    freopen("jav2", "w", stdout);
    cin >> t;
    for (ll cur = 1; cur <= t; cur++) {
        cin >> d;
        rep(i, d) cin >> p[i];
        ll ans = 1e10;
        for (ll i = 1; i <= N; i++) {
            ll res = 0;
            rep(j, d)
                res += (p[j] + i - 1) / i - 1;
            res += i;
            ans = min(ans, res);
        }
        cout << "Case #" << cur << ": " << ans << endl;
    }
}