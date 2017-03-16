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
const string digit[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
const int order[]={0,2,4,6,8,1,3,5,7,9};
const char special[]="ZWUXGORFSI";
string answer(string s) {
    int cnt[333];
    memset(cnt,0,sizeof cnt);
    FORE(it,s) cnt[*it]++;
    int res[111];
    memset(res,0,sizeof res);
    REP(i,10) {
        res[order[i]]=cnt[special[i]];
        FORE(it,digit[order[i]]) cnt[*it]-=res[order[i]];
    }
    string num;
    REP(i,10) num+=string(res[i],'0'+i);
    return (num);
}
int main(void) {
    int t; cin>>t;
    FOR(i,1,t) {
        string s; cin>>s;
        printf("Case #%d: %s\n",i,answer(s).c_str());
    }
    return 0;
}
