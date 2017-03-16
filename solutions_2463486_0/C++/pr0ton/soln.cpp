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

char a[255], b[255];
vector<ll> sol;
void gen(int i, int j) {
    if (i > j) {
        ll v;
        sscanf(a, "%lld", &v);
        ll v2 = v * v;
        sprintf(b, "%lld", v2);
        for (int x=0, y = strlen(b) -1 ; x <= y; x++, y--) {
            if (b[x] != b[y]) return;
        }
        // cout << v2 << " = " << v << "*" << v << endl;
        sol.pb(v2);
    } else {
        for (char c=i == 0 ? '1' : '0'; c <= '9'; c++) {
            a[i] = a[j] = c;
            gen(i+1, j-1);
        }
    }
}

int main() {
    for (int i=1; i <= 10; i++) {
        fill(a, 0); fill(b, 0);
        gen(0, i-1);
    }
    sort(all(sol));
    int runs; s(runs);
    for (int T=1; T <= runs; T++) {
        ll a, b;
        sl(a); sl(b);
        ll res = (upper_bound(all(sol), b) - upper_bound(all(sol), a-1));
        
        printf("Case #%d: %lld\n", T, res);
    }
}
