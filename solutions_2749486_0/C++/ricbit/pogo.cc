#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <set>
#include <string>

using namespace std;

typedef pair<int, int> pii;

struct state {
  int cost;
  int step;
  int x, y;
  string path;
  bool operator<(const state& s) const {
    return cost > s.cost;
  }
};

struct Search {
  Search(int x, int y): gx(x), gy(y) {}

  state new_state(int x, int y, int cost, int step, string path) {
    state s;
    s.x = x;
    s.y = y;
    s.cost = cost;
    s.step = step;
    s.path = path;
    return s;
  }

  string search() {
    priority_queue<state> next;
    state start = new_state(0, 0, 0, 1, "");
    next.push(start);
    while (!next.empty()) {
      state st = next.top();
      next.pop();
      pii pos = make_pair(st.x, st.y);
      if (memo.find(pos) != memo.end()) {
        continue;
      }
      //printf ("%d %d: %d, %d, %s\n",st.x,st.y,st.cost,st.step,st.path.c_str());
      memo[make_pair(st.x, st.y)] = make_pair(st.cost, st.path);
      int dx[] = {1, -1, 0, 0};
      int dy[] = {0, 0, 1, -1};
      char dir[] = "EWNS";
      for (int i = 0; i < 4; i++) {
        int nx = st.x + dx[i] * st.step;
        int ny = st.y + dy[i] * st.step;
        if (memo.find(make_pair(nx, ny)) == memo.end()) {
          //printf("GOAL %d %d : %d %d\n",st.x,st.y,gx,gy);
          if (nx == gx && ny == gy) {
            return st.path + dir[i];
          }
          next.push(new_state(nx, ny, st.cost + st.step, 
                              st.step + 1, st.path + dir[i]));
        }
      }
    }
    return "";
  }
  int gx, gy;
  map<pii, pair<int, string> > memo;
};

int main() {
  int tc;
  scanf("%d", &tc);
  for (int tci = 1; tci <= tc; tci++) {
    int x,y;
    scanf("%d", &x);
    scanf("%d", &y);
    Search s(x, y);
    string ans = s.search();
    printf("Case #%d: %s\n", tci, ans.c_str());
  }
  return 0;
}
