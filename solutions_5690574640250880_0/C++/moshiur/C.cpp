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

int R, C, M;
char dp[52][52][52*52];

bool can(int r, int prev, int m){
    if( (R-r)*prev < m ) return false;

    if(m < 0) return false;
    if(r == R) return m == 0;

    char& ret = dp[r][prev][m];
    if(ret>-1)return ret;
    ret = false;

   // cout<<r<<" "<<prev<<" "<<m<<endl;

    for(int now = 0; now <= prev && now <= m; ++now){
        if(prev == C && now == C-1){
            if(r != R-1) continue;
        }

        if(r == R-1 && now < prev) {
            if(prev == C && now == C-1) ;
            else continue;
        }

        ret = ret || can(r+1, now, m-now);
        if(ret) break;
    }

    return ret;
}

void print(int r, int prev, int m){
    if(R == 1){
        FOR(i,m) printf("*"); FOR(i,C-m-1) printf("."); puts("c"); return;
    }
    if(C == 1){
        FOR(i,m) printf("*\n"); FOR(i,R-m-1) printf(".\n"); puts("c"); return;
    }

    if(r == R) return;

    if(!can(r,prev,m)){
        puts("Impossible");
        return;
    }

    int cur = -1;

    for(int now = 0; now <= prev && now <= m; ++now){
        if(prev == C && now == C-1){
            if(r != R-1) continue;
        }

        if(r == R-1 && now < prev) {
            if(prev == C && now == C-1) ;
            else continue;
        }
        if(can(r+1, now, m-now)){
            cur = now; break;
        }
    }

    if(cur == -1){
        printf("ERR: %d, %d, %d\n",r,prev,m);
    }

    assert(cur > -1);

    FOR(j,cur) printf("*");
    FOR(j,C-cur) {
        if(r == R-1 && j==C-cur-1)
        printf("c");
        else printf(".");
    }
    puts("");

    print(r+1, cur, m-cur);
}

int main() {
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C_small_out.txt","w",stdout);

    int T=INT;

    REP(t,1,T){
        CLR(dp,-1);

        R=INT;C=INT;M=INT;
        printf("Case #%d:\n",t); print(0,C,M);
    }
    return 0;
}
