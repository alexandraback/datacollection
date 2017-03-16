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
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
long long valInBase(long long x,int n,int p) {
    long long res=0;
    FORD(i,n-1,0) {
        res*=p;
        res+=BIT(x,i);
    }
    return (res);
}
void process(int tc,int n,int req) {
    printf("Case #%d:\n",tc);
    REP(i,req) {
        long long tmp=MASK(n/2-1)+1+2*i;
        REP(love,2) FORD(j,n/2-1,0) printf("%d",BIT(tmp,j));
        FOR(j,2,10) printf(" %lld",valInBase(tmp,n,j));
        printf("\n");
    }
}
int main(void) {
    int t,n,r;
    scanf("%d%d%d",&t,&n,&r);
    process(t,n,r);
    return 0;
}
