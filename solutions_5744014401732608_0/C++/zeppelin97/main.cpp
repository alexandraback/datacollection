#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nmax = 100005;
const long double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const long double eps = 1e-6;
int b[55][55];
ll dp[55];
ll n;
ll ct(ll i, ll j){
    if (i == 1 && j == n) return 1;
    if (i == 1 && j == i + 1) return 1e18;
    if(i == n - 1 && j == n) return 1e18;
    ll cnt1 = 0;
    ll cnt2 = dp[j];
    for(int k = 1; k < i; ++k){
        if (b[k][i]) cnt1++;
    }
    if (i == 1) cnt1++;
    return cnt1 * cnt2;
}
int main(){
    ios_base::sync_with_stdio(0);
    freopen("B-small-attempt4.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int q = 1; q <= t; ++q){
        cin >> n;
        ll m;
        cin >> m;
        memset(b, 0, sizeof (b));
        memset(dp, 0, sizeof(dp));
        dp[n] = 1;
        dp[n - 1] = 1;
        for(int i = n - 2; i >= 1; --i){
            dp[i] = 1;
            for(int j = i + 1; j < n; ++j) dp[i] += dp[j];
        }
        if (m > dp[1]){
            cout << "Case #" << q << ": IMPOSSIBLE\n";
            continue;
        }
        cout << "Case #" << q << ": POSSIBLE\n";
        for(int i = 1; i < n; ++i){
            for(int j = i + 1; j <= n; ++j) b[i][j] = 1;
        }
        int cnt = 1;
        for(int i = 1; i < n; ++i){
            for(int j = i + 2; j <= n; ++j){
                ll tmp = ct(i, j);
                //cout << i << ' ' << j << ' ' << m << ' '<< tmp << ' ' << dp[1] << endl;
                if (dp[1] >= m + tmp){
                    for(int k = i; k >= 1; --k){
                        dp[k] -= dp[j];
                    }
                    //cout << i << ' ' << j << ' '<<  dp[1] << ' ' << m << ' '<< tmp << endl;
                    b[i][j] = 0;
                }
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j) cout << b[i][j];
            cout << '\n';
        }
    }
    return 0;
}
