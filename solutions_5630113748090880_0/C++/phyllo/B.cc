#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <stack>
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

vector<int> solve(int N, vector< vector<int> > v){
  vector<int> ret;
  map<int,int> memo;
  rep(i,v.size()){
    rep(j,v[i].size()){
      memo[v[i][j]]++;
    }
  }
  FOR(it,memo){
    if(it->second%2!=0){
      ret.push_back(it->first);
    }
  }
  sort(ALLOF(ret));
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t,T){
    int N;
    vector< vector<int> > v;
    cin >> N;
    rep(i,2*N-1){
      vector<int> tmp;
      rep(j,N){
        int a;
        cin >> a;
        tmp.push_back(a);
      }
      v.push_back(tmp);
    }
    vector<int> ret = solve(N, v);
    cout << "Case #" << t+1 << ":";
    rep(i,ret.size()){
      cout << " " << ret[i];
    }
    cout << endl;
  }
  
  return 0;
}

