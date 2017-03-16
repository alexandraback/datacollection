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

double C,F,X;

int main() {
    freopen("B-large.in","r",stdin);
    freopen("B_large_out.txt","w",stdout);

    int T=INT;
    REP(t,1,T){
        scanf("%lf%lf%lf",&C,&F,&X);

        double ans = X / 2.0;

        double time_elapsed = 0.0;

        for(int i = 1; ; ++i){ // use i factories
            double rate = 2.0 + double(i-1)*F;
            double time_required = C / rate;
            double tmp = time_elapsed + time_required + X / double(rate + F);
            if(tmp > ans) break;
            ans=tmp;
            time_elapsed += time_required;
        }

        printf("Case #%d: %.7lf\n",t,ans);
    }
    return 0;
}
