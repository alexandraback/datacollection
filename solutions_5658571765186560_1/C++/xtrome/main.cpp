#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr<<"‌";
#define rep(i, n) for(int i = 0; i < (n); i++)
#define F first
#define S second
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef long long ll;
using namespace std;

const ll N = 50 + 9;

int main()
{_
    freopen("D-large.in.txt", "r", stdin);
    freopen("Lans", "w", stdout);
    
    ll t;
    cin >> t;
    for (ll test = 1; test <= t; test++) {
        ll x, n, m;
        cin >> x >> n >> m;
        if (n > m)
            swap(n, m);
        cout << "Case #" << test << ": ";
        
        if (x > m || n < (x - 1) / 2 + 1 || (n * m) % x || x >= m + 3 || x >= 9) {
            cout << "RICHARD\n";
            continue;
        }
        
        ll ok[N][N];
        rep(i, N) rep(j, N) ok[i][j] = 1;

        for (ll l = 0; l <= x - m; l++)
            for (ll r = x - m - l; r <= x - m - l; r++)
                for (ll i = l + 1; i <= n - r; i++)
                    if (l + r <= x - m) {
                        if (((i - 1) * m - l) % x == 0 && ((n - i) * m - r) % x == 0)
                            ok[l][r] = 0;
                    }
        
        
        ll tc = 0;
        for (ll l = 0; l <= x - m; l++)
            for (ll r = x - m - l; r <= x - m - l; r++)
                if (l + r <= x - m) {
                    tc = max(tc, ok[l][r]);
        }
        
        rep(i, N) rep(j, N) ok[i][j] = 1;
        
        for (ll l = 0; l <= x - n; l++)
            for (ll r = x - n - l; r <= x - n - l; r++)
                for (ll i = l + 1; i <= m - r; i++)
                    if (l + r <= x - n && l + r + 1 > n) {
                        if (((i - 1) * n - l) % x == 0 && ((m - i) * n - r) % x == 0)
                            ok[l][r] = 0;
                    }
        
        for (ll l = 0; l <= x - n; l++)
            for (ll r = x - n - l; r <= x - n - l; r++)
                if (l + r <= x - n && l + r + 1 > n) {
                    tc = max(tc, ok[l][r]);
                }
        
        
        if (tc) {
            cout << "RICHARD\n";
            continue;
        }
        
        cout << "GABRIEL\n";
    }
}