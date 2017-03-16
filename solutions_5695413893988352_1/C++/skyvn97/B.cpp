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
const long long INF=(long long)1e18+7LL;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
string numStr(long long x,int len) {
    string res;
    while (x>0) {
        res.push_back(x%10+'0');
        x/=10;
    }
    while (res.size()<len) res.push_back('0');
    reverse(ALL(res));
    return (res);
}
long long canEqual(string s,string t) {
    REP(i,s.size()) if (s[i]!='?' && t[i]!='?' && s[i]!=t[i]) return (-1);
    long long res=0;
    REP(i,s.size()) {
        int chs;
        if (s[i]!='?') chs=s[i]-'0';
        else if (t[i]!='?') chs=t[i]-'0';
        else chs=0;
        res=res*10+chs;
    }
    return (res);
}
long long Abs(long long x) {
    return (x<0?-x:x);
}
pair<long long,long long> better(const pair<long long,long long> &a,const pair<long long,long long> &b) {
    long long va=Abs(a.fi-a.se);
    long long vb=Abs(b.fi-b.se);
    if (va!=vb) return (va<vb?a:b);
    return (min(a,b));
}
pair<long long,long long> biggerAt(string s,string t,int pos) {
    long long a=0,b=0;
    REP(i,s.size()) {
        if (i<pos) {
            int chs;
            if (s[i]!='?' && t[i]!='?' && s[i]!=t[i]) return (make_pair(INF,-1));
            if (s[i]!='?') chs=s[i]-'0';
            else if (t[i]!='?') chs=t[i]-'0';
            else chs=0;
            a=a*10+chs;
            b=b*10+chs;
        } else if (i==pos) {
            if (s[i]=='0' || t[i]=='9') return (make_pair(INF,-1));
            if (s[i]!='?' && t[i]!='?' && s[i]<=t[i]) return (make_pair(INF,-1));
            int chsA,chsB;
            if (s[i]=='?' && t[i]=='?') {
                chsA=1;chsB=0;
            } else if (s[i]=='?') {
                chsA=t[i]-'0'+1;
                chsB=t[i]-'0';
            } else if (t[i]=='?') {
                chsA=s[i]-'0';
                chsB=s[i]-'0'-1;
            } else {
                chsA=s[i]-'0';
                chsB=t[i]-'0';
            }
            a=a*10+chsA;
            b=b*10+chsB;
        } else {
            int chsA=s[i]=='?'?0:s[i]-'0';
            int chsB=t[i]=='?'?9:t[i]-'0';
            a=a*10+chsA;
            b=b*10+chsB;
        }
    }
    return (make_pair(a,b));
}
pair<long long,long long> solve(string s,string t) {
    pair<long long,long long> res(INF,-1);
    REP(i,s.size()) res=better(res,biggerAt(s,t,i));
    return (res);
}
void process(int tc) {
    string s,t; cin>>s>>t;
    if (canEqual(s,t)>=0) {
        long long x=canEqual(s,t);
        printf("Case #%d: %s %s\n",tc,numStr(x,s.size()).c_str(),numStr(x,t.size()).c_str());
        return;
    }
    pair<long long,long long> a=solve(s,t);
    pair<long long,long long> b=solve(t,s);
    swap(b.fi,b.se);
    pair<long long,long long> best=better(a,b);
    printf("Case #%d: %s %s\n",tc,numStr(best.fi,s.size()).c_str(),numStr(best.se,s.size()).c_str());
}
int main(void) {
    int t; cin>>t;
    FOR(i,1,t) process(i);
    return 0;
}
