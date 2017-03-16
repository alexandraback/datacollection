#include<bits/stdc++.h>
#define MAX   17
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
string word[MAX][2];
int f[MASK(MAX)+7],n;
void process(int tc) {
    cin>>n;
    REP(i,n) REP(j,2) cin>>word[i][j];
    memset(f,-1,sizeof f);
    f[0]=0;
    REP(i,MASK(n)) if (f[i]>=0) REP(j,n) if (!BIT(i,j)) {
        bool ok[2];
        REP(k,2) {
            ok[k]=false;
            REP(l,n) if (BIT(i,l) && word[l][k]==word[j][k]) ok[k]=true;
        }
        if (ok[0] && ok[1]) maximize(f[i|MASK(j)],f[i]+1);
        else maximize(f[i|MASK(j)],f[i]);
    }
    printf("Case #%d: %d\n",tc,f[MASK(n)-1]);
}
int main(void) {
    int t; cin>>t;
    FOR(i,1,t) process(i);
    return 0;
}
