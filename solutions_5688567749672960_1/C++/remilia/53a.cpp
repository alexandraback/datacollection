#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
int t;
ll n;

int bitcount(ll n) {
    int cnt = 0;
    while (n) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

int w;
ll s;

ll res(ll x) {
    ll ans = 0;
    while (x) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

ll solve(ll n) {
    ll tmp = 1;
    for (int i = 0; i < w / 2; i++) {
        tmp *= 10;
    }
    ll sb = n / tmp;
    ll sss = res(sb);
    ll ans = sss + n % tmp;
    if (res(s + sss) == s + sss) ans--;
    tmp *= 10;
    sb = n / tmp;
    ans = min(ans, sss + n % tmp);
    return ans;
}

int main() {
    int cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        w = bitcount(n);
        if (w == 1) {
            printf("Case #%d: %lld\n", ++cas, n);
            continue;
        }
        s = 10;
        ll ans = 10;
        for (int i = 1; i < w - 1; i++) {
            ll tmp = 1;
            for (int j = 0; j <= i / 2; j++)
                tmp *= 10;
            s *= 10;
            ans += (s - 1) / tmp + (s - 1) % tmp + 1;
        }
        ans = min(ans, n);
        if (n == s) {
            printf("Case #%d: %lld\n", ++cas, ans);
            continue;
        }
        if (n % 10 == 0) ans += solve(n - 1) + 1;
        else ans += solve(n);
        ans = min(ans, n);
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}
