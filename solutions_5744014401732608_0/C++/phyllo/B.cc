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


void small_calc(int B, ll M){
  vector< pair<int,int> > w;
  rep(i,B){
    REP(j,i+1,B){
      w.push_back(make_pair(i,j));
    }
  }
  for(ll S=1; S<(1<<(w.size())); S++){
    vector<ll> ret(B, 0);
    ret[0] = 1;
    rep(i,w.size()){
      if((S>>i)&1){
        int a = w[i].first;
        int b = w[i].second;
        ret[b] += ret[a];
      }
    }
    if(ret[B-1] == M){
      vector< vector<int> > G(B, vector<int>(B,0));
      rep(i,w.size()){
        if((S>>i)&1){
          int a = w[i].first;
          int b = w[i].second;
          G[a][b] = 1;
        }
      }
      rep(i,B){
        rep(j,B){
          cout << G[i][j];
        }
        cout << endl;
      }
      return;
    }
  }

}

void solve(ll B, ll M){
  vector<ll> v(B,0);
  v[0] = 1;
  rep(i,v.size()){
    REP(j,i+1,v.size()){
      v[j] += v[i];
    }
  }
  if(v[B-1] < M){
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  cout << "POSSIBLE" << endl;
  small_calc(B, M);
}

int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t,T){
    ll B, M;
    cin >> B >> M;;
    cout << "Case #" << t+1 << ": ";
    solve(B, M);
  }
  
  return 0;
}

