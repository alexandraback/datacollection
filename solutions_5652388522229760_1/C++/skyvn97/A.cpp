#include<bits/stdc++.h>
#define MAX   100100
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
const char noAns[]="INSOMNIA";
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int digitMask(long long x) {
    if (x==0) return (MASK(0));
    int res=0;
    while (x>0) {
        res|=MASK(x%10);
        x/=10;
    }
    return (res);
}
void process(int tc) {
    int n;
    scanf("%d",&n);
    int res=0;
    FOR(i,1,MAX) {
        res|=digitMask(1LL*i*n);
        if (res==MASK(10)-1) {
            printf("Case #%d: %lld\n",tc,1LL*i*n);
            return;
        }
    }
    printf("Case #%d: %s\n",tc,noAns);
}
int main(void) {
    int t;
    scanf("%d",&t);
    FOR(i,1,t) process(i);
    return 0;
}
