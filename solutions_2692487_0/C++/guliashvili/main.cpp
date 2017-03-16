#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<cmath>
#include<ctime>

#define FO(i,s,e,p) for(int i=(s);i<int(e);i+=p)
#define FOD(i,s,e,p) for(int i=(s);i>int(e);i-=p)


#define FOR(i,s,e) FO(i,s,e,1)
#define FORE(i,s,e) FOR(i,s,e+1)
#define FORD(i,s,e) FOD(i,s,e,1)
#define FORDE(i,s,e) FORD(i,s,e-1)

#define ALL(i,s) for(__typeof((s).begin()) i=(s).begin();i!=(s).end();i++)

#define MEM(tab,fill) memset(tab,fill,sizeof(tab))

#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
#include<bitset>
#include<map>
#include<cassert>
#define pb push_back
#define ll long long
using namespace std;

#define EPS 0.0000001
#define MOD 1000000007
#define mp make_pair
#define fi first
#define se second
#define inf ((1<<29)-1)
#define deb(a) cout<<#a<<' '<<a<<endl;
#define PI pair<ll,ll>
#define llu unsigned ll

#define AL(a) (a).begin(),(a).end()
#define PII pair<PI,PI>

ll MN(ll a,ll b){
    if(a==-1 || b==-1) return max(a,b);
    return min(a,b);
}

void solve(){
    ll me,n;cin>>me>>n;
    vector<ll> in(n);
    FOR(i,0,n) cin>>in[i];
    sort(in.rbegin(),in.rend());
    if(me==1){
        cout<<n;
        return;
    }
    ll ans=-1;

    ll sul=0;
    FORDE(i,n-1,0){
        if(in[i]<me){
            me+=in[i];
        }else{
            ans=MN(ans,i+1+sul);
            me+=me-1;
            sul++;
            i++;
        }

    }
    ans=MN(ans,sul);
    cout<<ans;






}

int main(){
    freopen("C:\\a","r",stdin);
    freopen("C:\\w","w",stdout);

    int t;cin>>t;
    FORE(i,1,t){
        printf("Case #%d: ",i);
        solve();
        cout<<endl;
    }




    return 0;
}
