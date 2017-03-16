#include <cstdio>
#include <cassert>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,p,k) for(int i=(p); i<=(k); ++i)

enum { n_max = 100 };

int A[n_max][n_max];

bool solve1(int c, int m)
{
  assert(m<c);
  REP(i,m) A[0][i] = '*';
  A[0][c-1] = 'c';
  return 1;
}

bool solve2(int c, int m)
{
  int f = 2*c-m;
  assert(f);
  if(f==1){ f--; m++; }
  if(f&1 || f==2) return 0;
  REP(i,2) REP(j,m/2) A[i][j] = '*';
  A[0][c-1] = 'c';
  return 1;
}

bool solve(int r, int c, int m)
{
  assert(r<=c);
  REP(rr,r) REP(cc,c) A[rr][cc] = '.';
  if(r==1) return solve1(c,m);
  if(r==2) return solve2(c,m);
  int f = r*c-m;
  REP(rr,r) REP(cc,c) A[rr][cc] = '*';
  if(f==1){ A[0][0] = 'c'; return 1; }
  if(f==2 || f==3 || f==5 || f==7) return 0;
  REP(rr,2) REP(cc,2) A[rr][cc] = '.';
  if(f==4){ A[0][0] = 'c';  return 1; }
  f -= 6;
  FOR(rr,2,r-1) if(f>1){ REP(cc,2) A[rr][cc] = '.'; f -= 2; }
  int cc = 2;
  while(f){ REP(rr,r) if(f){ A[rr][cc] = '.'; f--; } cc++; }
  if(A[1][cc-1]=='*') A[1][cc-1] = A[2][cc-1] = '.';
  else if(cc==c) A[r-1][c-1] = A[r-2][c-1] = '.';
  else A[0][cc] = A[1][cc] = '.';
  A[0][0] = 'c';
  return 1;
}

int main()
{
  int t; scanf("%d",&t);
  FOR(_,1,t)
  {
    int r,c,m; scanf("%d%d%d",&r,&c,&m);
    printf("Case #%d:\n",_);
    if(r<c)
    {
      if(solve(r,c,m)) REP(rr,r)
      { REP(cc,c) printf("%c",A[rr][cc]); puts(""); }
      else puts("Impossible");
    }
    else
    {
      if(solve(c,r,m)) REP(rr,r)
      { REP(cc,c) printf("%c",A[cc][rr]); puts(""); }
      else puts("Impossible");
    }
  }
  return 0;
}
