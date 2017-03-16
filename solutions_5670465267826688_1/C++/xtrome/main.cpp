#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr<<"‌";
#define rep(i, n) for(int i = 0; i < (n); i++)
#define F first
#define S second
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
using namespace std;

const ll N = 1e5 + 9;
ll a[N];


int main()
{_
    freopen("C-large.in.txt", "r", stdin);
    freopen("ansCF:DCFXDD", "w", stdout);
    a['1'] = 0, a['i'] = 1, a['j'] = 2, a['k'] = 3;
    ll mul[4][4] =
    {
        {a['1'], a['i'], a['j'], a['k']},
        {a['i'], 222, a['k'], -a['j']},
        {a['j'], -a['k'], 222, a['i']},
        {a['k'], a['j'], -a['i'], 222}
    };
    
    ll t;
    cin >> t;
    for (ll test = 1; test <= t; test++) {
        cout << "Case #" << test << ": ";
        ll n, l, x, neg = 0;
        cin >> l >> x;
        string ss, s;
        cin >> ss;
        
        x = min(x, 100);
        rep(i, x)
            s += ss;
        s.resize(l * x);
        
        
        n = s.size();
        rep(i, n)
        s[i] = a[s[i]];
        
        ll res = -9, go = 0;
        rep(i, n) {
            ll it = s[i];
            if (res == -9) res = it; else {
                res = mul[res][it];
                if (res == 222) neg++, res = 0;
                if (res < 0) res = -res, neg++;
            }

            if ((neg & 1) == 0) {
                if (res == a['i'] && go == 0) res = -9, go++;
                if (res == a['j'] && go == 1) res = -9, go++;
                if (i == n - 1) if (res == a['k'] && go == 2) res = -9, go++;
            }
            
        }

        cout << (go == 3 ? "YES\n" : "NO\n");
    }
}
/*

 1
 2 6
 ji

*/