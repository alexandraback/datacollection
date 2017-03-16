#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <cassert>
#include <ctime>
#include <list>
#include <numeric>
#include <fstream>

using namespace std;
static const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
#ifndef M_PI
const double M_PI=acos(-1.0);
#endif
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int((a).size()))
#define F first
#define S second
int dx[]={0,-1,0,1,1,1,-1,-1},dy[]={1,0,-1,0,1,-1,1,-1};

int memo[1<<20];
int k,n;
int have[200];
int op[200];
vector<int> key[200];

bool dfs(int vis,bool out=false){
  if(!out){
    if(vis==(1<<n)-1)
      return memo[vis]=true;
    if(memo[vis] != -1)
      return memo[vis];
    rep(i,n){
      if(((vis>>i)&1) || !have[op[i]]) continue;
      --have[op[i]];
      FOR(it,key[i]) ++have[*it];
      bool ok=dfs(vis|(1<<i));
      FOR(it,key[i]) --have[*it];    
      ++have[op[i]];
      if(ok) return memo[vis]=true;
    }
    return memo[vis]=false;
  }

  if(vis==(1<<n)-1) return true;
  rep(i,n){
      if(((vis>>i)&1) || !have[op[i]]) continue;
      if(memo[(1<<i)|vis]!=1) continue;
      cout << ' ' << i+1;
      --have[op[i]];
      FOR(it,key[i]) ++have[*it];
      return dfs(vis|(1<<i),true);
  }
  
}

void solve(int ca){
  printf("Case #%d:",ca);
  memset(memo,-1,sizeof(memo));
  rep(i,200){
    key[i].clear();
    have[i] = 0;
  }

  
  cin >> k >> n;
  rep(i,k){
    int a;
    cin >> a;
    ++have[a-1];
  }

  rep(i,n){
    int ki;
    cin >> op[i] >> ki;
    --op[i];
    rep(j,ki){
      int ik;
      cin >> ik;
      key[i].pb(ik-1);
    }
  }

  if(dfs(0)){
    dfs(0,1);
    cout << endl;
    return;
  }
  cout << " IMPOSSIBLE" << endl;
}

main(){
  int t;
  cin >> t;
  rep(i,t) solve(i+1);
}
