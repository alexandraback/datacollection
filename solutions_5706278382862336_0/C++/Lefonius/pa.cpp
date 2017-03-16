#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while((a%=b)&&(b%=a));
    return a+b;
}

int main() {
    int T, time=0;
    scanf("%d", &T);
    while(T--) {
        ll a, b;
        scanf("%lld/%lld", &a, &b);
        ll g = gcd(a, b);
        a /= g;
        b /= g;
        ll p=1;
        int i=0;
        printf("Case #%d: ", ++time);
        for(i=0, p=1; p<b; i++, p*=2);
        if(p!=b) {
            puts("impossible");
            continue;
        }
        for(i=0; p>a; i++, p/=2);
        printf("%d\n", i);
        
    }
    return 0;
}
