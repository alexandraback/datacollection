#include<bits/stdc++.h>
using namespace std;
const int inf = 1000000001;
const int MOD = 1000000007;
typedef long long Int;
#define FOR(i,a,b) for(int i=(a); i<=(b);++i)
#define mp make_pair
#define pb push_back
#define sz(s) (int)((s).size())
string s1[22], s2[222];

int solve() {
    int n;cin>>n;
    FOR(i,0,n-1) cin>>s1[i]>>s2[i];
    int ans=0;
    FOR(mask,0,(1<<n)-1) {
        bool ok=true;
        int cur=0;
        FOR(i,0,n-1) if(mask&(1<<i)) {
            ++cur;
            bool o1=false, o2=false;
            FOR(j,0,n-1) if(mask&(1<<j));else {
                if(s1[j]==s1[i]) o1=true;
                if(s2[j]==s2[i]) o2=true;
            }
            if(!o1 || !o2) ok=false;
        }
        if(ok) ans=max(ans, cur);
    }
    return ans;
}


int main() {
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    int tests;
    scanf("%d\n",&tests);
    FOR(idtest, 1, tests) {
        int ans = solve();
        cout<<"Case #"<<idtest<<": ";
        cout<<ans<<endl;
    }
}
