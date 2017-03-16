#include <cstdio>
#include <algorithm>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FORD(i,p,k) for(int i=(p); i>=(k); --i)

enum { n_max = 1200 };

int run(double *A, double *B, int n)
{
  int res = 0;
  int bi = n-1;
  FORD(i,n-1,0)
  {
    while(bi>=0 && A[i]<B[bi]) bi--;
    if(bi>=0 && A[i]>B[bi]){ res++; bi--; }
  }
  return res;
}

double A[2][n_max];

int main()
{
  int t; scanf("%d",&t);
  REP(_,t)
  {
    int n; scanf("%d",&n);
    REP(i,2) REP(j,n) scanf("%lf",&A[i][j]);
    REP(i,2) std::sort(A[i],A[i]+n);
    printf("Case #%d: %d %d\n",_+1,run(A[0],A[1],n),n-run(A[1],A[0],n));
  }
  return 0;
}

