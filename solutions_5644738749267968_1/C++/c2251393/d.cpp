
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

const int MAXN = 1010;

int n;
double massN[MAXN], massK[MAXN];

inline int solveDWAR()
{
	int pts = 0;
	REP(i, 1, n)
	{
		bool flag = 1;
		REP(j, 1, n-i+1)
			if(massN[i+j-1] < massK[j])
			{
				flag = 0;
				break ;
			}
		if(flag)
		{
			pts = n-i+1;
			break ;
		}
	}
	return pts;
}

inline int solveWAR()
{
	int pts = n;
	int j = 1;
	REP(i, 1, n)
	{
		while(j <= n && massN[i] > massK[j]) 
			j++;
		if(j <= n)
		{
			pts--;
			j++;
		}
	}
	return pts;
}

int main()
{
	int t;
	scanf("%d", &t);
	REP(__, 1, t)
	{
		scanf("%d", &n);
		REP(i, 1, n) scanf("%lf", massN+i);
		sort(massN+1, massN+n+1);
		REP(i, 1, n) scanf("%lf", massK+i);
		sort(massK+1, massK+n+1);
		int x = solveDWAR();
		int y = solveWAR();
		x = max(x, y);
		printf("Case #%d: ", __);
		printf("%d %d\n", x, y);
	}
}
