#include <iostream>
#include <queue>
#include <set>

using namespace std;

#define INF 10000000.0;
#define C_TO_IND(x, y) ((x) * m + (y))
#define X(index) ((index) / m)
#define Y(index) ((index) % m)
#define GOAL C_TO_IND(n-1, m-1)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

struct cell {
  int c, f; // ceiling, floor
};

struct item {
  item(int c_, double t_) : c(c_), t(t_) {}
  int c; //cell
  double t; //time
};

class mycomparison {
public:
  bool operator() (const item& lhs, const item&rhs) const { return lhs.t > rhs.t; }
};

int h, n, m;
cell map[100][100];

double min_time(double curr_time, int x1, int y1, int x2, int y2) {
  if (map[x1][y1].f + 50 > map[x2][y2].c) return INF;
  if (map[x2][y2].f + 50 > map[x2][y2].c) return INF;
  if (map[x2][y2].f + 50 > map[x1][y1].c) return INF;
  int max_water = map[x2][y2].c - 50;
  double water_time = (h - max_water) / 10.0;
  if (water_time <= 0 && curr_time <= 0) return 0; // can start there
  if (water_time > curr_time) {
    curr_time = water_time; // wait
  }
  int curr_water = h - 10.0 * curr_time;
  if (curr_water >= map[x1][y1].f + 20) return curr_time + 1.0;
  else return curr_time + 10.0;
}

int main() {
  int t; cin >> t;
  for (int ii = 1; ii <= t; ++ii) {
    cin >> h >> n >> m;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> map[i][j].c;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> map[i][j].f;
      }
    }

    priority_queue<item, vector<item>, mycomparison> pq;
    set<int> visited;
    pq.push(item(C_TO_IND(0,0), 0.0));
    while (!pq.empty()) {
      item curr = pq.top(); pq.pop();
      if (visited.count(curr.c)) continue;
      if (curr.c == GOAL) {
        printf("Case #%d: %f\n", ii, curr.t);
        break;
      }

      visited.insert(curr.c);
      int x = X(curr.c); int y = Y(curr.c);

      if (x > 0) {
        pq.push(item(C_TO_IND(x - 1, y), min_time(curr.t, x, y, x - 1, y)));
      }
      if (y > 0) {
        pq.push(item(C_TO_IND(x, y - 1), min_time(curr.t, x, y, x, y - 1)));
      }
      if (x < n - 1) {
        pq.push(item(C_TO_IND(x + 1, y), min_time(curr.t, x, y, x + 1, y)));
      }
      if (y < m - 1) {
        pq.push(item(C_TO_IND(x, y + 1), min_time(curr.t, x, y, x, y + 1)));
      }
    }
  }
  return 0;
}