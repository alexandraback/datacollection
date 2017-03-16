#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

ll ret;

void dfs(int i, ll prevE, ll gain, ll E, ll R, const vector<ll>& v){
  if(i==v.size()){
    ret = max(ret, gain);
    return;
  }
  
  ll nowE = min(E, prevE + R);
  
  rep(j,nowE+1){
    dfs(i+1, nowE-j, gain+v[i]*j, E, R, v);
  }
}

ll solve(ll E, ll R, const vector<ll>& v){
  ret = 0;

  dfs(0, E, 0, E, R, v);

  return ret;
}


int main(){
  int T;
  cin >> T;
  
  rep(t,T){
    ll E, R, N;
    vector<ll> v;
    cin >> E >> R >> N;
    rep(i,N){
      ll tmp;
      cin >> tmp;
      v.push_back(tmp);
    }
    cout << "Case #" << t+1 << ": " << solve(E,R,v) << endl;
  }
  
  return 0;
}
