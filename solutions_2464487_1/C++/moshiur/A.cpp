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

LL r, tot;

LL S(LL n){
    LL ret = n * (n-1);
    return ret>>1;
}

bool can(LL cnt){

    LL a = (2LL*(r+1LL)-1LL);

    if(a > tot/cnt) return false;

    LL area = a*cnt;

    area += S(cnt)*4LL;

   // area -= cnt;

    return area <= tot;
}

LL calc(){
    LL lo = 1, hi = 2000000000;

    while (hi-lo>1){
        LL m = (hi+lo)>>1;

        if(can(m)) lo=m; else hi=m;
    }

    return lo;
}

int main(){
    freopen("A_large.in","r",stdin);
    freopen("A_large.out","w",stdout);

    int T=INT;

    REP(kase,1,T){
        cin>>r>>tot;

        printf("Case #%d: ",kase); cout<<calc()<<"\n";
    }

    return 0;
}
