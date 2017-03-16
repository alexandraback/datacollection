#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define FN "C-small-attempt1"

int n,m,x;
char a[128][128];

bool solve(int n, int m, int x) {
  if (x == 1) {
    a[0][0] = 'c';
    return true;
  }
  if (n == 1) {
    a[0][0] = 'c';
    FOR(i,1,x-1) a[0][i]='.';
    return true;
  }
  if (n==2) {
    if (x%2 != 0) return false;
    if (x<4) return false;
    REP(i,2) REP(j,x/2) a[i][j]='.';
    a[0][0]='c';
    return true;
  }
  if (x==4 || x==6) {
    REP(i,2) REP(j,x/2) a[i][j] = '.';
    a[0][0]='c';
    return true;
  }
  if (x < 8) return false;
  int y = x;
  REP(i,2) REP(j,2) a[i][j] = '.';
  a[0][0]='c';
  y-=4;
  FOR(i,2,max(n,m)) {
    if (y<2) break;
    if (i < n) {
      a[i][0]=a[i][1]='.';
      y-=2;
    }
    if (y<2) break;
    if (i < m) {
      a[0][i]=a[1][i]='.';
      y-=2;
    }
  }
  FOR(i,2,n-1) FOR(j,2,m-1) {
    if (y<1) return true;
    a[i][j]='.';
    --y;
  }
  if (y==0) return true;
  fprintf(stderr,"BAD %d %d %d\n", n,m,x);
  return false;
}

bool verify(int n, int m, int x) {
  int q=0,w=0,e=0;
  REP(i,n) REP(j,m) 
    if (a[i][j]=='c') ++q;
    else if (a[i][j]=='.') ++w;
    else if (a[i][j]=='*') ++e;
  //printf("== %d %d %d\n",q,w,e);
  return q==1 && w+q==x && q+w+e == n*m;
}

int main()
{
  freopen(FN ".in","r",stdin);
  freopen(FN ".out","w",stdout);

  int tests;
  scanf("%d",&tests);
  for (int test = 1; test<=tests; test++)
  {
    scanf("%d%d%d",&n,&m,&x);
    printf("Case #%d:\n",test);
    x = n*m-x;
    bool sw = n>m;
    if (sw) {
      swap(n,m);
    }
    REP(i,n) REP(j,m) a[i][j]='*';
    if (!solve(n,m,x)) {
      printf("Impossible\n");
    } else {
      if (!verify(n,m,x)) fprintf(stderr,"very bad\n");
      if (!sw) {
        REP(i,n) {
          REP(j,m) {
            printf("%c",a[i][j]);
          }
          printf("\n");
        }
      } else {
        REP(j,m) {
          REP(i,n) {
            printf("%c",a[i][j]);
          }
          printf("\n");
        }
      }
    }
  }
  return 0;
}
