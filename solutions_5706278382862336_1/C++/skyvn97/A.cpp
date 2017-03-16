#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
ll p,q;
inline ll gcd(ll a,ll b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a=a%b; else b=b%a;
    }
}
void process(int tc) {
    scanf("%lld/%lld",&p,&q);
    printf("Case #%d: ",tc);
    ll t=gcd(p,q);
    p=p/t;q=q/t;
    bool ok=false;
    REP(i,41) if (q==(1LL<<i)) ok=true;
    if (!ok) {
        printf("impossible\n");
        return;
    }
    ll tmp=(1LL<<40)/q*p;
    FOR(i,1,40) if (tmp>=(1LL<<(40-i))) {
        printf("%d\n",i);
        return;
    }
    assert(false);
}
int main(void) {
    int tc;
    scanf("%d",&tc);
    REP(zz,tc) process(zz+1);
    return 0;
}
