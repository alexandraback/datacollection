#include <iostream>
#include <cstdio>
using namespace std;

#define ll                      long long

#define inc(i,a,b)              for(int i=a;i<=b;++i)
#define dec(i,a,b)              for(int i=a;i>=b;--i)

ll gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    int T; cin >> T;
    
    inc(t,1,T) {
        ll p, q;
        scanf("%lld/%lld",&p,&q);
        cout << "Case #" << t << ": ";
        
        ll r = gcd(p,q);
        p = p/r, q = q/r;
        
        ll a = (1ll << 40);
        ll x = (a/q)*p;
        
        if(a%q != 0 || (x<0) || (x>a)) {
            cout << "impossible\n";
            continue;
        }
        
        dec(i,40,0) {
            ll c = (1ll << i);
            if(x >= c) {
                cout << 40-i << "\n";
                break;
            }
        }
    }
}