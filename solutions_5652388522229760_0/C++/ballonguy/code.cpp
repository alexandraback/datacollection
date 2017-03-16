#include<bits/stdc++.h>
using namespace std;
const int inf = 1000000001;
const int MOD = 1000000007;
typedef long long Int;
#define FOR(i,a,b) for(int i=(a); i<=(b);++i)
#define mp make_pair
#define pb push_back
#define sz(s) (int)((s).size())


bool z[11];

int main() {
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    int t;cin>>t;
    FOR(tt,1,t) {
        Int n;
        cin>>n;
        int ret=-1;
        memset(z, false, sizeof(z));
        int ans=0;
        FOR(i,1,1000000) {
            Int cur = i*n;
            for(;;) {
                int d = cur%10;
                ans += (!z[d]);
                z[d] = 1;
                cur /= 10;
                if(cur==0) break;
            }
            if(ans==10) {
                ret=i;
                break;
            }
        }
        cout<<"Case #"<<tt<<": ";
        if(ret==-1) cout<<"INSOMNIA\n";else cout<<ret*1LL*n<<endl;
    }
}
