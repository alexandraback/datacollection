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

void solve(int case_no){
  printf("Case #%d: ",case_no+1);
  int n;
  scanf("%d",&n);
  assert(n<=1000000);   // large
  if(n==0){
    puts("INSOMNIA");
    return;
  }
  bool ok[10];
  REP(i,10)ok[i]=false;
  int cnt = 0;
  int x = n;
  while(true){
    int t = x;
    while(t){
      int c = t%10;
      if(!ok[c]){
        ++cnt;
        if(cnt==10){
          printf("%d\n",x);
          return;
        }
        ok[c]=true;
      }
      t/=10;
    }
    x += n;
  }
}

int main(){
  int t;
  scanf("%d",&t);
  REP(i,t)solve(i);
  return 0;
}
