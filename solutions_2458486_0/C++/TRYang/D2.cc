#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::swap;

const int kMAXN = 410;

int keys[kMAXN][kMAXN], hold[kMAXN][kMAXN];
int keys_num[kMAXN];
int need[kMAXN];
int tag[kMAXN];
int n, m;
vector<int> ans;

int match[kMAXN];
int vis[kMAXN];
int debug;
int change(int x) {
  for (int i = 0; i <= n; i++) {
    if (tag[i] || !vis[i]) continue;
    for (int j = 0; j < keys_num[i]; j++)
      if (keys[i][j] == need[x] && hold[i][j] == -1) {
        hold[i][j] = x;
        match[x] = i;
        return 1;
      }
  }
  return 0;
}
int dd[kMAXN];
int find(int x) {
  if (x == 0 || match[x] != -1) return 1;
  if (dd[x]) return 0;
  dd[x] = 1;
  vis[x] = 1;
  for (int i = 0; i <= n; i++) {
    if (tag[i] || vis[i]) continue;
//    printf("%d %d\n", x, i);
    for (int j = 0; j < keys_num[i]; j++)
      if (keys[i][j] == need[x] && hold[i][j] == -1) {
        if (find(i)) {
          hold[i][j] = x;
          match[x] = i;
          return 1;
        }
      }
  }
  for (int i = 0; i <= n; i++) {
    if (tag[i] || vis[i]) continue;
    for (int j = 0; j < keys_num[i]; j++)
      if (keys[i][j] == need[x]) {
        if (!change(hold[i][j])) return 0;
        hold[i][j] = x;
        match[x] = i;
        return 1;
      }
  }
  return 0;
}
int check() {
  memset(match, -1, sizeof match);
  memset(hold, -1, sizeof hold);
  for (int i = 1; i <= n; i++) {
    if (tag[i] || match[i] != -1) continue;
    memset(vis, 0, sizeof vis);
    memset(dd, 0, sizeof dd);
//    if (debug) printf("%d\n", i);
    if (!find(i)) return 0;
  }
  return 1;
}
int main() {
  int T, cp = 0;
  for (scanf("%d", &T); T; T--) {
    scanf("%d%d", keys_num, &n);
    m = 0;
    for (int i = 0; i < keys_num[0]; i++) {
      scanf("%d", keys[0] + i);
      m = max(m, keys[0][i]);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", need + i, keys_num + i);
      for (int j = 0; j < keys_num[i]; j++) {
        scanf("%d", keys[i] + j);
        m = max(m, keys[i][j]);
      }
    }
//          for (int c = 0; c <= n; c++) {
//            printf("c = %d : ", c);
//            for (int d = 0; d < keys_num[c]; d++) printf(" %d", keys[c][d]);puts("");
//          }
    memset(tag, 0, sizeof tag);
    int flag = check();
    ans.clear();
//    printf("%d\n", flag);
    debug = 0;
    for (int k = 0; k < n && flag; k++) {
      flag = 0;
      for (int i = 1; i <= n; i++) {
        if (tag[i]) continue;
        int p = -1;
        for (int j = 0; j < keys_num[0]; j++)
          if (keys[0][j] == need[i]) p = j;
        if (p == -1) continue;
        swap(keys[0][keys_num[0] - 1], keys[0][p]);
        keys_num[0]--;

        for (int j = 0; j < keys_num[i]; j++) keys[0][keys_num[0]++] = keys[i][j];

//        if (k == 1) {
//          printf("i = %d\n", i);
//          for (int c = 0; c <= n; c++) {
//            printf("c = %d : ", c);
//            for (int d = 0; d < keys_num[c]; d++) printf(" %d", keys[c][d]);puts("");
//          }
//        }
//        if (k == 1 && i == 1) debug = 1;
        tag[i] = 1;
        if (check()) {
//          printf("%d %d\n", k, i);
          keys_num[i] = 0;
          ans.push_back(i);
          flag = 1;
          break;
        }
        tag[i] = 0;
//        if (k == 1 && i == 1) debug = 0;

        keys_num[0] -= keys_num[i];

        keys[0][keys_num[0]++] = need[i];
      }
    }
    printf("Case #%d:", ++cp);
    if (flag) {
      for (int i = 0; i < ans.size(); i++) printf(" %d", ans[i]);
      puts("");
    } else puts(" IMPOSSIBLE");
  }
  return 0;
}
