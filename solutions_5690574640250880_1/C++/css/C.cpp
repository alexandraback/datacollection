#include<cstdio>
using namespace std;

int k, t, r, c, cc, m, sx, sy;
bool mine[50][50], ok;

bool Ch(int x, int y) {
  if (x<0 || x>=r || y<0 || y>=c || mine[x][y]) return 1;
  return 0;
}

void Full(int c) {
  int s = m;
  for (int x = 0; x < r; x++)
    for (int y = 0; y < cc; y++)
      mine[x][y] = 0;
  for (int x = 0; x < r; x++)
    for (int y = 0; y < c; y++)
      if (s > 0) {
        mine[x][y] = 1;
        s--;
        k = x;
      }
}

void Change(int c) {
  if (mine[k][1]) return;
  mine[k-1][c-1] = 0;
  mine[k][1] = 1;
}

int main()
{
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d%d%d", &r, &c, &m);
    m = r*c-m;
    cc = c;
    ok = 1;
    sx = sy = 0;
    printf("Case #%d:\n", i);
    if (r==1 || c==1 || m==1) {
      Full(c);
    } else {
      if (m < 4) {
        ok = 0;
      } else {
        if (r==2 || c==2) {
          if (m%2 == 1) {
            ok = 0;
          } else {
            if (c == 2) Full(c); else Full(m/2);
          }
        } else {
          if (m==5 || m==7) {
            ok = 0;
          } else {
            int tmp = (m+2)/3; 
            if (m%2 == 0) tmp = m/2;
            if (tmp > c) tmp = c;
            Full(tmp);
            Change(tmp);
          }
        }
      }
    }
    if (ok) {
      for (int x = 0; x < r; x++)
        for (int y = 0; y < c; y++)
          if (Ch(x+1, y+1) && Ch(x+1, y-1) && Ch(x-1, y+1) && Ch(x-1, y-1) && Ch(x, y) && Ch(x+1, y) && Ch(x-1,y) && Ch(x, y+1) && Ch(x, y-1)) {
            sx = x;
            sy = y;
          }
      for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++)
          if (x==sx && y==sy) {
            printf("c");
          } else {
            if (mine[x][y]) printf("."); else printf("*");
          }
        printf("\n");
      }
    } else {
      printf("Impossible\n");
    }
  }
}
