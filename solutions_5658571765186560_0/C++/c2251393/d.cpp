
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

bool ok(int x, int r, int c)
{
  if(x >= 7) return 0;
  if((r*c) % x != 0) return 0;
  if(max(r, c) < x) return 0;
  if(x == 1) return 1;
  if(x == 2) return 1;
  if(x == 3)
  {
    if(min(r, c) == 1) return 0;
    return 1;
  }
  if(x == 4)
  {
    if(min(r, c) > 2) return 1;
    return 0;
  }
  if(x == 5)
  {
    if(min(r, c) > 2) return 1;
    return 0;
  }
  if(x == 6)
  {
    if(min(r, c) > 2) return 1;
    return 0;
  }
}

int main()
{
  int tc;scanf("%d", &tc);
  REP(__, 1, tc)
  {printf("Case #%d: ", __);
    int x, r, c;scanf("%d%d%d", &x, &r, &c);
    if(ok(x, r, c)) puts("GABRIEL");
    else puts("RICHARD");

  }
}
