#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 123456;

int R, C, W;

map<vector<int>, int> mp[11][11];

int dfs(vector<int>& vec, int turn, int y) {
  if (turn == 0) {
    if (mp[C][W].count(vec)) {
      return mp[C][W][vec];
    }
    int ways = 0;
    int total = 0;
    for (int i = 0; i < vec.size(); ++i) {
      if (vec[i] == 1) {
        ++total;
      }
    }
    for (int i = 0; i <= C - W; ++i) {
      bool can = true;
      int cnt = 0;
      for (int j = 0; j < W; ++j) {
        if (vec[i + j] == 2) {
          can = false;
          break;
        } else if (vec[i + j] == 1) {
          ++cnt;
        }
      }
      if (can && cnt == total) ++ways;
    }
    if (ways > 0 && total == W) {
      return 0;
    }
    int ret = INT_MAX;
    for (int i = 0; i < C; ++i) {
      if (vec[i] == 0) {
        vector<int> tmp = vec;
        ret = min(ret, dfs(tmp, 1 - turn, i) + 1);
      }
    }
    return mp[C][W][vec] = ret;
  } else {
    int ret = 0;
    int total = 0;
    for (int i = 0; i < vec.size(); ++i) {
      if (vec[i] == 1) {
        ++total;
      }
    }
    for (int i = 0; i <= C - W; ++i) {
      bool can = true;
      int cnt = 0;
      for (int j = 0; j < W; ++j) {
        if (vec[i + j] == 2) {
          can = false;
          break;
        } else if (vec[i + j] == 1) {
          ++cnt;
        }
      }
      if (can && cnt == total) {
        vector<int> tmp = vec;
        // for (int j = 0; j < W; ++j) {
        //   tmp[i + j] = 1;
        // }
        tmp[y] = (y >= i && y < i + W) ? 1 : 2;
        ret = max(ret, dfs(tmp, 1 - turn, 0));
      }
    }
    return ret;
  }
}

int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 1; T <= cases; ++T) {
    int ans = 0;
    scanf("%d %d %d", &R, &C, &W);
    vector<int> vec(C);
    ans = dfs(vec, 0, 0);
    printf("Case #%d: %d\n", T, ans);
  }
}