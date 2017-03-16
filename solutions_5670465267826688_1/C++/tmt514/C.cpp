#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

int cs=0;
char s[50000];
int p[50000];

//1 i j k -1 -i -j -k
int c[8][8];
int u[4][4] = {
  {0, 1, 2, 3},
  {1, 4, 3, 6},
  {2, 7, 4, 1},
  {3, 2, 5, 4}
};

int f(int x, int y) {
  return c[x][y];
}

int get(char x) {
  if(x=='i') return 1;
  else if(x=='j') return 2;
  else if(x=='k') return 3;
  return 0;
}

void solve() {
  int L;
  long long X;

  for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
      c[i][j] = (u[i%4][j%4] + (i/4)*4 + (j/4)*4)%8;

  scanf("%d%lld", &L, &X);
  scanf("%s", s);

  for(int i=0;i<L;i++) p[i] = get(s[i]);
  int now = 0;
  for (int i=0;i<L;i++) now = f(now, p[i]);
  
  long long qq = X%4;
  int all = now;
  now = 0;
  for (int i=0;i<qq;i++) {
    now = f(now, all);
  }

  printf("Case #%d: ", cs);
  fprintf(stderr, "Case #%d: ", cs);

  if (now != 4) { fprintf(stderr, "Case1\n"); puts("NO"); return; }
  
  int R = L;
  for (int i = 1; i < min(X, 4LL); i++)
    for (int j = 0; j < L; j++)
      p[R++] = p[j];
  int MINI = -1, MINK = -1;
  now = 0;
  for (int i = 0; i < R; i++) {
    now = f(now, p[i]);
    if (now == 1) { MINI = i+1; break; }
  }
  now = 0;
  for (int i = R-1; i >= 0; i--) {
    now = f(p[i], now);
    if (now == 3) { MINK = R-i; break; }
  }

  if (MINI == -1 || MINK == -1 || MINI + MINK > (long long)L * X) {
    fprintf(stderr, "CASE2 NO\n");
    puts("NO");
  }
  else {
    fprintf(stderr, "CASE2 YES\n");
    puts("YES");
  }

}
int main(void) {
  int T;
  scanf("%d", &T);
  for(cs=1;cs<=T;cs++) solve();
  return 0;
}
