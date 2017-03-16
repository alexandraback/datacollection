// Headers
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<vector>
#include<map>
#include<fstream>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
#include<bitset>
#include<set>
using namespace std;
// Global declarations
typedef long long int ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int,int> pi;
const double eps = 1e-6;
int const mod  = 1e9+7;
int const INF = 1<<29;
// Macros
#define mp make_pair
#define el putchar('\n')
#define sp putchar(' ')
#define Fill(a,val) memset(a,val,sizeof a)
#define pb push_back
#define ppb pop_back
#define gcd __gcd
#define all(a) a.begin(),a.end()
#define ff first
#define ss second

ll rev(ll n){
    ll ret = 0;
    while(n){
        ret = 10*ret + n%10;n/=10;
    }
    return ret;
}

ll ans[1000005];

int main(){
    freopen("ip.in","r",stdin);
    freopen("op.out","w",stdout);
    ll t,x=1;cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i=1;i<=n;++i) ans[i] = i;
        for(ll i=2;i<=n;++i){
            ans[i] = min(ans[i],ans[i-1]+1);
            ll dig = rev(i);
            if(dig > n) continue;
            if(dig > i) ans[dig] = min(ans[dig],ans[i]+1);
        }
        cout<<"Case #"<<x++<<": "<<ans[n];el;
    }
    return 0;
}
