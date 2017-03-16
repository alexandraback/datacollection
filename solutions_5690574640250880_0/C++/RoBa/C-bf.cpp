#include <cstdio>
#include <cstring>
#include <cassert>

int R, C, M, empty;
char mp[64][64];

const int dir[][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int cc[64][64], q[64*64][2], tk[64][64];
inline bool in(int x, int y) {
  return x >= 0 && x < R && y >= 0 && y < C;
}
int verify(int &cx, int &cy) {
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
  for (cx = 0 ; cx < R ; ++cx) {
    for (cy = 0 ; cy < C ; ++cy) {
      if (mp[cx][cy] == '*') continue;

      memset(tk, 0, sizeof(tk));
      q[0][0] = cx; q[0][1] = cy; tk[cx][cy] = 1;
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
      if (qh == empty) return 1;
    }
  }
  return 0;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    scanf("%d%d%d",&R,&C,&M);
    empty = R * C - M;
    printf("Case #%d:\n", ca);
    int flg = 0;
    for (int mask = 0 ; mask < (1<<(R*C)) ; ++mask) {
      int cnt = 0;
      for (int i = 0 ; i < R * C ; ++i) {
        if (mask&(1<<i)) {
          mp[i/C][i%C] = '*';
          ++cnt;
        } else {
          mp[i/C][i%C] = '.';
        }
      }
      if (cnt != M) continue;
      /*
      printf("====\n");
      for (int i = 0 ; i < R ; ++i) {
        for (int j = 0 ; j < C ; ++j)
          printf("%c", mp[i][j]);
        printf("\n");
      }
      printf("====\n");
      */
      int cx, cy;
      if (verify(cx, cy)) {
        // printf("cx:%d cy:%d\n", cx, cy);
        mp[cx][cy] = 'c';
        for (int i = 0 ; i < R ; ++i) {
          for (int j = 0 ; j < C ; ++j)
            printf("%c", mp[i][j]);
          printf("\n");
        }
        flg = 1;
        break;  
      }
    }
    if (!flg) printf("Impossible\n");
  }
  return 0;
}

