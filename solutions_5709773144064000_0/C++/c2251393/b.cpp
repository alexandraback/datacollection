
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
typedef pair<int, int> pii;
typedef unsigned long long ull;

// Some common const.
const double EPS = -1e8;
const double Pi = acos(-1);
 
// Equal for double
bool inline equ(double a, double b)
{return fabs(a - b) < EPS;}

// }}}
// start ~~QAQ~~



int main()
{
	int t;
	scanf("%d", &t);
	REP(__, 1, t)
	{
		printf("Case #%d: ", __);

		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);

		double ac = x / 2;

		double investTime = 0.0;
		double rate = 2.0;
		REP(i, 0, 100000)
		{
			ac = min(ac, investTime + x / rate);
			investTime += c / rate;
			rate += f;
		}

		printf("%.7lf\n", ac);
	}
}
