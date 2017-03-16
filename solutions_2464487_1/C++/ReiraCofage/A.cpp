#include <cstdio>
#include <cstring>
#include <cmath>

#define SIZE 1000000000000000000ll
#define ll unsigned long long int

using namespace std;

ll C=1, T, r, tt;

ll conta(ll p) {
    ll me = 2llu*p*(p+r+1llu)-3llu*p;
    return me;
}

int main() {

    for(scanf("%llu",&T);T--;) {
        scanf("%llu %llu",&r,&tt);
        ll resp = -1, ini = 1llu, fim = 707106782ll;
        while (ini <= fim) {
            ll p = (ini+fim)/2llu;
            ll f = conta(p);
            if (f <= tt) {
                resp = p;
                ini = p+1;
            } else fim = p-1;
        }
        printf("Case #%llu: %llu\n",C++,resp);
    }

    return 0;
}
