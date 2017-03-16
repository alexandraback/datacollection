#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long i64;

typedef i64 nkr_int;

typedef pair<i64, i64> pi;

typedef vector<nkr_int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define iter(T) T::iterator
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(s, e, n)  for(n = (s); n < (e); ++n)

typedef unsigned long long ui64;

class Solver {
public:
  Solver() {}
  ~Solver() {}

  void solve();
};

i64 bit_count(ui64 b) {
  i64 ans = 0;
  while(b != 0) {
    ans += b % 2;
    b /= 2;
  }
  return ans;
}

bool enclosed(i64 N, i64 M, i64 K, ui64 b) {
  vvi stones(N, vi(M, 0));
  vvi visited(N, vi(M, 0));
  i64 i, j;
  REP(0, N, i) {
    REP(0, M, j) {
      stones[i][j] = b % 2;
      b /= 2;

      visited[i][j] = stones[i][j];
    }
  }

  i64 ct_open = 0;
  set<pi> points;
  REP(0, M, j) {
    if(stones[0][j] == 0) {
      points.insert(pi(0, j));
    }
    if(stones[N-1][j] == 0) {
      points.insert(pi(N-1, j));
    }
  }
  REP(1, N-1, i) {
    if(stones[i][0] == 0) {
      points.insert(pi(i, 0));
    }
    if(stones[i][M-1] == 0) {
      points.insert(pi(i,M-1));
    }
  }

  while(!points.empty()) {
    pi cur = *points.begin();
    points.erase(points.begin());
    visited[cur.first][cur.second] = 1;
    ct_open++;

    if(cur.first != 0 && visited[cur.first-1][cur.second] == 0) {
      points.insert(pi(cur.first-1, cur.second));
    }
    if(cur.first != N-1 && visited[cur.first+1][cur.second] == 0) {
      points.insert(pi(cur.first+1, cur.second));
    }
    if(cur.second != 0 && visited[cur.first][cur.second-1] == 0) {
      points.insert(pi(cur.first, cur.second-1));
    }
    if(cur.second != M-1 && visited[cur.first][cur.second+1] == 0) {
      points.insert(pi(cur.first, cur.second+1));
    }

  }

  if(N * M - ct_open >= K) {
    return true;
  }
  return false;

}

void Solver::solve() {
  i64 N, M, K;
  cin >> N >> M >> K;

  ui64 b;
  ui64 b_max = 1 << (N * M);

  i64 ans = N * M;
  REP(0, b_max, b) {
    if(enclosed(N, M, K, b)) {
      ans = min(ans, bit_count(b));
    }
  }
  cout << ans << endl;
}

int main(int argc, char *argv[]){

  i64 N;
  cin >> N;
  i64 n;

  Solver s;

  REP(0, N, n) {
    cout << "Case #" << n + 1 << ": ";

    s.solve();
  }

  return 0;
}

