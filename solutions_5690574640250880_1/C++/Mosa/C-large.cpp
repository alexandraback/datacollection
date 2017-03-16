// I have no idea what i'm doing,
// I have no idea what i'm doing... :D
#include <bits/stdc++.h>

using namespace std;

int r, c;
char g[55][55];
bool vis[55][55];
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
  freopen("C-large.in", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  int t; scanf("%d", &t);
  for(int tst = 1; tst <= t; ++tst) {
    printf("Case #%d:\n", tst);
    int m;
    scanf("%d %d %d", &r, &c, &m);
    if(r * c - m == 1) {
      for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c - 1; ++j) putchar('*');
        if(i == r - 1) putchar('c');
        else putchar('*');
        putchar('\n');
      }
      continue;
    }
    for(int rcnt = 0; rcnt < r; ++rcnt) {
      for(int ccnt = 0; ccnt < c; ++ccnt) {
        int tot = rcnt * c + ccnt * r - rcnt * ccnt;
        if(tot > m) continue;
        int rem = m - tot;
        int rc = r - rcnt + c - ccnt - 1;
        if(rem >= rc) continue;
        memset(g, '.', sizeof g);
        for(int i = 0; i < rcnt; ++i)
          for(int j = 0; j < c; ++j) g[i][j] = '*';
        for(int j = 0; j < ccnt; ++j)
          for(int i = 0; i < r; ++i) g[i][j] = '*';
        for(int offset = 0; offset + rem <= rc; ++offset) {
          for(int i = offset; i < offset + rem; ++i) {
            if(i < r - rcnt) g[r - i - 1][ccnt] = '*';
            else g[rcnt][ccnt + i - r + rcnt + 1] = '*';
          }
          if(g[r - 1][c - 1] == '*') continue;
          memset(vis, 0, sizeof vis);
          int cnt = 0;
          for(int k = 0; k < 8; ++k) {
            int ni = r - 1 + di[k];
            int nj = c - 1 + dj[k];
            if(ni < 0 || ni >= r || nj < 0 || nj >= c || g[ni][nj] == '.')
              ++cnt;
          }
          if(cnt == 8) {
            g[r - 1][c - 1] = 'c';
            dfs(r - 1, c - 1);
            bool valid = 1;
            for(int ii = 0; ii < r && valid; ++ii) {
              g[ii][c] = 0;
              for(int jj = 0; jj < c && valid; ++jj) {
                if(g[ii][jj] == '.' && !vis[ii][jj]) valid = 0;
              }
            }
            if(valid) {
              for(int ii = 0; ii < r; ++ii) puts(g[ii]);
              goto done;
            }
          }
          for(int i = offset; i < offset + rem; ++i) {
            if(i < r - rcnt) g[r - i - 1][ccnt] = '.';
            else g[rcnt][ccnt + i - r + rcnt + 1] = '.';
          }
        }
      }
    }
    puts("Impossible");
    done:;
  }
  return 0;
}
