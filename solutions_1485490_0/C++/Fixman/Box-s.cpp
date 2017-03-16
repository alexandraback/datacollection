#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
 
using namespace std ;

#define all(n) n.begin(), n.end()
#define fb(i, n) fv (i, 0, n)
#define fe(i, n) fb (i, n.size())
#define fi(i, n) for (typeof (n.begin()) i = n.begin() ; i != n.end() ; i++)
#define fv(i, s, n) for ( int i = s ; i < n ; i++ )
#define LOG cerr << "[" << __LINE__ << "] "
#define pb push_back

#define y first
#define x second

typedef long long ll ;
typedef pair <ll, ll> pll ;

const int lm = 150 ;
const ll sm = -23058430092136939ll ;

int N, M ;
int Va[lm], Vb[lm] ;
ll Qa[lm], Qb[lm] ;

pll P[lm][lm][2] ;

ll solve()
{
	fb (n, lm) fb (m, lm) fb (j, 2) P[n][m][j] = pll(0, 0) ;

	cin >> N >> M ;
	fb (i, N) cin >> Qa[i] >> Va[i] ;
	fb (i, M) cin >> Qb[i] >> Vb[i] ;

	Va[N] = -1 ;
	Vb[M] = -2 ;

	fb (n, N + 1) fb (m, M + 1) fb(w, 2)
	{
		ll s = P[n][m][w].y ;
		ll r = P[n][m][w].x ;

		if (n == N && m == M) continue ;

		//LOG << n << ' ' << m << ' ' << w << endl ;
		//assert(!w && r + Qa[n] > 0 || w && r + Qb[m] > 0) ;

		//if (!w && r + Qa[n] <= 0) P[n + 1][m][0] = max(P[n + 1][m][0], pll(s, 0)) ;
		//if (!w && r + Qa[n] <= 0 || w && r + Qb[m] <= 0) continue ;

		//LOG << n << ' ' << m << ' ' << w << ": " << s << ' ' << r << endl ;

		if (Va[n] != Vb[m])
		{
			if (w == 0)
			{
				P[n + 1][m][0] = max(P[n + 1][m][0], pll(s, 0)) ;
				P[n + 1][m][1] = max(P[n + 1][m][1], pll(s, 0)) ;

				P[n][m + 1][0] = max(P[n][m + 1][0], pll(s, r)) ;
			}
			else
			{
				P[n + 1][m][1] = max(P[n + 1][m][1], pll(s, r)) ;

				P[n][m + 1][0] = max(P[n][m + 1][0], pll(s, 0)) ;
				P[n][m + 1][1] = max(P[n][m + 1][1], pll(s, 0)) ;
			}
		}
		else
		{
			ll Aa = Qa[n] + r * !w, Ab = Qb[m] + r * w ;

			if (n == N) Aa = 0 ;
			if (m == M) Ab = 0 ;

			if (Aa > Ab)
				P[n][m + 1][0] = max(P[n][m + 1][0], pll(s + Ab, r * !w - Ab)) ;
			else
				P[n + 1][m][1] = max(P[n + 1][m][1], pll(s + Aa, r *  w - Aa)) ;
		}
	}

	//fb (i, N + 1) { fb (u, M + 1) cout << '(' << P[i][u][0].y << ' ' << P[i][u][0].x << ", " << P[i][u][1].y << ' ' << P[i][u][1].x << "), " ; cout << endl ; }

	return max(P[N][M][0].y, P[N][M][1].y) ;
}

int main()
{
	int t ; cin >> t ;
	fb (i, t)
		printf ("Case #%d: %lld\n", i + 1, solve()) ;
}

