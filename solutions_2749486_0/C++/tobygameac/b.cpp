#include <cstdio>
#include <queue>
#include <string>
#include <set>
using namespace std;

struct State {
  State (int x, int y, int m, string s) : x(x), y(y), move(m), path(s) {}
  int x, y, move;
  string path;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
string d[4] = {"N", "S", "W", "E"};

int main() {
  int T, C = 1;
  scanf("%d", &T);
  while (T--) {
    int x, y;
    scanf("%d%d", &x, &y);
    queue<State> q;
    q.push(State(0, 0, 1, ""));
    string ans;
    set<pair<pair<int, int>, int> > visited;
    while (!q.empty()) {
      State now = q.front();
      q.pop();
      if (now.x == x && now.y == y) {
        ans = now.path;
        break;
      }
      int add = now.move;
      for (int i = 0; i < 4; i++) {
        int newX = now.x + dx[i] * add, newY = now.y + dy[i] * add;
        if (!visited.count(make_pair(make_pair(newX, newY), add + 1))) {
          visited.insert(make_pair(make_pair(newX, newY), add + 1));
          q.push(State(newX, newY, add + 1, now.path + d[i]));
        }
      }
    }
    printf("Case #%d: %s\n", C++, ans.c_str());
  }
  return 0;
}
