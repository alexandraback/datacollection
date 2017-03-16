
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

const int MAXN = 1010;

int n;
char in[MAXN];

int main()
{
  int tc;scanf("%d", &tc);
  REP(__, 1, tc)
  {printf("Case #%d: ", __);
    scanf("%d%s", &n, in);
    int cnt = 0, ans = 0;
    REP(i, 0, n)
    {
      int dig = in[i] - '0';
      if(dig > 0 && cnt < i)
      {
        ans += i - cnt;
        cnt = i;
      }
      cnt += dig;
    }
    printf("%d\n", ans);
  }
}
