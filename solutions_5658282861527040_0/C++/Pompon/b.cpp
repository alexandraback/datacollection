#include <cstdio>
#include <algorithm>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,p,k) for(int i=(p); i<=(k); ++i)

typedef long long LL;

bool ok(int a, int b, int k)
{ return (a&b&k)==(a&b); }

int set(int a, int ai, bool v)
{ return (a>>ai&1)==v ? a : a^1<<ai; }

int bc(int v){ return __builtin_popcount(v); }

int n(int v, bool d){ return d ? v : ~v; }

LL count(int a, int b, int k, int ki)
{
  if(!(k>>ki&1)) return 0;
  k ^= 1<<ki;

  int C[2][2][2]; REP(i,2) REP(j,2) REP(l,2)
    C[i][j][l] = bc(n(a>>ki,i) & n(b>>ki,j) & n(k>>ki,l));
  printf("k = %d\n",k);
  REP(i,2) REP(j,2) REP(l,2) printf("C[%d][%d][%d]=%d\n",i,j,l,C[i][j][l]);
  if(C[0][0][1] || C[1][0][1] || C[0][1][1]) return 0;
  if(C[1][1][0]) return (1LL<<ki-1+C[0][1][0]+ki-1+C[1][0][0]);
  LL res = ((1<<C[0][1][0])-1)*(1LL<<ki-1)+(a&((1<<ki)-1));
  res *= ((1<<C[0][0][1])-1)*(1LL<<ki-1)+(b&((1<<ki)-1));
  return res; 
}

int main()
{
  int t; scanf("%d",&t);
  FOR(_,1,t)
  {
    int a,b,k; scanf("%d%d%d",&a,&b,&k);
    LL res = 0;
    REP(i,a) REP(j,b) if((i&j)<k) res++;
    printf("Case #%d: %d\n",_,res);
    //REP(ki,40) res += count(a,b,k,ki);
    //printf("%lld\n",res);
  }
  return 0;
}
