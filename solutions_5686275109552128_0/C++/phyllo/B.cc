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

map<vector<int>,int> memo;

int dfs(const vector<int>& v){
  if(memo.count(v)>0){
    return memo[v];
  }

  //all 1
  bool flg = true;
  rep(i,v.size()) if(v[i]!=1){
    flg = false;
    break;
  }
  if(flg){
    return memo[v] = 1;
  }

  int res = 100000000;
  vector<int> w;

  //eat time
  rep(i,v.size()){
    if(v[i]>1){
      w.push_back(v[i]-1);
    }
  }
  res = dfs(w)+1;
  
  //special time
  if(v[0]>1){
    REP(i,1,v[0]){
      if(i>v[0]-i) break;
      w.clear();
      w.push_back(i);
      w.push_back(v[0]-i);
      REP(i,1,v.size()) w.push_back(v[i]);
      sort(ALLOF(w));
      reverse(ALLOF(w));
      res = min(res, dfs(w)+1);
    }
  }
  return memo[v] = res;
}

int solve_small(vector<int> v){
  int ret = 0;
  rep(i,v.size()){
    ret = max(ret, v[i]);
  }
  memo.clear();
  sort(ALLOF(v));
  reverse(ALLOF(v));
  
  ret = min(ret, dfs(v));
  /*
  FOR(itr,memo){
    cout << itr->second << " ";
    rep(i,(itr->first).size()){
      cout << " " << (itr->first)[i];
    }
    cout << endl;
  }
  */
  return ret;
}


int main(){
  int T;

  cin >> T;
  rep(t,T){
    int D, p;
    vector<int> v;

    cin >> D;
    rep(i,D){
      cin >> p;
      v.push_back(p);
    }
    cout << "Case #" << t+1 << ": " << solve_small(v) << endl;

  }
  
  return 0;
}
