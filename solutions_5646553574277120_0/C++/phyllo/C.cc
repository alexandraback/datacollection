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



int diff(const vector<int>& v, map<int,int>& orig){
  int ret = 0;
  rep(i,v.size()){
    if(orig.count(v[i]) == 0) ret++;
  }
  return ret;
}



int solve_small(int C, int V, vector<int> v){
  int ret = 0, ret2 = 0;

  vector<int> memo(V+1,0);
  rep(i,v.size()){
    if(v[i]<=V){
      memo[v[i]] = 1;
    }
  }

  if(V>=1 && memo[1] == 0) ret++;
  if(V>=2 && memo[2] == 0) ret++;
  if(V>=4 && memo[4] == 0) ret++;
  if(V>=8 && memo[8] == 0) ret++;
  if(V>=16 && memo[16] == 0) ret++;



  for(ll S=0; S<(1<<(v.size())); S++){
    int tmp = 0;
    rep(i,v.size()){
      if(S>>i&1) tmp += v[i];
    }
    if(tmp<=V){
      memo[tmp] = 1;
    }
  }
  REP(i,1,V+1){
    if(memo[i] == 0) ret2++;
  }

  return min(ret, ret2);
}



int main(){
  int T;

  cin >> T;
  rep(t,T){
    int C, D, V, tmp;
    cin >> C >> D >> V;
    vector<int> type;
    rep(i,D){
      cin >> tmp;
      type.push_back(tmp);
    }

    cout << "Case #" << t+1 << ": " << solve_small(C,V,type) << endl;
  }
  
  return 0;
}
