#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int res[][4]={{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};
const char yes[]="YES";
const char no[]="NO";
const long long INF=(long long)1e18+7LL;
int Abs(int x) {
    return (x<0?-x:x);
}
int calc(int x,int y) {
    int signX=x<0?-1:1;
    int signY=y<0?-1:1;
    int X=Abs(x);
    int Y=Abs(y);
    return (signX*signY*res[X-1][Y-1]);
}
int num(char c) {
    if (c=='i') return (2);
    if (c=='j') return (3);
    if (c=='k') return (4);
    assert(false);
}
int result(const string &s) {
    int res=1;
    REP(i,s.size()) res=calc(res,num(s[i]));
    return (res);
}
int result(const string &s,long long t) {
    int res=1;
    int mul=result(s);
    while (t>0) {
        if (t&1) res=calc(res,mul);
        mul=calc(mul,mul);
        t>>=1;
    }
    return (res);
}
string s;
long long t;
long long findFirst(const string &s,int val,bool rev) {
    int cur=1;
    REP(i,s.size()) {
        cur=rev?calc(num(s[i]),cur):calc(cur,num(s[i]));
        if (cur==val) return (i+1);
    }
    return (INF);
}
bool process(void) {
    cin>>t>>t>>s;
    if (result(s,t)!=calc(calc(2,3),4)) return (false);
    long long len=t*s.size();
    string tmp;
    REP(love,200) tmp+=s;
    long long left=findFirst(tmp,2,false);
    reverse(tmp.begin(),tmp.end());
    long long right=findFirst(tmp,4,true);
    return (left+right<len);
}
int main(void) {
    int t;
    cin>>t;
    FOR(i,1,t) printf("Case #%d: %s\n",i,process()?yes:no);
    return 0;
}
