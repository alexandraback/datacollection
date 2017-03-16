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

void flip(int arr[2][110], int n, int tgt){
  REP(i,tgt){
    int src = tgt-1-i;
    arr[1][i] = arr[0][src]^1;
  }
  FOR(i,tgt,n){
    arr[1][i] = arr[0][i];
  }
  swap(arr[0],arr[1]);
  return;
}

void solve(int case_no){
  // input
  printf("Case #%d: ",case_no+1);
  char s[110];
  scanf("%s",s);
  int n = 0;
  while(s[n]!='\0')++n;
  // solve
  int x[2][110];
  REP(i,n)x[0][i]=(s[i]=='+'?1:0);
  int cnt = 0;
  REP(_i,n){
    int i = n-1-_i;
    if(x[0][i]==1)continue;
    // need to flip
    int flipper = 0;
    REP(j,n){
      if(x[0][j]==0)break;
      flipper = j+1;
    }
    if(flipper!=0){
      flip(x,n,flipper); ++cnt;
    }
    flip(x,n,i+1); ++cnt;
  }
  printf("%d\n", cnt);
}

int main(){
  int t;
  scanf("%d",&t);
  REP(i,t)solve(i);
  return 0;
}
