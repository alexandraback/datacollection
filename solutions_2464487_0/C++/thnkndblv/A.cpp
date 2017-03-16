/* Librerias */
#include "stdio.h"
#include "memory.h"
#include "string.h"
#include "ctype.h"
#include "math.h"
#include "iostream"
#include "string"
#include "algorithm"
#include "utility"
#include "vector"
#include "sstream"
#include "stack"
#include "queue"
#include "deque"
#include "set"
#include "map"
#include "bitset"

using namespace std;

/*---------------------------------- Macros ----------------------------------*/
#define foreach(i, a) for (typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define fori(i, a, b) for (int i=(a); i<(b); i++)
#define forn(i, n) fori(i, 0, (n))

#define all(x) (x).begin(), (x).end()
#define null(x) memset((x), -1, sizeof (x))
#define zero(x) memset((x), 0, sizeof (x))

#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second

/*------------------------ Redefinir tipos de datos --------------------------*/
typedef vector<int> vi;
typedef long long LL;
typedef pair<int,int> ii;

/*------------------------------- Funciones ----------------------------------*/
inline LL mod(LL n, LL MOD = (LL)(1e9 + 7)){ return (n % MOD + MOD) % MOD; }
inline LL gcd(LL a, LL b){ return (b == 0LL) ? a : gcd(b, a % b); }
inline LL modPow(LL a, LL b, LL MOD = (LL)(1e9 + 7))
{
	LL ret = 1LL;
	while ( b > 0LL )
	{
		if ( b & 1 ) ret = mod( ret * a, MOD );
		a = mod( a * a, MOD );
		b >>= 1;
	}
	return ret;
}
inline bool leapYear(int year){ return (year%400 == 0) || (year%100 != 0 && year%4 == 0); }

/*-------------------------- PROGRAMA PRINCIPAL ------------------------------*/


int main()
{
	int nTC;

	cin >> nTC;
	forn(tc, nTC)
	{
		LL r, t;

		cin >> r >> t;

		LL lo = 1, hi = min( (LL)(1e9), (LL)(6e18) / r );
		while ( lo < hi )
		{
			LL n = (lo + hi + 1LL) >> 1;
			LL x = 2LL*n*r + 2*n*n - n;
			//cout << "*" << n << " " << x << endl;
			if ( x > t ) hi = n - 1;
			else lo = n;
		}

		cout << "Case #" << tc+1 << ": "  << lo << endl;
	}

	return 0;
}
