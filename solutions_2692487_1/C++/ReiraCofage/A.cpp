#include <cstdio>
#include <cstring>
#include <algorithm>

#define ll long long int

using namespace std;

ll T, ini, n,C=1;
ll v[128];

int main() {

    for(scanf("%lld",&T);T--;) {
        scanf("%lld %lld",&ini,&n);
        for (ll i=0;i<n;i++) scanf("%lld",v+i);
        sort(v,v+n);
        ll best=0x7ffffffffffff000ll;
        for (ll rem=0;rem<=n;rem++) {
            ll tt = rem;
            ll j = n-1-rem;
            ll atu=ini;
            for (ll i=0;i<=j;i++) {
                x:;
                if (atu > v[i]) {
                    atu += v[i];
                    continue;
                }
                if (atu ==1 ) { //somar de 0 nao adianta
                    tt = 0x7ffffffffffff000ll;
                    break;
                }
                tt++;
                atu += (atu-1);
                goto x;
            }
            best = min(best, tt);
        }
        printf("Case #%lld: %lld\n",C++,best);
    }

    return 0;
}
