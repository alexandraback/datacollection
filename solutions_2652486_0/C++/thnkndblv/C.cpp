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
int N, R, M, K;
vector< vi > subset;
vector< set<int> > a;
vi s( 3 );
int prod(int mask)
{
	int ret = 1;
	forn(i, N)
	{
		if ( mask & (1 << i) ) ret *= s[i];
	}
	return ret;
}
void backtrack(int pos)
{
	if ( pos == N )
	{
		subset.pb( s );
		set<int> temp;
		forn(mask, 1 << N) temp.insert( prod( mask ) );
		a.pb( temp );
	}
	else
	{
		fori(i, 2, M+1)
		{
			s[pos] = i;
			backtrack( pos+1 );
		}
	}
}

int main()
{
	int nTC;

	cin >> nTC;
	forn(tc, nTC)
	{
		cout << "Case #" << tc+1 << ":" << endl;
		cin >> R >> N >> M >> K;
		backtrack( 0 );
		forn(r, R)
		{
			vi ss( K );
			forn(i, K) cin >> ss[i];
			int ans = 0;
			forn(i, subset.size())
			{
				bool ok = true;
				forn(j, K) if ( a[i].count( ss[j] ) == 0 ) ok = false;
				if (ok)
				{
					ans = i;
					break;
				}
			}
			forn(i, N) cout << subset[ans][i];
			cout << endl;
		}
	}

	return 0;
}
