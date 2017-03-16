#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define SZ(c) ((int)(c).size())
typedef long long LL;

char a[105][105];
int p[105];
int flag = 0;
int R, C, M;

int check_spaces(int c) {
  if (c == 0) return 0;
  int ret = p[0];
  for(int i=0;i<c;i++) ret += p[i];
  ret += c+1;
  if (c == C) ret -= p[c-1]+1;
  return ret;
}

void make_sol(int c) {
  for(int i=0;i<C;i++) if(i>=c) p[i] = 0;
  for(int i=0;i<C;i++) for(int j=0;j<R;j++) a[j][i] = '*';
  for(int j=0;j<=p[0];j++) a[j][0] = '.';
  for(int i=0;i<c;i++) for(int j=0;j<=p[i];j++) a[j][i+1] = '.';
  a[0][0] = 'c';
}

void go(int lev, int S, int last) {
  if (flag) return;
  int t = check_spaces(lev);
  //printf("lev=%d S=%d last=%d t=%d M=%d\n", lev, S, last, t, M);
  if (t > M) return;
  if (t == M) { flag = 1; make_sol(lev); return; }
  if (lev >= C) return;

  last = min(last, S);
  while(last>0) {
    p[lev] = last;
    go(lev+1, S-last, last);
    if (flag) return;
    --last;
  }
}

void solve(int cs) {
  printf("Case #%d:\n", cs);
  int swapped = 0;
  flag = 0;
  scanf("%d%d%d", &R, &C, &M);
  if (R < C) { swapped = 1; swap(R, C); }
  M = R * C - M;
  if (M == 1) {
    for(int i=0;i<R;i++) for(int j=0;j<C;j++)
      a[i][j] = '*';
    a[0][0] = 'c';
    flag = 1;
  } /* else if (M >= 2*C) {
    int cnt = 0;
    for(int i=0;i<R;i++) for(int j=0;j<C;j++)
      if(++cnt <= R*C-M) a[i][j] = '*';
      else if(i==R-1 && j==C-1) a[i][j] = 'c';
      else a[i][j] = '.';
    flag=1;
  } */else {
    go(0, M, min(M, R-1));
  }
  if(!flag) {
    puts("Impossible");
  } else if(swapped) {
    for(int i=0;i<C;i++,puts("")) for(int j=0;j<R;j++) printf("%c", a[j][i]);
  } else {
    for(int i=0;i<R;i++,puts("")) for(int j=0;j<C;j++) printf("%c", a[i][j]);
  }
}

int main(void) {
  int T;
  scanf("%d", &T);
  for(int cs=1;cs<=T;cs++) solve(cs);
  return 0;
}
