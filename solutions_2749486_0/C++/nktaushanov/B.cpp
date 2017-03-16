/*
ID: nigo1
LANG: C++
TASK: B
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

int T;

bool used[1024][1024];

void set(int x, int y) {
  used[x + 500][y + 500] = 1;
}

bool get(int x, int y) {
  return used[x + 500][y + 500];
}

int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string dir = "NSEW";

pair<int, int> prev[1024][1024];
char used_dir[1024][1024];

void bfs(int x, int y) {
  memset(used, 0, sizeof used);

  queue<int> que;
  que.push(0);
  que.push(0);
  int lvl = 1, p = 0;

  while(!que.empty()) {
    p = que.size()/2;
    while (p--) {
      int _x = que.front();
      que.pop();
      int _y = que.front();
      que.pop();
      if (_x == x && y == _y) break;

      for (int m = 0; m < 4; m++) {
        int newx = _x + moves[m][0]*lvl;
        int newy = _y + moves[m][1]*lvl;

        if (newx + 500 < 0 || newx + 500 > 1000) continue;
        if (newy + 500 < 0 || newy + 500 > 1000) continue;

        if (get(newx, newy)) continue;
        prev[newx + 500][newy + 500] = make_pair(_x, _y);
        used_dir[newx + 500][newy + 500] = dir[m];

        set(newx, newy);
        que.push(newx);
        que.push(newy);
      }
    }
    lvl++;
  }
  if (!get(x, y)) {
    printf("\n");
    return;
  }

  stack<char> st;
  int cnt = 0;
  while (x != 0 || y != 0) {
    st.push(used_dir[x + 500][y + 500]);
    int newx, newy;
    newx = prev[x + 500][y + 500].first;
    newy = prev[x + 500][y + 500].second;
    x = newx, y = newy;
  }

  while(!st.empty()) {
    printf("%c", st.top());
    st.pop();
  }
  printf("\n");
}

int main()
{
  //freopen ("B.in", "r", stdin);
  //freopen ("B.out", "w", stdout);

  scanf("%d", &T);
  for (int test = 1; test <= T; test++) {
    int x, y;
    scanf("%d%d", &x, &y);

    printf("Case #%d: ", test);
    bfs(x, y);
  }

  return 0;
}
