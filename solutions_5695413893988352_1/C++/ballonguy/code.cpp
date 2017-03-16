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
    return ans;
}


string fl(string s, char d) {
    FOR(i,0,sz(s)-1) if(s[i]=='?') s[i]=d;
    return s;
}


Int a, b;
void upd(string s1, string s2) {
    //cerr<<s1<<" "<<s2<<endl;
    Int p = get(s1);
    Int q = get(s2);
    //cerr<<p<<" "<<q<<endl;
    if(abs(p-q)<abs(a-b)) a=p, b=q;else
            if(abs(p-q)==abs(a-b)) {
                if(p<a || p==a && q<b) a=p, b=q;
            }
}

void go(string s11, string s22) {
    if(sz(s11)!=sz(s22)) cerr<<"wtf"<<endl;
    FOR(e, 0, sz(s11)) {
        string s1 = s11;
        string s2 = s22;
        bool ok=true;
        FOR(i,0,e-1) {
            if(s1[i]!=s2[i] && s1[i]!='?' && s2[i]!='?')ok=false; else
                if(s1[i]=='?' && s2[i]=='?') s1[i]=s2[i]='0';else
                    if(s1[i]=='?') s1[i]=s2[i];else
                        s2[i]=s1[i];
        }
        if(!ok) continue;

        if(e==sz(s11)) upd(s1, s2); else {
            if(s1[e]=='?' && s2[e]=='?') {
                string t1 = s1;
                string t2 = s2;
                t1[e]='0'; t1 = fl(t1, '9');
                t2[e]='1'; t2 = fl(t2, '0');
                upd(t1, t2);

                t1 = s1;
                t2 = s2;
                t1[e]='1'; t1 = fl(t1, '0');
                t2[e]='0'; t2 = fl(t2, '9');
                upd(t1, t2);
            } else {
                FOR(d1, 0, 9) FOR(d2, 0, 9) if(d1!=d2) {
                    string t1=s1,
                            t2 = s2;
                    if(s1[e]!='?' && d1!=s1[e]-'0') continue;
                    if(s2[e]!='?' && d2!=s2[e]-'0') continue;
                    t1[e]=d1+'0';
                    t2[e]=d2+'0';
                    if(d1<d2) {
                        t1 = fl(t1, '9');
                        t2 = fl(t2, '0');
                    } else {
                        t1 = fl(t1, '0');
                        t2 = fl(t2, '9');
                    }
                    upd(t1, t2);
                }
            }
        }
    }
}
string s;
pair<Int,Int> solve() {
    //string s;
    getline(cin, s);
    a=0, b=1e+18;

    vector<string> temp;
    string cur = "";
    FOR(i,0,sz(s)) if(i==sz(s) || s[i]==' ') temp.pb(cur), cur="";else cur+=s[i];

    string s1, s2;
    s1=temp[0];
    s2=temp[1];

    go(s1, s2);
    return mp(a, b);
}

int len(Int n) {
    if(n==0) return 1;
    Int ans=0;
    while(n) ans++, n/=10;
    return ans;
}

void pr(Int n) {
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
