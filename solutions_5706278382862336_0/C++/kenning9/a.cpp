#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int TC;
ll p, q; char c;
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main(){
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc){
        scanf("%lld/%lld", &p,  &q);
        ll x = gcd(q, p);
        q /= x; p /= x;
        //printf("%lld  %lld\n", p,  q);
        ll ans = 0, pq = 0;
        for(pq = 0; pq < 41 && q > (1ll << pq); ++pq){
            //printf("pq is %lld\n", pq);
        }
        if((1ll<<pq) != q){
            printf("Case #%d: impossible\n", tc);
            continue;
        }
        for(ans = 40; ans > 0 && p < (1ll << ans); ans--);
        printf("Case #%d: %lld\n",tc, pq - ans);
    }
}
        
