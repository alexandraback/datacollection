#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <cmath>

using namespace std;

typedef struct state {
  int x, y, step, dist, prevdir;
  state(int ix, int iy, int is, int id, int pd)
    : x(ix), y(iy), step(is), dist(id), prevdir(pd) { }
  bool operator<(const struct state rhs) const {
    if (step != rhs.step) return step > rhs.step;
    return dist > rhs.dist;
  }
} state;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

ostream& operator<<(ostream& os, const state& rhs) {
  return os << "(" << rhs.x << ", " << rhs.y << ", "
	    << rhs.step << ", " << rhs.dist << ", " << rhs.prevdir << ")";
}

string getroad(map<pair<int, int>, pair<int, int> >& memo,
	       pair<int, int> pos)
{
  string ans;
  const char dstr[] = "ESWN";
  // (0, 0)でない間...
  while (pos.first != 0 || pos.second != 0) {
    int step = memo[pos].first;
    int dir  = memo[pos].second;
    cerr << "(x:" << pos.first << ", y:" << pos.second << ", s:" << step << ", d:" << dir << ")";
    ans += dstr[dir];
    pos.first -= step * dx[dir];
    pos.second -= step * dy[dir];
    cerr << " --> (x:" << pos.first << ", y:" << pos.second << ")" << endl;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

string solve(int gx, int gy)
{
  // pos(x,y) -> (cost,prev)
  map<pair<int, int>, pair<int, int> > memo;

  priority_queue<state> que;
  que.push(state(0, 0, 0, abs(gx) + abs(gy), 0));
  
  while (!que.empty()) {
    const state cur = que.top();
    que.pop();

    //cerr << cur << endl;
    
    pair<int, int> pos = make_pair(cur.x, cur.y);
    if (memo.find(pos) != memo.end()) continue;
    memo[pos] = make_pair(cur.step, cur.prevdir);
    
    if (cur.x == gx && cur.y == gy) {
      // goal
      return getroad(memo, make_pair(gx, gy));
    }
    
    // move
    for (int i = 0; i < 4; ++i) {
      int nx = cur.x + (cur.step + 1) * dx[i];
      int ny = cur.y + (cur.step + 1) * dy[i];
      if (abs(nx) > 100000 || abs(ny) > 100000) continue;
      que.push(state(nx, ny, cur.step + 1, abs(gx - nx) + abs(gy - ny), i));
    }
  }
  
  return "\(o_o)/";
}

int main()
{
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; ++cs) {
    int gx, gy;
    cin >> gx >> gy;

    string ans = solve(gx, gy);
    cout << "Case #" << cs << ": " << ans << endl;
  }
  
  return 0;
}
