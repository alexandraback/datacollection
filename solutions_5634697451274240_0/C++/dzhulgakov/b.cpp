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

#define FN "B-small-attempt0"

#define N 128
#define K 1024

int mem[2][1024];

int f(bool plus, int n)
{
  //fprintf(stderr, "enter %c %d\n", plus?'+':'-', n);
  int& res = mem[plus][n];
  if (res != -1) return res;

  if (plus && n==1) return res = 0;
  res = 1000000;
  FOR(k,1,n)
  {
    bool kp = (k%2 == 1) ? plus : !plus;
    int nn = n;
    if (k < n && !plus == !kp) --nn;
    res = min(res, f(!kp, nn)+1);
  }
  return res;
}

int main()
{
  freopen(FN ".in","r",stdin);
  freopen(FN ".out","w",stdout);

  FILL(mem,-1);

  int tests;
  scanf("%d",&tests);
  for (int test = 1; test<=tests; test++)
  {
    char a[10000];
    scanf("%s", a);
    bool plus = a[0] == '+';
    int k = 1;
    REP(i,strlen(a)) if (i && a[i] != a[i-1]) ++k;

    int res = f(plus,k);

    printf("Case #%d: %d\n",test,res);
  }
  return 0;
}
