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
  static string IMP = "IMPOSSIBLE";
  int k,c,s;
  scanf("%d%d%d",&k,&c,&s);
  printf("Case #%d: ",no+1);
  vl ans;
  if(c==1){
    // brute force
    REP(i,k)ans.push_back(i+1);
  }else{
    // twice efficient
    // unit = k + k^2 + ... + k^(c-1)
    ll unit = 0;
    ll b = 1;
    REP(i,c-1){
      b *= k;
      unit += b;
    }
    REP(i,k/2){
      ll a = 2*i;
      ll b = 2*i+1;
      ll head = unit*a;
      ll tgt = head + b;
      ans.push_back(tgt+1);
    }
    if(k%2==1){
      ans.push_back(k);
    }
  }
  if(ans.size()>s){
    puts(IMP.c_str());
  }else{
    printf("%lld",ans[0]);
    REPR(i,ans.size()) printf(" %lld",ans[i]);
    printf("\n");
  }
}

int main(){
  int t;
  scanf("%d",&t);
  REP(i,t)solve(i);
  return 0;
}
