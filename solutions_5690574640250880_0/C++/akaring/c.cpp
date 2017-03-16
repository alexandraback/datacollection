#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void checkMin(T &a, T b) { if(b<a) a=b; }
template<typename T> inline void checkMax(T &a, T b) { if(a<b) a=b; }
#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for (int i=0;i<int(n);++i)
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MAX_N = 64;

int R, C, M;
int mp[MAX_N][MAX_N];
char str[MAX_N][MAX_N];

const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

void dfs(bool vis[MAX_N][MAX_N], int i, int j) {
  vis[i][j] = true;
  if (mp[i][j] != 0) {
    return;
  }
  REP (k, 8) {
    int x = i + dx[k], y = j + dy[k];
    if (0 <= x && x < R && 0 <= y && y < C && !vis[x][y] && mp[x][y] >= 0) {
      dfs(vis, x, y);
    }
  }
}

bool check() {
  REP (i, R) {
    REP (j, C) {
      if (mp[i][j] >= 0) {
        bool vis[MAX_N][MAX_N] = {};
        dfs(vis, i, j);
        if (accumulate(vis[0], vis[MAX_N], 0) + M == R * C) {
          str[i][j] = 'c';
          return true;
        }
      }
    }
  }
  return false;
}

void build(int mask) {
  fill(mp[0], mp[MAX_N], -1);
  REP (i, R) {
    REP (j, C) {
      int o = i * C + j;
      if ((mask >> o) & 1) {
        str[i][j] = '*';
      } else {
        mp[i][j] = 0;
        str[i][j] = '.';
      }
    }
    str[i][C] = '\0';
  }
  REP (i, R) {
    REP (j, C) {
      if (mp[i][j] == 0) {
        int adj = 0;
        REP (k, 8) {
          int x = i + dx[k], y = j + dy[k];
          if (0 <= x && x < R && 0 <= y && y < C && mp[x][y] == -1) {
            ++adj;
          }
        }
        mp[i][j] = adj;
      }
    }
  }
}

bool gao() {
  REP (mask, 1 << (R * C)) {
    if (__builtin_popcount(mask) != M) {
      continue;
    }
    build(mask);
    if (check()) {
      REP (i, R) {
        printf("%s\n", str[i]);
      }
      return true;
    }
  }
  return false;
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    scanf("%d%d%d", &R, &C, &M);
    printf("Case #%d:\n", index);
    if (!gao()) {
      printf("Impossible\n");
    }
  }
  return 0;
}
