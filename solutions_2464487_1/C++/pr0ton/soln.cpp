/* come at me bro */

#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<sstream>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>



#define oo 					(int)13e7
#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define fill(a,v) 				memset(a, v, sizeof a)
#define ull 					unsigned long long
#define ll 						long long
#define bitcount 			__builtin_popcount
#define all(x) 				x.begin(), x.end()
#define pb( z ) 				push_back( z )
#define gcd					__gcd
using namespace std;
ll r, t;

ll f(ll r, ll n) {
    n--;
    return 2*r*(n+1) + 2*n*(n+1) + n + 1;
}

int main() {
    int runs; s(runs);
    for (int T=1; T <= runs; T++) {
        cin>>r>>t;
        
        ll lo = 0, hi = 1;
        
        while (f(r, hi) <= t) hi *= 2;
        
        while (lo + 1 < hi) {
            ll mid = (lo + hi)/2;
            if (f(r, mid) <= t) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        
        printf("Case #%d: %lld\n", T, lo); //lo + 1);
        
    }
}
