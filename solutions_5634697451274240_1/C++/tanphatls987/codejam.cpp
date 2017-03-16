#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("codejam.inp","r",stdin)
#define OUTPUT freopen("codejam.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e2+10;

int n,a[N];
string s;
void prepare(){
    a[0]=-1;
    n=0;
    cin>>s;
    for(auto i:s) {
        a[++n]=i=='+';
        if (a[n]==a[n-1]) n--;
    }
}
int solve(){
    int tar=1,ans=0;
//    cout<<n<<'\n';
//    FOR(i,1,n) cout<<a[i]<<" ";ENDL;
    FORD(i,n,1) if (a[i]!=tar) ans++,tar^=1;
    return ans;
}
int main(){
    freopen("input.inp","r",stdin);
    OUTPUT;
    int test;
    cin>>test;
    FOR(te,1,test){
        prepare();
        printf("Case #%d: %d\n",te,solve());
    }
}
