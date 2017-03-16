#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
vector< vector<int> > cards;
int T, R, N, M, K;
int tmp[12];
void dfs(int k, int last){
  if(k == N){
    vector<int> c;
    REP(i, N) c.push_back(tmp[i]);
    cards.push_back(c);
    return;
  }
  for(int i = last; i <= M; i++){
    tmp[k] = i;
    dfs(k + 1, i);
  }
}
double pos[20000];
map<ll, double> pos2[20000];
void init(){
  dfs(0, 2);
  double fact[15];
  fact[1] = 1.0;
  for(int i = 2; i < 15; i++) fact[i] = fact[i - 1] * i;
  REP(i, cards.size()){
    vector<int> c = cards[i];
    map<int, int> cnt;
    REP(j, c.size()) cnt[c[j]]++;
    pos[i] = fact[c.size()];
    FORIT(it, cnt) pos[i] /= fact[it->second];
  }
  REP(i, cards.size()){
    vector<int> c = cards[i];
    REP(S, 1 << c.size()){
      ll mul = 1;
      REP(j, c.size()) if(S >> j & 1) mul *= c[j];
      pos2[i][mul] += 1.0;
    }
  }
}

int main(){
  cin >> T >> R >> N >> M >> K;
  init();
  printf("Case #1:\n");
  REP(iter, R){
    vector<ll> v(K);
    REP(i, K) cin >> v[i];
    double max_p = 0;
    vector<int> ans;
    REP(i, cards.size()){
      double p = pos[i];
      REP(j, K) p *= pos2[i][v[j]];
      if(p > max_p){
        p = max_p;
        ans = cards[i];
      }
    }
    REP(i, ans.size()) cout << ans[i]; cout << endl;
  }
  return 0;
}
