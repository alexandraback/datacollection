#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define X first
#define Y second
#define PB push_back
#define FOR(x,y) for (int x = 0; x < int(y); ++x)
#define debug(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef vector<bool> Vb;
typedef vector<Vb> Mb;
typedef vector<char> Vc;
typedef vector<Vc> Mc;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<P> Vp;
typedef vector<Vp> Mp;
typedef vector<string> Vs;
typedef vector<Vs> Ms;

typedef queue<P> Q;
typedef priority_queue<PP> PQ;
typedef stack<int> STACK;
typedef set<int> SET;
typedef SET::iterator Sit;
typedef map<int, int> MAP;
typedef MAP::iterator Mit;
typedef stringstream SS;

template <class Ta, class Tb> inline Tb cast(Ta a) { SS ss; ss << a; Tb b; ss >> b; return b; };

const double EPS = 1e-9;
const int INF = 1000000000;
const int MOD = 1000000007;
const int diri[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dirj[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int H, R, C;
Mi A, B;

inline bool inside(int r, int c) {
  return 0 <= r and r < R and 0 <= c and c < C;
}

inline bool can_move(int a1, int b1, int a2, int b2) {
  return a1 <= b2 - 50 and a2 <= b2 - 50 and a2 <= b1 - 50;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    cin >> H >> R >> C;
    A = B = Mi(R, Vi(C));
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        cin >> B[i][j];
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        cin >> A[i][j];
    
    Mi dist(R, Vi(C, INF));
    dist[0][0] = 0;
    Q q;
    q.push(P(0, 0));
    while (q.size()) {
      int r = q.front().X;
      int c = q.front().Y;
      q.pop();
      
      for (int k = 0; k < 4; ++k) {
        int i = r + diri[k];
        int j = c + dirj[k];
        if (inside(i, j) and dist[i][j] > 0 and can_move(A[r][c], B[r][c], A[i][j], B[i][j]) and H <= B[i][j] - 50) {
          dist[i][j] = 0;
          q.push(P(i, j));
        }
      }
    }
    
    PQ pq;
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j) {
        if (dist[i][j] == 0) {
          pq.push(PP(0, P(i, j)));
        }
      }
    while (pq.size()) {
      int d = -pq.top().X;
      int r = pq.top().Y.X;
      int c = pq.top().Y.Y;
      pq.pop();
      
      if (d != dist[r][c]) continue;
      if (r == R - 1 and c == C - 1) break;
      
      for (int k = 0; k < 4; ++k) {
        int i = r + diri[k];
        int j = c + dirj[k];
        if (inside(i, j) and can_move(A[r][c], B[r][c], A[i][j], B[i][j])) {
          int t = max(d, H - B[i][j] + 50);
          if (H - t - A[r][c] >= 20) t += 10;
          else t += 100;
          if (t < dist[i][j]) {
            dist[i][j] = t;
            pq.push(PP(-t, P(i, j)));
          }
        }
      }
    }
    
//     for (int i = 0; i < R; ++i) {
//       for (int j = 0; j < C; ++j)
//         cerr << "\t" << (dist[i][j] < INF ? dist[i][j] : -1);
//       cerr << endl;
//     }
    
    cout << "Case #" << cas << ": " << dist[R - 1][C - 1]/10 << "." << dist[R - 1][C - 1]%10 << endl;
  }
}
