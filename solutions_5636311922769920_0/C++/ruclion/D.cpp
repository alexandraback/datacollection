#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

ll k, c, s;
ll calcu(ll k, ll c) {
    ll ans = 1;
    for(int i = 1; i <= c; i++) {
        ans *= k;
    }
    return ans;
}

void solve() {
    ll tim = (k + c - 1) / c;
    if(s < tim) {
        printf(" IMPOSSIBLE\n");
    }
    else {
        for(int i = 0; i < tim; i++) {
            ll ans = 0;
            for(int j = 0; j < c; j++) {
                ll tmp = j + (ll)i * c;
                ans = ans * (ll)k + min(tmp, k - 1);
            }

            //ans = ans + i * c * calcu(k, c - 1);
            printf(" %lld", ans + 1);
        }
        printf("\n");
    }
}

int main() {
    freopen("D-small-attempt1.in", "r", stdin);
    freopen("Dout.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d:", i);
        scanf("%lld%lld%lld", &k, &c, &s);
        solve();
    }
    return 0;
}
