#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//#define DEBUG_MODE

#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLR(a,x) memset(a,(x),sizeof(a))

#ifdef DEBUG_MODE
#define DBG(X) X
#else
#define DBG(X)
#endif

inline int ___INT(){int ret; scanf("%d",&ret); return ret;}
#define INT ___INT()

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> VI;

int A,B,K;

LL dp[31][2][2][2];

int getBit(int x, int k){
    k=30-k;
    return (x>>k)&1;
}

LL F(int i, int a, int b, int k){
    if(i == 31){
        return 1;
    }
    LL& ret = dp[i][a][b][k];
    if(ret>-1)return ret;
    ret=0;

    FOR(da,2)FOR(db,2){
        if(a && da > getBit(A,i)) continue;
        if(b && db > getBit(B,i)) continue;
        int dk = da&db;
        if(k && dk > getBit(K,i)) continue;

        ret += F(i+1, a && da==getBit(A,i), b && db==getBit(B,i), k && dk==getBit(K,i));
    }

    return ret;
}


int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B_small_out.txt","w",stdout);

    int T=INT;
    REP(t,1,T){
        A=INT-1;B=INT-1;K=INT-1;
        CLR(dp,-1);
        printf("Case #%d: ",t); cout<<F(0,1,1,1)<<endl;
    }
	return 0;
}

