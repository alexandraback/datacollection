#include <cstdio>
#include <cstring>
#include <cassert>

char mp[64][64];
int R, C, M, empty;

const int dir[][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int cc[64][64], q[64*64][2], tk[64][64];
inline bool in(int x, int y) {
  return x >= 0 && x < R && y >= 0 && y < C;
}
int verify() {
  for (int i = 0 ; i < R ; ++i)
    for (int j = 0 ; j < C ; ++j) {
      int cnt = 0;
      for (int d = 0 ; d < 8 ; ++d) {
        int ti = i + dir[d][0];
        int tj = j + dir[d][1];
        if (in(ti,tj) && mp[ti][tj] == '*') ++cnt;
      }
      cc[i][j] = cnt;
    }
  memset(tk, 0, sizeof(tk));
  q[0][0] = 0; q[0][1] = 0; tk[0][0] = 1;
  int qh, qt;
  for (qh = 0, qt = 1 ; qh < qt ; ++qh) {
    int x = q[qh][0], y = q[qh][1];
    assert(mp[x][y] != '*');
    if (cc[x][y] == 0) {
      for (int d = 0 ; d < 8 ; ++d) {
        int tx = x + dir[d][0];
        int ty = y + dir[d][1];
        if (!in(tx,ty) || tk[tx][ty]) continue;
        tk[tx][ty] = 1;
        q[qt][0] = tx; q[qt][1] = ty;
        ++qt;
      }
    }
  }
  return qh == empty;
}

int tryR() {
  for (int er = 2 ; er <= R ; ++er) {
    int ec = (empty + er - 1) / er;
    if (ec > C) continue;
    if (empty % er == 1) continue;
    if (empty / er <= 1) continue;
    // printf("er:%d ec:%d\n", er, ec);
    for (int i = 0 ; i < R ; ++i)
      for (int j = 0 ; j < C ; ++j) {
        int tmp = j * er + i;
        if (i < er && tmp < empty) mp[i][j] = '.';
        else mp[i][j] = '*';
      }
    mp[0][0] = 'c';
    return 1;
  }
  return 0;
}

int tryC() {
  for (int ec = 2 ; ec <= C ; ++ec) {
    int er = (empty + ec - 1) / ec;
    if (er > R) continue;
    if (empty % ec == 1) continue;
    if (empty / ec <= 1) continue;
    // printf("er:%d ec:%d\n", er, ec);
    for (int i = 0 ; i < C ; ++i)
      for (int j = 0 ; j < R ; ++j) {
        int tmp = j * ec + i;
        if (i < ec && tmp < empty) mp[j][i] = '.';
        else mp[j][i] = '*';
      }
    mp[0][0] = 'c';
    return 1;
  }
  return 0;
}

int main() {
  int T;
  scanf("%d",&T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    scanf("%d%d%d", &R, &C, &M);
    printf("Case #%d:\n", ca);
    empty = R * C - M;
    int flg = 0;
    if (R == 1 || C == 1) {
      int tmp = 0;
      for (int i = 0 ; i < R ; ++i)
        for (int j = 0 ; j < C ; ++j)
          if (tmp < empty) {mp[i][j] = '.'; ++tmp;}
          else mp[i][j] = '*';
      mp[0][0] = 'c';
      flg = 1;
    } 
    if (!flg && empty == 1) {
      memset(mp, '*', sizeof(mp));
      mp[0][0] = 'c';
      flg = 1;
    }
    if (!flg) {
      if (tryR()) flg = 1;
      else {
        if (tryC()) flg = 1;
        else {
          if (M == R - 1 && M == C - 1 && R >= 4) {
            memset(mp, '.', sizeof(mp));
            for (int j = 2 ; j < C ; ++j)
              mp[R-1][j] = '*';
            mp[R-2][C-1] = '*';
            flg = 1;
          }
        }
      }
    }
    if (!flg) {
      // printf("Impossible (%d %d %d)\n", R, C, M);
      printf("Impossible\n");
    } else {
      for (int i = 0 ; i < R ; ++i) {
        for (int j = 0 ; j < C ; ++j)
          printf("%c", mp[i][j]);
        printf("\n");
      }
      if (!verify()) {printf("failed to verify!"); return 1;}
    }
  }
  return 0;
}

