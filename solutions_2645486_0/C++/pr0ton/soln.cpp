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

int E, R, N;
int v[10007];

int dp[111][111];
int solve(int pos, int energy) {
    if (pos == N) return 0;
    int &res = dp[pos][energy];
    if (~res) return res;
    res = 0;
    for (int pick=0; pick <= energy; pick++) {
        res = max(res, v[pos] * pick + solve(pos+1, min(E, energy - pick + R)));
    }
    return res;
}

int main() {
    int runs; s(runs);
    for (int T=1; T <= runs; T++) {
        s(E); s(R); s(N);
        for (int i=0; i < N; i++) s(v[i]);
        fill(dp, -1);
        printf("Case #%d: %lld\n", T, (ll)solve(0, E));
    }
}
