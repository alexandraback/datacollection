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


int k, n;
const int mxk = 44, mxn = 20;
int keyc[mxk];

int ktype[mxn];
vector<int> keys[mxn];
int dp[1<<mxn];
int backp[1<<mxn];


bool solve(int mask) {
    if (mask == (1<<n) - 1) {
        return 1;
    }
    int &res = dp[mask];
    if (~res) return res;
    int &bp = backp[mask];
    res = 0;
    bp = -1;
    int ckeyc[mxk] = {0};
    for (int i=0; i < mxk; i++) ckeyc[i] = keyc[i];
    for (int i=0; i < n; i++) { 
        if (mask & 1<<i) {
            for (int j=0; j < (int)keys[i].size(); j++) {
                ckeyc[ keys[i][j] ] += 1;
            }
            ckeyc[ ktype[i] ] -= 1;
        }
    }
    
    for (int i=0; i < n; i++)
        if (!(mask & 1<<i) && ckeyc[ ktype[i] ] > 0 && solve(mask | 1<<i)) {
            bp = i;
            res=1;
            break;
        }
    return res;
}

int main() {
    int runs; s(runs);
    for (int t=1; t <= runs; t++) {
        // clear stuff
        fill(keyc, 0); fill(dp, -1);
        for (int i=0; i < mxn; i++) {
            keys[i].clear();
        }
        // read ip
        s(k); s(n);
        for (int i=0; i < k; i++) {
            int f; s(f); keyc[f]++;
        }
        
        for (int i=0; i < n; i++) {
            s(ktype[i]);
            int cnt; s(cnt);
            keys[i].resize(cnt);
            for (int j=0; j < cnt; j++)
                s(keys[i][j]);
        }
        
        printf("Case #%d:", t);
        if (solve(0)) {
            int m = 0;
            for (int i=0; i < n; i++) {
                printf(" %d", backp[m] + 1);
                m |= 1<<backp[m];
            }
            puts("");
        } else {
            puts(" IMPOSSIBLE");
        }
    }
}
