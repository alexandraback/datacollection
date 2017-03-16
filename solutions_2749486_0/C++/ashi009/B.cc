#include <iostream>
#include <vector>

using namespace std;

vector<char> trace;

char dirNames[4] = {'E', 'N', 'W', 'S'};
int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int tx, ty;

bool dfs(int cx, int cy, int dst, int maxd) {
  // cout << cx << ' ' << cy << endl;
  if (cx == tx && cy == ty)
    return true;
  if (dst > maxd)
    return false;
  int range = (maxd + dst) * (maxd - dst + 1) / 2;
  if (cx + range < tx || cx - range > tx || cy + range < ty || cy - range > ty)
    return false;
  for (int i = 0; i < 4; i++) {
    trace.push_back(dirNames[i]);
    if (dfs(cx + dirs[i][0] * dst, cy + dirs[i][1] * dst, dst + 1, maxd))
      return true;
    trace.pop_back();
  }
  return false;
}

int main() {
  int T;
  cin >> T;
  for (int CASE = 1; CASE <= T; CASE++) {
    cin >> tx >> ty;
    for (int maxd = 1; maxd <= 500; maxd++) {
      trace.clear();
      if (dfs(0, 0, 1, maxd))
        break;
    }
    cout << "Case #" << CASE << ": ";
    for (char ch : trace)
      cout << ch;
    cout << endl;
  }
}
