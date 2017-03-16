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


int n;
int bff[2521];
vi in[2521];
bool alused[2521];
bool used[2521];

int dfs(int p,int ng){
  alused[p] = true;
  int ret = 0;
  REP(i,in[p].size()){
    int to = in[p][i];
    if(to==ng)continue;
    ret = max(ret,dfs(to,ng)+1);
  }
  return ret;
}

pair<bool,int> calc(int p){
  // get cycle
  int cur = p;
  REP(i,n)used[i] = false;
  used[p] = true;
  int cnt = 0;
  while(true){
    ++cnt;
    cur = bff[cur];
    if(used[cur]){
      if(cur==p)break;
      return make_pair(false,0);
    }
    used[cur] = true;
  }
  cur = p;
  while(true){
    alused[cur] = true;
    cur = bff[cur];
    if(alused[cur])break;
  }
  pair<bool,int> ret;
  if(cnt==2){
    ret.first = true;
    // longest line
    cnt += dfs(bff[p],p);
    cnt += dfs(p,bff[p]);
    ret.second = cnt;
  }else{
    ret.first = false;
    ret.second = cnt;
  }
  return ret;
}

void solve(int no){
  printf("Case #%d: ",no+1);
  scanf("%d",&n);
  REP(i,n)in[i].clear();
  REP(i,n){
    scanf("%d",bff+i);
    bff[i] --;
    in[bff[i]].push_back(i);
  }
  int cycleans = 0;
  int lineans = 0;
  REP(i,n)alused[i] = false;
  REP(i,n){
    if(alused[i])continue;
    pair<bool,int> tmp = calc(i);
    if(tmp.first){
      // line
      lineans += tmp.second;
    }else{
      cycleans = max(cycleans, tmp.second);
    }
  }
  int ans = max(cycleans, lineans);
  printf("%d\n",ans);
}

int main(){
  int t;
  scanf("%d",&t);
  REP(i,t)solve(i);
  return 0;
}
