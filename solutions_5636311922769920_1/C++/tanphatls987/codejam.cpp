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
const int N=0;

int n,m,k;
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
}
void solve(){
    vector <ll> ans;
    int cur=0;
    while (cur<n){
        ll pos=0;
        FOR(pha,1,m){
            pos=pos*n;
            if (cur<n)
                pos+=cur,cur++;
        }
        ans.push_back(pos+1);
    }
    if (ans.size()>k){
        printf("IMPOSSIBLE\n");
        return;
    }
    for(auto i:ans) printf("%lld ",i);ENDL;
}
int main(){
    freopen("input.inp","r",stdin);
    OUTPUT;
    int test;
    scanf("%d",&test);
    FOR(te,1,test){
        prepare();
        printf("Case #%d: ",te);
        solve();
    }
}
