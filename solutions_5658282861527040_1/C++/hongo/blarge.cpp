#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long int


int main(){
    int t;
    ll a, b, k;

    scanf("%d", &t);
    for(int nt = 0; nt < t; ++nt){
        scanf("%lld %lld %lld", &a, &b, &k);
        ll res = 0LL;
        //totos os pares tal que a < k;
        ll x = min(k, a);
        res += x * b;
        //printf("%lld\n", res);

        //pares tal que b < k
        x = a-min(k, a);
        ll y = min(b, k);
        res += x * y;

        //pares tal que a >= k && b >= k
        for(ll i = k; i < a; ++i){
            for(ll j = k; j < b; ++j){
                if((i&j)<k) res += 1LL;
            }
        }

        printf("Case #%d: %lld\n", nt+1, res);


    }

    return 0;
}
