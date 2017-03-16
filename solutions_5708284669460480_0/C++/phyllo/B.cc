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

vector<string> v;
void dfs(string &key, string str, int S){
  if(str.length()==S){
    v.push_back(str);
    return;
  }
  rep(i,key.length()){
    dfs(key,str + key[i],S);
  }
}  

int cnttgt(const string& str, const string& tgt){
  int ret = 0;
  rep(i,str.length()-tgt.length()+1){
    bool flg = true;
    rep(j,tgt.length()){
      if(str[i+j] != tgt[j]){
        flg = false;
        break;
      }
    }
    if(flg) ret++;
  }
  return ret;
}

double solve_small(string key, string tgt, int S){
  v.clear();
  rep(i,key.length()){
    string tmp = "" + key[i];
    dfs(key,tmp,S);
  }

  double ret = 0;
  double mx = 0;
  rep(i,v.size()){
    int cnt = cnttgt(v[i], tgt);
    mx = max(mx, (double)cnt);
    ret += cnt;
  }
  ret /= (double)(v.size());
  
  return mx - ret;
}

int main(){
  int T;

  cin >> T;
  rep(t,T){
    int K, L, S;
    cin >> K >> L >> S;
    string key, tgt;
    cin >> key;
    cin >> tgt;
    
    cout << "Case #" << t+1 << ": ";
    printf("%.8lf\n", solve_small(key,tgt,S));
  }
  
  return 0;
}
