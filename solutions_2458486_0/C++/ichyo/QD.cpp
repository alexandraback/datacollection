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
int N, K;
int start[20] = {};
vector<int> get[20];
int need[20] = {};
bool used[1 << 20];
int cur[20];
int pos[20];
bool dfs(int S, int k){
  if(k == N){
    return true;
  }
  if(used[S]) return false;
  used[S] = true;
  for(int i = 0; i < N; i++) if(0 == (S >> i & 1) && need[i] >= 0 && pos[need[i]] > 0){
    pos[need[i]]--;
    REP(j, get[i].size()) pos[get[i][j]]++;

    cur[k] = i;
    if(dfs(S | (1 << i), k + 1)) return true;

    REP(j, get[i].size()) pos[get[i][j]]--;
    pos[need[i]]++;
  }
  return false;
}

int main(){
  int T;
  cin >> T;
  REP(CASE, T){
    printf("Case #%d: ", CASE + 1);
    int K_; cin >> K_ >> N;
    vector<int> START(K_);
    REP(i, K_) cin >> START[i];
    vector<int> NEED(N);
    vector< vector<int> > GET(N);
    REP(i, N){
      cin >> NEED[i];
      int L; cin >> L;
      GET[i].assign(L, 0);
      REP(j, L)  cin >> GET[i][j];
    }
    vector<int> keys = NEED;
    sort(keys.begin(), keys.end());
    keys.erase(unique(keys.begin(), keys.end()), keys.end());
    K = keys.size();
    vector<int> id(201, -1);
    REP(i, K) id[keys[i]] = i;
    memset(start, 0, sizeof(start));
    REP(i, 20) get[i].clear();
    memset(need, 0, sizeof(need));
    memset(used, 0, sizeof(used));
    memset(pos, 0, sizeof(pos));
    REP(i, K_) if(id[START[i]] != -1) start[id[START[i]]]++;
    REP(i, N) REP(j, GET[i].size()) if(id[GET[i][j]] != -1) get[i].push_back(id[GET[i][j]]);
    REP(i, N) need[i] = id[NEED[i]];
    REP(i, K) pos[i] = start[i];
    if(dfs(0, 0)){
      REP(i, N) {
        cout << cur[i] + 1;
        if(i == N - 1) cout << endl;
        else cout << " ";
      }
    }else{
      cout << "IMPOSSIBLE" << endl;
    }
  }
  return 0;
}
