#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct State {
  vector<int> v;
  int size, len;
};

int main() {
  int T, C = 1;
  scanf("%d", &T);
  while (T--) {
    int a, n;
    scanf("%d%d", &a, &n);
    vector<int> num;
    for (int i = 0, j; i < n; i++) {
      scanf("%d", &j);
      num.push_back(j);
    }
    sort(num.begin(), num.end());
    State state;
    state.v = num;
    state.size = a;
    state.len = 0;
    queue<State> q;
    q.push(state);
    int ans = 2e9;
    while (!q.empty()) {
      vector<int> now = q.front().v;
      int size = q.front().size, len = q.front().len;
      q.pop();
      if (!now.size()) {
        ans = len < ans ? len : ans;
        continue;
      }
      State temp;
      temp.v = now;
      temp.len = len;
      if (size > now[0]) {
        temp.v.erase(temp.v.begin());
        temp.size = size + now[0];
        q.push(temp);
      } else {
        temp.len = len + 1;
        if (size > 1) {
          temp.size = size + size - 1;
          q.push(temp);
        }
        temp.size = size;
        temp.v.erase(temp.v.begin());
        q.push(temp);
      }
    }
    printf("Case #%d: %d\n", C++, ans);
  }
  return 0;
}
