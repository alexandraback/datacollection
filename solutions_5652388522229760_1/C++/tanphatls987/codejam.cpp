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

int n;
void solve(){
    if (n==0) {
        printf("INSOMNIA\n");
        return;
    }
    int tar=(1<<10)-1,mask=0;
    int cur=0;
    while (mask!=tar){
        cur+=n;
        int tmp=cur;
        while (tmp) mask|=1<<(tmp%10),tmp/=10;
    }
    printf("%d\n",cur);
}
int main(){
    freopen("input.inp","r",stdin);
    OUTPUT;
    int test;
    cin>>test;
    FOR(te,1,test){
        cin>>n;
        printf("Case #%d: ",te);
        solve();
    }
}
