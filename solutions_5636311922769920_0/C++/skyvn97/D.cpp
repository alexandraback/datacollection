#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
const char noAns[]="IMPOSSIBLE";
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int c,k,s;
void process(int tc) {
    scanf("%d%d%d",&k,&c,&s);
    printf("Case #%d: ",tc);
    if (c*s<k) {
        printf("%s\n",noAns);
        return;
    }
    int tmp=0;
    set<long long> res;
    REP(love,s) {
        long long val=0;
        REP(i,c) {
            val=val*k+tmp;
            tmp=(tmp+1)%k;
        }
        res.insert(val+1);
    }
    FORE(it,res) printf("%lld ",*it); printf("\n");
}
int main(void) {
    int t;
    scanf("%d",&t);
    FOR(i,1,t) process(i);
    return 0;
}
