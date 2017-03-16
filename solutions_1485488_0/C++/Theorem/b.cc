#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <map>

using namespace std;

struct cell{ int top, bottom; };

struct state {
  int i;
  int j;
  double seconds;
  state (int _i, int _j, double _seconds) : i(_i), j(_j), seconds(_seconds) { }
  bool operator< (const state& o) const {
    if (seconds != o.seconds) return seconds > o.seconds;
    if (i != o.i) return i < o.i;
    return j < o.j;
  }
};

cell grid [1000][1000];

void solve (int a_case)
{
  int H, N, M;
  cin >> H >> N >> M;

  for (int i = 0; i < 1000; ++i) for (int j = 0; j < 1000; ++j) grid[i][j].top = grid[i][j].bottom = 0;

  for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> grid[i+1][j+1].top;
  for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> grid[i+1][j+1].bottom;

  priority_queue<state> q;
  set<state> visited;

  q.push(state(1, 1, 0.0));

  int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  while (q.empty() == false) {
    state x = q.top(); q.pop();

    if (visited.find(x) != visited.end()) continue;
    visited.insert(x);

    if (x.i == N && x.j == M) {
      printf("Case #%d: %lf\n", a_case, x.seconds);
      return;
    }


    for (int i = 0; i < 4; ++i) {
      int wi = x.i + d[i][0];
      int wj = x.j + d[i][1];

      cell& c = grid[x.i][x.j];
      cell& w = grid[wi][wj];
      double WL = std::max(0.0, H - 10 * x.seconds);

      if (c.bottom <= w.top - 50 &&
          w.bottom <= w.top - 50 &&
          w.bottom <= c.top - 50) {

        double wait_cost = 0;
        if (WL <= w.top - 50) wait_cost = 0;
        else wait_cost = (WL - (w.top - 50)) / 10.0;

        int travel_cost = 0;
        if (c.bottom <= WL - 20) travel_cost = 1;
        else travel_cost = 10;

        if (x.seconds == 0 && wait_cost == 0) {
          q.push(state(wi, wj, x.seconds));
        } else {
          q.push(state(wi, wj, travel_cost + wait_cost + x.seconds));
        }
      }
    }
  }


  printf("Case #%d: Dunno\n", a_case);
}

int main ()
{
  int n;
  string dummy;

  cin >> n;
  getline(cin, dummy);
  for (int i = 0; i < n; ++i) solve(i+1);

  return 0;
}

