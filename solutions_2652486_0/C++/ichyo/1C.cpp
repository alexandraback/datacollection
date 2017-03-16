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

int main(){
  int pos[4 * 4 * 4][5 * 5 * 5 + 1] = {};
  for(int A = 0; A < 4 * 4 * 4; A++){
    int a[3];
    int TA = A;
    REP(i, 3){
      a[i] = (TA % 4) + 2;
      TA /= 4;
    }
    for(int S = 0; S < 1 << 3; S++){
      int M = 1;
      REP(i, 3) if(S >> i & 1) M *= a[i];
      pos[A][M] ++;
    }
  }
  int T;
  cin >> T;
  REP(CASE, T){
    printf("Case #%d:\n", CASE);
    int R, N, M, K;
    cin >> R >> N >> M >> K;
    assert(N == 3 && M == 5);
    REP(iter, R){
      vector<int> v(K);
      REP(i, K) cin >> v[i];
      REP(i, K) assert(v[i] <= 5 * 5 * 5);
      map<ll, vector<int> > ary_map;
      int ans[3];
      for(int A = 0; A < 4 * 4 * 4; A++){
        ll mul = 1;
        REP(i, K) mul *= pos[A][v[i]];
        ary_map[mul].push_back(A);
      }
      map<ll, vector<int> >::reverse_iterator it = ary_map.rbegin();
      int L = it->second.size();
      int TA = it->second[rand() % L];
      REP(i, 3) {
        cout << (TA % 4 + 2);
        TA /= 4;
      }
      cout << endl;
    }
  }
  return 0;
}
