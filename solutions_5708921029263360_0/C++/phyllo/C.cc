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

struct COMP {
  int i, j, k;
  bool operator()(const string& a, const string& b){
    if(a[i] == b[i]){
      if(a[j] == b[j]) return a[k] < b[k];
      return a[j] < b[j];
    }
    return a[i] < b[i];
  }
};

void solve(int J, int P, int S, int K){
  map<string,int> memo;
  vector<string> v;
  string str = "000";
  rep(i,J){
    rep(j,P){
      rep(k,S){
        str[0] = '1' + i;
        str[1] = '1' + j;
        str[2] = '1' + k;
        v.push_back(str);
      }
    }
  }
  COMP comp;
  
  vector<int> w;
  w.push_back(0);
  w.push_back(1);
  w.push_back(2);
  int mx = 0;
  vector<string> best;
  do {
    comp.i = w[0];
    comp.j = w[1];
    comp.k = w[2];
    sort(ALLOF(v), comp);
    
    memo.clear();
    vector<string> ret;
    rep(i,v.size()){
      str = v[i];
      string s1 = str;
      s1[0] = '0';
      string s2 = str;
      s2[1] = '0';
      string s3 = str;
      s3[2] = '0';
      
      int l1 = memo[s1];
      int l2 = memo[s2];
      int l3 = memo[s3];
      if(l1+1 >= K || l2+1 >= K || l3+1 >= K) continue;
      ret.push_back(str);
      memo[s1] += 1;
      memo[s2] += 1;
      memo[s3] += 1;
    }
    if(mx < ret.size()){
      mx = ret.size();
      best = ret;
    }
  }while(next_permutation(ALLOF(w)));

  cout << best.size() << endl;
  rep(i,best.size()){
    cout << best[i][0] << " " << best[i][1] << " " << best[i][2] << endl;
  }

}

int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t,T){
    int J, P, S, K;
    cin >> J >> P >> S >> K;
    cout << "Case #" << t+1 << ": ";
    solve(J, P, S, K);
  }
  return 0;
}

