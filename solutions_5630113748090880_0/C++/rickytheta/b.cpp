#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

void solve(int no){
  printf("Case #%d: ",no+1);
  int n;
  scanf("%d",&n);
  int cnt[2525];
  REP(i,2525)cnt[i]=0;
  REP(i,2*n-1){
    REP(j,n){
      int x;
      scanf("%d",&x);
      cnt[x]++;
    }
  }
  vi ans;
  REP(i,2525){
    if(cnt[i]%2==1){
      ans.push_back(i);
    }
  }
  cout<<ans[0];
  REPR(i,ans.size())cout<<" "<<ans[i];
  cout<<endl;
}

int main(){
  int t;
  scanf("%d",&t);
  REP(i,t)solve(i);
  return 0;
}
