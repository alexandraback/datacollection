#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int INF = INT_MAX/4;
const int MAXN = 105;

struct State {
  int y, x;
};

int& ceiling(const State &s) { static int m[MAXN][MAXN]; return m[s.y][s.x]; }
int& floor(const State &s) { static int m[MAXN][MAXN]; return m[s.y][s.x]; }
int& colour(const State &s) { static int m[MAXN][MAXN]; return m[s.y][s.x]; }
int& earliest(const State &s) { static int m[MAXN][MAXN]; return m[s.y][s.x]; }
int& dist(const State &s) { static int m[MAXN][MAXN]; return m[s.y][s.x]; }

bool operator<(const State &s1, const State &s2) {
  if (dist(s1) != dist(s2)) return dist(s1) < dist(s2);
  if (s1.y != s2.y) return s1.y < s2.y;
  return s1.x < s2.x;
}

int initial_water, R, C;

double solve() {
  State s;
  for (s.y=0; s.y<R; ++s.y) {
    for (s.x=0; s.x<C; ++s.x) {
      colour(s) = 0;
      if (ceiling(s) - floor(s) < 50) {
        earliest(s) = INF;
      } else {
        earliest(s) = max(0, 50 + initial_water - ceiling(s));
      }
    }
  }

  set<State> pq;
  State start = {0, 0}, end = {R-1, C-1};
  dist(start) = 0;
  colour(start) = 1;
  pq.insert(start);
  while (!pq.empty()) {
    State curr = *pq.begin(); pq.erase(pq.begin());
    colour(curr) = 2;

    if (curr.x == end.x && curr.y == end.y) {
      return 0.1 * dist(end);
    }

    static const int dy[] = {-1, 0, 1, 0};
    static const int dx[] = {0, 1, 0, -1};
    for (int dir=0; dir<4; ++dir) {
      State next = {curr.y + dy[dir], curr.x + dx[dir]};
      if (next.y < 0 ||
          next.y >= R ||
          next.x < 0 ||
          next.x >= C ||
          colour(next) == 2) {
        continue;
      }

      if (floor(curr) + 50 > ceiling(next) ||
          floor(next) + 50 > ceiling(curr)) {
        continue;
      }

      int tstart = max(dist(curr), earliest(next));
      int tmove;
      if (tstart == 0) {
        tmove = 0;
      } else if (initial_water - tstart - floor(curr) >= 20) {
        tmove = 10;
      } else {
        tmove = 100;
      }
      if (colour(next) == 1) {
        if (dist(next) <= tstart + tmove) {
          continue;
        }
        pq.erase(next);
      }
      dist(next) = tstart + tmove;
      colour(next) = 1;
      pq.insert(next);
    }
  }
  abort();
}

int main() {
  cin.sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    cin >> initial_water >> R >> C;
    State s;
    for (s.y=0; s.y<R; ++s.y) {
      for (s.x=0; s.x<C; ++s.x) {
        cin >> ceiling(s);
      }
    }
    for (s.y=0; s.y<R; ++s.y) {
      for (s.x=0; s.x<C; ++s.x) {
        cin >> floor(s);
      }
    }
    printf("Case #%d: %.1f\n", tt, solve());
  }  
  
  return 0;
}
