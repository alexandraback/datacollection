#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
typedef long long ll;
using namespace std;

long long n;

ll area[16];

ll x10(int num) {
    ll a = 1;
    while (num) {
        a *= 10;
        num--;
    }
    return a;
}

void init() {
    ll a;
    int i, j, count(2), fix(1);
    area[0] = 1;
    area[1] = 11;
    area[2] = 30;
    for (i = 3; i < 16; i++) {
        ll &ans = area[i];
        ans = area[i-1];
        ans += x10(count) - 2;
        ans += 1;
        ans += x10(count - fix);
        fix^=1;
        count += fix;
    }
}


pair<long long, int> getCount() {
    ll x;
    int i, j, k;
    for (x = 1, i = 0; x*10 <= n; x *= 10, i++);
    return {area[i], i+1};
}


ll rev(ll x) {
    ll y(0);
    while (x) {
        y = y*10 + x%10;
        x/=10;
    }
    return y;
}

ll go(ll mod) {
    ll mod2 = mod;
    ll f = n % mod;
    int flag(0);
//    cout << f << endl;
    while (!f) {
        flag = 1;
        mod *= 10;
        f = n % mod;
    }
    if (flag && n != mod / 10) {
        n--;
        return go(mod2) + 1;
    }
    else if (n == mod / 10) {
        return -1;
    }
    else {
        ll ans;
        if (mod > mod2) {
            ans = mod/10;
            //cout << ans << endl;
            if (n%mod > mod/10) {
                mod/=10;
                n -= mod;
            }
            //cout << ans << ' ' << n << endl;
        }
        else {
         //   cout << "lalala" << endl;
            ans = n % mod;
        }
        ll nn = rev(n / mod);
        if (nn == 1) nn -= 1;
        return ans + nn - 1;
    }
}

int test(int mod) {
    ll f = n % mod;
    if (!f) return 1;
    return 0;
}

int main() {
    int t, tt;
    ll ans;
    cin >> tt;
    init();
    //for (int i = 0 ; i < 10; i++) {cout << i << ' ' << area[i] << endl; }
    xrep(t, 1, tt+1) {
        cin >> n;
        if (n < 10) {
            ans = n;
        }
        else {
            pair<long long, int> p = getCount();
            int num = p.second / 2 + (p.second % 2);
            ll temp = x10(num);
           // cout << p.first << endl;
           // cout << go(temp) << endl;
            ans = go(temp) + p.first;
            //cout << p.first << endl;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}
