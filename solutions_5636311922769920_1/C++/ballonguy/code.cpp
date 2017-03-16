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
        Int k,c,s;
        cin>>k>>c>>s;
        vector<Int> ans;

        int i=1;
        bool z=false;
        while(!z) {
            Int pos = 1;
            FOR(iter, 1, c) {
                pos = (pos-1)*k + i;
                i++;
                if(i==k+1) {z=1;i=1;}
            }
            ans.pb(pos);
        }
        cout<<"Case #"<<tt<<":";
        if(sz(ans)>s) cout<<" IMPOSSIBLE\n";else {
            FOR(i,0,sz(ans)-1) cout<<" "<<ans[i];
            cout<<endl;
        }
    }
}
