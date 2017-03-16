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

bool fair(int x){
    int d[50]; int i=0;
    while(x){d[i++]=x%10; x/=10;}
    --i;
    for(int j=0;j<i;++j,--i)if(d[i]!=d[j])return false;
    return true;
}

bool square(int x){
    int sq = (int)sqrt(double(x));

    if(sq*sq==x && fair(x) && fair(sq)) return true;

    return false;
}

int main(){
    freopen("C_small.in","r",stdin);
    freopen("C_small_output.txt","w",stdout);

    int T=INT;

    REP(t,1,T){
        int A=INT; int B=INT;
        int cnt=0;

        for(;A<=B;++A){
            if(fair(A)&&square(A)) ++cnt;
        }

        printf("Case #%d: %d\n",t,cnt);
    }
    return 0;
}
