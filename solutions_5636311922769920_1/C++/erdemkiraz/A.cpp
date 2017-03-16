#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "cstring"
#include "string"
#include "vector"
#include "cassert"
#include "queue"
#include "cstdio"
#include "cstdlib"
#include "ctime"
#include "cmath"
#include "bitset"

using namespace std;

typedef long long ll;
typedef pair < int, int > ii;

ll k, c, s;
ll pw[300];

void solve() {
    scanf("%lld %lld %lld", &k, &c, &s);
    c = min(c, k);
    ll need = k - c + 1;
    if(s < need) {
        puts("IMPOSSIBLE");
        return;
    }
    pw[0] = 1;
    for(int i = 1; i <= 200; i++)
        pw[i] = pw[i - 1] * k;
    ll x = c;
    for(ll i = 1; i < c; i++) {
        x += pw[c - i] * (i - 1);
    }
    for(ll i = x; i <= x + need - 1; i++)
        printf("%lld ", i);
    puts("");
}

int main () {
    
    freopen("big.txt", "w", stdout);
    
    int t;
    
    scanf("%d", &t);
    
    for(int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    
    return 0;

}