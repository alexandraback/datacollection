#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define REP(i,n) for(int i=0;i<(n);++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define dump(x) cerr << "  (L" << __LINE__ << ") " << #x << " = " << (x) << endl;
#define dumpv(x) cerr << "  (L" << __LINE__ << ") " << #x << " = "; REP(q,(x).size()) cerr << (x)[q] << " "; cerr << endl;
template<typename T1, typename T2>
ostream& operator<<(ostream& s, const pair<T1, T2>& d) {return s << "(" << d.first << "," << d.second << ")";}


const int DR[] = {0, 0, -1, 1};
const int DC[] = {-1, 1, 0, 0};


double solve(int H, int N, int M, VVI& C, VVI& F) {
  vector<vector<bool> > reached(N, vector<bool>(M, false));
  vector<vector<double> > shortest(N, vector<double>(M, 100000000.0));
  priority_queue<pair<double, PII>, vector<pair<double, PII> >, greater<pair<double, PII> > > que;
  que.push(make_pair(0.0, PII(0, 0)));

  while (!que.empty()) {
    pair<double, PII> cur = que.top(); que.pop();
    double t = cur.first;
    int r = cur.second.first;
    int c = cur.second.second;
    reached[r][c] = true;

    //printf("--- processing (%d, %d) = %f\n", r, c, t);
    if (r == N-1 && c == M-1) {
      return t;
    }

    for (int k = 0; k < 4; k++) {
      int nr = r + DR[k];
      int nc = c + DC[k];
      if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
      if (reached[nr][nc]) continue;

      if (C[nr][nc] >= F[r][c] + 50 && C[nr][nc] >= F[nr][nc] + 50 && C[r][c] >= F[nr][nc] + 50) {
        
        double time_to_clear = max(0.0, (H - (double)(C[nr][nc]-50)) / 10.0);
        //dump(time_to_clear);
        double time = max(t, time_to_clear);
        if (t != 0.0 || time_to_clear != 0.0) {
          if (H - time * 10 >= F[r][c] + 20) {
            time += 1.0;
          } else {
            time += 10.0;
          }
        }
        //printf("  ## PUSH (%f, (%d, %d))\n", time, nr, nc);
        if (time < shortest[nr][nc]) {
          que.push(make_pair(time, PII(nr, nc)));
          shortest[nr][nc] = min(shortest[nr][nc], time);
        }
      }
    }
  }

  return -1;
}

int main() {
  int T; cin >> T;
  REP(t, T) {
    int H, N, M; cin >> H >> N >> M;
    VVI C(N, VI(M));
    REP(i, N) REP(j, M) cin >> C[i][j];
    VVI F(N, VI(M));
    REP(i, N) REP(j, M) cin >> F[i][j];

    double ans = solve(H, N, M, C, F);
    printf("Case #%d: %.7f\n", t+1, ans);
  }
}

