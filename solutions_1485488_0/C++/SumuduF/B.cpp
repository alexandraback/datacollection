#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<PII> VP;
typedef pair<double, PII> PDP;

const double W_DROP = 10;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool canGo(int x, int y, int u, int v, const vector<VI> &f, const vector<VI> &c, double w) {
  if (max(0.0, w) > c[u][v] - 50) return false;
  if (f[x][y] > c[u][v] - 50) return false;
  if (f[u][v] > c[u][v] - 50) return false;
  if (f[u][v] > c[x][y] - 50) return false;

  return true;
  }

double flood(vector<VD> &bestHeight, int n, int m, int h, const vector<VI> &f, const vector<VI> &c) {
  bestHeight[0][0] = h;

  priority_queue<PDP> q; q.push(PDP(h, PII(0, 0)));

  while (!q.empty()) {
    PDP t = q.top(); q.pop();
    int x = t.second.first, y = t.second.second;
    if (t.first == bestHeight[x][y]) {
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if ((0 <= nx) && (nx < n) && (0 <= ny) && (ny < m)) {
          double wLeave = min(t.first, c[nx][ny] - 50.0);
          double wArrive = (wLeave < f[x][y]+20) ? (wLeave - 10*W_DROP) : (wLeave - W_DROP);
          if (wLeave == h)
            wArrive = h;

          if ((bestHeight[nx][ny] < wArrive) && canGo(x, y, nx, ny, f, c, wLeave)) {
            bestHeight[nx][ny] = wArrive;
            q.push(PDP(wArrive, PII(nx, ny)));
            }
          }
        }
      }
    }

  return (h - bestHeight[n-1][m-1]) / W_DROP;
  }

int main() {
  cout << fixed << setprecision(8);
  int nc; cin >> nc;
  for (int cur = 1; cur <= nc; ++cur) {
    int h, n, m; cin >> h >> n >> m;

    vector<VI> c(n, VI(m)), f(n, VI(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        cin >> c[i][j];
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        cin >> f[i][j];

    vector<VD> bestHeight(n, VD(m, -1E100));
    double minT = flood(bestHeight, n, m, h, f, c);

    cout << "Case #" << cur << ": " << minT << '\n';
    }
  }

