#include<bits/stdc++.h>
using namespace std;
const int inf = 1000000001;
const int MOD = 1000000007;
typedef long long Int;
#define FOR(i,a,b) for(int i=(a); i<=(b);++i)
#define mp make_pair
#define pb push_back
#define sz(s) (int)((s).size())

Int get(string s) {
    Int ans=0;
    FOR(i,0,sz(s)-1) ans = 10*ans+s[i]-'0';
}

Int a, b;
string s1, s2;
string s;

void go(int pos, string have) {
    if(pos==sz(s)) {
        stringstream ss;
        ss<<have;
        Int p, q;
        ss>>p>>q;
        if(abs(p-q)<abs(a-b)) a=p, b=q;else
            if(abs(p-q)==abs(a-b)) {
                if(p<a || p==a && q<b) a=p, b=q;
            }
        return;
    }
    if(s[pos]=='?') {

        FOR(d,'0','9') go(pos+1, have+char(d));
        return;
    }else
        go(pos+1, have+s[pos]);
}

pair<Int,Int> solve() {
    getline(cin, s);
    a=0, b=1e+18;
    go(0, "");
    return mp(a, b);
}

int len(Int n) {
    if(n==0) return 1;
    Int ans=0;
    while(n) ans++, n/=10;
    return ans;
}

void pr(int n) {
    FOR(it,1,sz(s)/2-len(n)) cout<<"0";
    cout<<n;
}


int main() {
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    int tests;
    scanf("%d\n",&tests);
    FOR(idtest, 1, tests) {
        pair<Int, Int> ans = solve();
        cout<<"Case #"<<idtest<<": ";
        pr(ans.first);
        cout<<" ";
        pr(ans.second);
        cout<<endl;
    }
}
