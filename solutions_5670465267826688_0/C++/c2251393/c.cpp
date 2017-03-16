
// default code for competitive programming
// c2251393 ver 3.141 {{{

// Includes
#include <bits/stdc++.h>

// Defines
#define NAME(x) #x
#define SZ(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define REP(i, s, e) for(int i = (s); i <= (e); i++)
#define REPD(i, s, e) for(int i = (s); i >= (e); i--)
#define DEBUG 1
#define fst first
#define snd second
 
using namespace std;

// Typedefs
typedef double real;
typedef long long ll;
typedef pair<ll, int> pli;
typedef tuple<ll, int> tli;
typedef pair<int, int> pii;
typedef tuple<int, int> tii;
typedef unsigned long long ull;

// Some common const.
const double EPS = -1e8;
const double Pi = acos(-1);
 
// Equal for double
bool inline equ(double a, double b)
{return fabs(a - b) < EPS;}

// }}}
// start ~~QAQ~~

const int MAXN = 10010;

int n, m;
char in[MAXN];

/*
 * i, j, k
 * i, k, -1
 */

map<char, pii> mp{
  {'1', pii(1, 1)},
  {'i', pii(1, 2)},
  {'j', pii(1, 3)},
  {'k', pii(1, 4)}
};

int sgn(int t)
{return t < 0 ? -1:1;}

int tbl[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 2, 3, 4},
  {0, 2,-1, 4,-3},
  {0, 3,-4,-1, 2},
  {0, 4, 3,-2,-1}
};

pii mul(pii x, pii y)
{
  int tsg = x.first * y.first;
  int tvl = tbl[x.second][y.second];
  return pii(tsg * sgn(tvl), tvl * sgn(tvl));
}

char dat[MAXN*40];
pii pro[MAXN*40];

int main()
{
  int tc;scanf("%d", &tc);
  REP(__, 1, tc)
  {printf("Case #%d: ", __);
    ll tmp;
    scanf("%d%lld", &n, &tmp);
    scanf("%s", in+1);
    if(tmp > 23ll)
    {
      tmp %= 4;
      m = tmp + 20;
    }
    else m = tmp;
    REP(i, 0, m-1) REP(j, 1, n)
        dat[i*n+j] = in[j];
    dat[m*n+1] = 0;
    //printf("%s\n", dat+1);
    pro[0] = pii(1, 1);
    REP(i, 1, m*n)
      pro[i] = mul(pro[i-1], mp[dat[i]]);
    int now = 0;
    vector<pii> goal{{1, 2}, {1, 4}};
    REP(i, 1, m*n)
    {
      if(now > 1) break ;
      if(pro[i] == goal[now]) now++;
    }
    if(now > 1 && pro[m*n] == pii(-1, 1)) puts("YES");
    else puts("NO");

  }
}
