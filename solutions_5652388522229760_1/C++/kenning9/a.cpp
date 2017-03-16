#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll lol(ll x){
    int found = 0;
    for(ll i = x; i > 0; i += x){
        //printf("%lld: %d\n", i, found);
        for(ll c = i; c > 0; c /= 10) found |= (1 << (c%10));
        if(found == (1 << 10) - 1) return i;
    }
    return -1;
}
int main(){
    int TC;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc){
        int n;
        scanf("%d", &n);
        if(n == 0) printf("Case #%d: INSOMNIA\n", tc);
        else printf("Case #%d: %lld\n", tc, lol(n));
    }
}
