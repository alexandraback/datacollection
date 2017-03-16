#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr<<"‌";
#define rep(i, n) for(int i = 0; i < (n); i++)
#define F first
#define S second
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef long long ll;
using namespace std;

const ll N = 1e5 + 9;

int main()
{_
    freopen("A-large.in.txt", "r", stdin);
    freopen("ans", "w", stdout);
    
    ll t;
    cin >> t;
    for (ll test = 1; test <= t; test++) {
        ll sx, cnt = 0, ans = 0;
        cin >> sx;
        for (ll i = 0; i <= sx; i++) {
            char st;
            cin >> st;
            st -= '0';
            ans += max(0, i - cnt);
            cnt += max(0, i - cnt);
            cnt += st;
        }
        cout << "Case #" << test << ": " << ans << endl;
    }
}