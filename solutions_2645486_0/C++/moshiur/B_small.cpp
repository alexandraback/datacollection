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

int E,R,N,V[100];
int dp[100][100];

int F(int e, int k){
    if(k == N) return 0;
    int& ret=dp[e][k];
    if(ret>-1)return ret;

    ret = 0;
    REP(i,0,e){
        ret = max(ret, i*V[k] + F(min(E,e-i+R), k+1));
    }

    return ret;
}

int main(){
    freopen("B_small.in","r",stdin);
    freopen("B_small.out","w",stdout);

    int T=INT;
    REP(t,1,T){
        E=INT; R=INT; N=INT;
        FOR(i,N) V[i]=INT;
        CLR(dp,-1);

        printf("Case #%d: %d\n",t,F(E,0));
    }
    return 0;
}
