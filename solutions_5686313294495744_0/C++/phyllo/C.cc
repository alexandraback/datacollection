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

int solve_small(const vector< pair<string,string> >& v){
  int ret = 0;
  int N = v.size();

  for(ll S=0; S<(1<<N); S++){
    int cand_faker = 0;
    int is_faker = 0;
    rep(i,N){
      if(S>>i & 1){ //faker
        cand_faker++;
        bool chk1 = false, chk2 = false;
        rep(j,N){
          if(!(S>>j & 1)){ //real
            if(v[j].first == v[i].first) chk1 = true;
            if(v[j].second == v[i].second) chk2 = true;
          }
        }
        if(chk1 && chk2) is_faker++;
      }
    }
    if(cand_faker == is_faker) ret = max(ret, cand_faker);
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t,T){
    ll N;
    cin >> N;
    vector< pair<string,string> > v;
    rep(i,N){
      string a, b;
      cin >> a >> b;
      v.push_back(make_pair(a,b));
    }
    int ret = solve_small(v);
    cout << "Case #" << t+1 << ": " << ret << endl;
  }
  
  return 0;
}

