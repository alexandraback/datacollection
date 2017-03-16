#include <iostream>
#include <queue>
#include <vector>

#define FR first
#define SC second

using namespace std;

typedef vector<int> VI;
typedef vector<VI> V2I;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int DY[] = {-1, 0, 1, 0};
const int DX[] = {0, 1, 0, -1};

inline int max(int a, int b, int c) {
  return max(a, max(b, c));
}

inline bool inside(int y, int x, int h, int w) {
  return y >= 0 && x >= 0 && y < h && x < w;
}

void flood(const V2I& c, const V2I& f, int h, V2I& dist, int y, int x) {
  if (dist[y][x] == 0) {
    return;
  }
  dist[y][x] = 0;
  for (int dir = 0; dir < 4; ++dir) {
    int ny = y+DY[dir];
    int nx = x+DX[dir];
    if (inside(ny, nx, int(dist.size()), int(dist[0].size()))) {
      if (min(c[y][x], c[ny][nx])-max(h, f[y][x], f[ny][nx]) >= 50) {
        flood(c, f, h, dist, ny, nx);
      }
    }
  }
}

int main() {
  cout.setf(ios::fixed);
  cout.precision(1);
  int T;
  cin >> T;
  for (int ca = 1; T--; ++ca) {
    int h, n, m;
    cin >> h >> n >> m;
    vector<vector<int> > c(n, vector<int>(m)), f(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> c[i][j];
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> f[i][j];
      }
    }
    vector<vector<int> > dist(n, vector<int>(m, INF));
    flood(c, f, h, dist, 0, 0);
    priority_queue<pair<int, PII>, vector<pair<int, PII> >, greater<pair<int, PII> > > pq;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) if (dist[i][j] == 0) {
        pq.push(pair<int, PII>(0, PII(i, j)));
      }
    }
    for (; !pq.empty();) {
      int d = pq.top().FR;
      int y = pq.top().SC.FR;
      int x = pq.top().SC.SC;
      pq.pop();
      if (dist[y][x] > d) {
        continue;
      }
      for (int dir = 0; dir < 4; ++dir) {
        int ny = y+DY[dir];
        int nx = x+DX[dir];
        if (!inside(ny, nx, n, m) || min(c[y][x], c[ny][nx])-max(f[y][x], f[ny][nx]) < 50) {
          continue;
        }
        int water_level = h-dist[y][x];
        int wait = max(0, water_level-(c[ny][nx]-50));
        water_level -= wait;
        int move = 10;
        if (water_level < f[y][x]+20) {
          move = 100;
        }
        if (dist[y][x]+wait+move < dist[ny][nx]) {
          dist[ny][nx] = dist[y][x]+wait+move;
          pq.push(pair<int, PII>(dist[ny][nx], PII(ny, nx)));
        }
      }
    }
    cout << "Case #" << ca << ": " << double(dist[n-1][m-1])/10.0 << endl;
  }
}
