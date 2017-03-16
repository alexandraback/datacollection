#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef DBG12
    #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#else
    #define dbg(...)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

struct Point {
  int x, y;

  Point(int x, int y) : x(x), y(y) {}

  bool operator < (const Point & p) const {
    if (x != p.x) {
      return x < p.x;
    }
    return y < p.y;
  }

  bool operator == (const Point & p) const {
    return x == p.x && y == p.y;
  }
};

struct N_omino {
  vector <Point> p;

  N_omino(const vector <Point> & p) : p(p) {
    assert(checkAndNormalize());
  }

  bool checkAndNormalize() {
    vector <Point> p = this->p;
    sort(p.begin(), p.end());
    if (unique(p.begin(), p.end()) != p.end()) {
      return false;
    }
    vector <Point> minLex;
    for (int rot = 0; rot < 4; ++rot) {
      for (int refl = 0; refl < 2; ++refl) {
        sort(p.begin(), p.end());
        for (int i = int(p.size()) - 1; i >= 0; --i) {
          p[i].x -= p[0].x;
          p[i].y -= p[0].y;
        }
        if (minLex.empty() || p < minLex) {
          minLex = p;
        }
        for (int i = 0; i < int(p.size()); ++i) {
          swap(p[i].x, p[i].y);
        }
      }
      for (int i = 0; i < int(p.size()); ++i) {
        swap(p[i].x, p[i].y);
        p[i].x = -p[i].x;
      }
    }
    this->p = minLex;
    return true;
  }

  void print() const {
    for (int i = 0; i < int(p.size()); ++i) {
      dbg("(%d,%d) ", p[i].x, p[i].y);
    }
    dbg("\n");
  }

  bool operator < (const N_omino & o) const {
    assert(p.size() == o.p.size());
    return p < o.p;
  }
};

const int MAX = 6;
set<N_omino> all[MAX + 1];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y, int n, int m, vector < vector <int> > & a) {
  if (!(0 <= x && x < n && 0 <= y && y < m)) {
    return 0;
  }
  if (a.at(x).at(y) != 0) {
    return 0;
  }
  a[x][y] = 1;
  int cnt = 1;
  for (int i = 0; i < 4; ++i) {
    cnt += dfs(x + dx[i], y + dy[i], n, m, a);
  }
  return cnt;
}

bool solve(int size, int n, int m) {
  if (size > MAX) {
    return false;
  }
  for (const N_omino & f : all[size]) {
    bool win = false;
    for (int refl = 0; refl < 2; ++refl) {
      for (int x0 = 0; x0 < n; ++x0) {
        for (int y0 = 0; y0 < m; ++y0) {
          vector < vector <int> > a(n, vector <int> (m, 0));
          dbg("x0 = %d, y0 = %d\n", x0, y0);
          bool ok = true;
          for (int i = 0; i < size; ++i) {
            int x = f.p[i].x + x0;
            int y = f.p[i].y + y0;
            if (0 <= x && x < n && 0 <= y && y < m) {
              a[x][y] = -1;
            } else {
              ok = false;
            }
          }
          for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
              if (a[x][y] == 0) {
                ok &= (dfs(x, y, n, m, a) % size == 0);
              }
            }
          }
          win |= ok;
        }
      }
      swap(n, m);
    }
    if (!win) {
      return false;
    }
  }
  return true;
}

void solve() {
  int x, n, m;
  assert(scanf("%d%d%d", &x, &n, &m) == 3);
  printf("%s\n", solve(x, n, m) ? "GABRIEL" : "RICHARD");
  fflush(stdout);
}

int main()
{
  all[1].insert(N_omino(vector<Point>(1, Point(0, 0))));
  for (int i = 2; i <= MAX; ++i) {
    for (const N_omino & x : all[i - 1]) {
      for (int j = 0; j < int(x.p.size()); ++j) {
        for (int k = 0; k < 4; ++k) {
          N_omino copyX = x;
          copyX.p.push_back(Point(x.p[j].x + dx[k], x.p[j].y + dy[k]));
          if (copyX.checkAndNormalize()) {
            all[i].insert(copyX);
          }
        }
      }
    }
    dbg("%d: %d\n", i, (int)all[i].size());
  }

  int tt;
  assert(scanf("%d", &tt) == 1);
  for (int ii = 1; ii <= tt; ++ii) {
    printf("Case #%d: ", ii);
    solve();
  }

  return 0;
}

