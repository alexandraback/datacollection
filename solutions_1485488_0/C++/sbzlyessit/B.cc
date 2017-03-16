#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

const double EPS = 1e-10;
const int MAXN = 100;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

std::vector<std::pair<int, double> > heap;
double t[MAXN][MAXN];
int c[MAXN][MAXN], f[MAXN][MAXN];
bool used[MAXN][MAXN];

int Sgn(double x) { return x < -EPS ? -1 : (x > EPS ? 1 : 0); }
bool heapcmp(std::pair<int, double> &a, std::pair<int, double> &b) { return a.second > b.second; }

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt) {
    int H, n, m;
    scanf("%d%d%d", &H, &n, &m);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) scanf("%d", &c[i][j]);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) scanf("%d", &f[i][j]);
    for (int i = 0; i < n; ++i)
      std::fill(t[i], t[i] + m, 1e20);
    memset(used, false, sizeof(used));
    t[0][0] = 0.0;
    heap.push_back(std::make_pair(0, 0.0));
    for (int i = 0; i < n * m; ++i) {
      int x, y;
      while (!heap.empty()) {
        x = heap[0].first / m, y = heap[0].first % m;
        if (!used[x][y] && Sgn(t[x][y] - heap[0].second) == 0) break;
        std::pop_heap(heap.begin(), heap.end(), heapcmp);
        heap.pop_back();
      }
      if (heap.empty()) break;
      x = heap[0].first / m, y = heap[0].first % m;
      std::pop_heap(heap.begin(), heap.end(), heapcmp);
      heap.pop_back();
      used[x][y] = true;
      double level = std::max((double) f[x][y], H - t[x][y] * 10);
      for (int j = 0; j < 4; ++j) {
        int xx = x + dx[j], yy = y + dy[j];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m || used[xx][yy]) continue;
        if (c[xx][yy] - f[xx][yy] < 50 || c[xx][yy] - f[x][y] < 50 || c[x][y] - f[xx][yy] < 50) continue;
        if (Sgn(c[xx][yy] - level - 50) >= 0 && Sgn(t[x][y]) == 0) {
          t[xx][yy] = 0.0;
        } else if (Sgn(c[xx][yy] - level - 50) >= 0) {
          t[xx][yy] = std::min(t[xx][yy], t[x][y] + (Sgn(level - f[x][y] - 20) >= 0 ? 1 : 10));
        } else {
          int toLevel = c[xx][yy] - 50;
          t[xx][yy] = std::min(t[xx][yy], t[x][y] + (level - toLevel) / 10.0 + (Sgn(toLevel - f[x][y] - 20) >= 0 ? 1 : 10));
        }
        heap.push_back(std::make_pair(xx * m + yy, t[xx][yy]));
        std::push_heap(heap.begin(), heap.end(), heapcmp);
      }
    }
    printf("Case #%d: %lf\n", tt, t[n - 1][m - 1]);
  }
  return 0;
}
