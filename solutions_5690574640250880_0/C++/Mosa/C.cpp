#include <bits/stdc++.h>

using namespace std;

int r, c;
char g[9][9];
bool vis[9][9];
int di[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dj[] = {1, -1, 0, 0, 1, -1, 1, -1};

void dfs(int i, int j) {
  for(int k = 0; k < 8; ++k) {
    int ni = i + di[k];
    int nj = j + dj[k];
    if(ni < 0 || ni >= r || nj < 0 || nj >= c || vis[ni][nj] || g[ni][nj] == '*') continue;
    vis[ni][nj] = 1;
    int cnt = 0;
    for(int kk = 0; kk < 8; ++kk) {
      int nni = ni + di[kk];
      int nnj = nj + dj[kk];
      if(nni < 0 || nni >= r || nnj < 0 || nnj >= c || g[nni][nnj] != '*') ++cnt;
    }
    if(cnt == 8)
      dfs(ni, nj);
  }
}

int main() {
  freopen("C-small-attempt1.in", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  int t; scanf("%d", &t);
  for(int tst = 1; tst <= t; ++tst) {
    printf("Case #%d:\n", tst);
    int m;
    scanf("%d %d %d", &r, &c, &m);
    int n = r * c;
    if(n - m == 1) {
      for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c - 1; ++j) putchar('*');
        if(i == r - 1) putchar('c');
        else putchar('*');
        putchar('\n');
      }
      continue;
    }
    for(int msk = 0; msk < (1 << n); ++msk) {
      if(__builtin_popcount(msk) != m) continue;
      memset(g, '.', sizeof g);
      for(int i = 0; i < n; ++i) if((msk >> i) & 1) g[i / c][i % c] = '*';
      for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j) if(g[i][j] != '*') {
          int cnt = 0;
          for(int k = 0; k < 8; ++k) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if(ni < 0 || ni >= r || nj < 0 || nj >= c || g[ni][nj] == '.')
              ++cnt;
          }
          if(cnt == 8) {
            memset(vis, 0, sizeof vis);
            g[i][j] = 'c';
            dfs(i, j);
            for(int ii = 0; ii < r; ++ii) {
              g[ii][c] = 0;
              for(int jj = 0; jj < c; ++jj) {
                if(g[ii][jj] == '.' && !vis[ii][jj]) goto next;
              }
            }
            for(int ii = 0; ii < r; ++ii) puts(g[ii]);
            goto done;
          }
        }
      next:;
    }
    puts("Impossible");
    done:;
  }
  return 0;
}
