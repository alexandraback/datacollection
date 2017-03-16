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
typedef pair < ll, ll > ii;

ll n, m;
set < ll > s;
map < ll, ii > cut;

void solve() {
    for(ll len = 1; len < n; len++) {
        if(n % len == 0) {
            for(ll j = 1; j < (1LL << len); j += 2) {
                ll cur = j | (1LL << (len - 1)), x = 0;
                if(cur == (1LL << len) - 1)
                    continue;
                for(int k = 0; k < n / len; k++) {
                    x = (x << len) | cur;
                }
                if(s.find(x) == s.end()) {
                    s.insert(x);
                    cut[x] = {cur, len};
                }
                if(s.size() == m)
                    break;
            }
        }
        if(s.size() == m)
            break;
    }
    //printf("s.size() = %d\n", s.size());
    assert(s.size() == m);
    for(auto x : s) {
        ll piece = cut[x].first, len = cut[x].second;
        for(ll i = n - 1; i >= 0; i--) {
            printf("%lld", (x >> i) & 1);
        }
        putchar(' ');
        for(ll base = 2; base <= 10; base++) {
            ll res = 0;
            for(ll i = len - 1; i >= 0; i--) {
                res *= base;
                if((x >> i) & 1)
                    res++;
            }
            printf("%lld ", res);
        }
        puts("");
    }
}

int main () {
    
    //freopen(".txt", "r", stdin);
    freopen("small.txt", "w", stdout);
    
    int t;
    
    scanf("%d", &t);
    
    for(int it = 1; it <= t; it++) {
        printf("Case #%d:\n", it);
        scanf("%lld %lld", &n, &m);
        solve();
    }
    
    return 0;
    
}