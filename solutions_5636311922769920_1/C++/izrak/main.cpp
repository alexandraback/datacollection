#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

vector<ll> solve(ll k, ll c) {
    vector<ll> res;
    FO(t,0,(k+c-1)/c) {
        ll ind = 0;
        FO(i,t*c,(t+1)*c) {
            ind = ind * k + (i % k);
        }
        res.push_back(ind+1);
    }
    return res;
}

int main() {
    int T; scanf("%d", &T);
    FO(z,0,T) {
        printf("Case #%d:", z+1);
        int k, c, s;
        scanf("%d%d%d", &k, &c, &s);
        vector<ll> v = solve(k,c);
        if (sz(v) > s) printf(" IMPOSSIBLE\n");
        else {
            for (ll x : v) printf(" %lld", x);
            printf("\n");
        }
    }
}

