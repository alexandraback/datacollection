#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
void process(int tc) {
    string s;
    cin>>s>>s;
    int res=0;
    int sum=0;
    REP(i,s.size()) {
        if (sum<i && s[i]!='0') {
            res+=i-sum;
            sum+=i-sum;
        }
        sum+=s[i]-'0';
    }
    printf("Case #%d: %d\n",tc,res);
}
int main(void) {
    int t;
    cin>>t;
    FOR(i,1,t) process(i);
    return 0;
}
