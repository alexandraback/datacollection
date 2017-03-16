#include<bits/stdc++.h>
using namespace std;
const int inf = 1000000001;
const int MOD = 1000000007;
typedef long long Int;
#define FOR(i,a,b) for(int i=(a); i<=(b);++i)
#define mp make_pair
#define pb push_back
#define sz(s) (int)((s).size())



int main() {
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    int t;cin>>t;
    FOR(tt,1,t) {
        string s;cin>>s;
        s+='+';
        int ans=0;
        FOR(i,0,sz(s)-2) ans+=(s[i]!=s[i+1]);
        cout<<"Case #"<<tt<<": ";
        cout<<ans<<endl;
    }
}
