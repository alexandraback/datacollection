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

/* Macros */
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define fori(i, a, b) for (int i=(a); i<(b); i++)
#define forn(i, n) fori(i, 0, (n))

#define all(x) (x).begin(), (x).end()
#define null(x) memset((x), -1, sizeof (x))
#define clean(x) memset((x), 0, sizeof(x))

#define pb push_back
#define mp make_pair

/* Redefinir tipos de datos */
typedef vector<int> vi;
typedef long long LL;
typedef pair<int,int> ii;

/* Funciones */
inline LL mod(LL n, LL MOD = (LL)(1e9 + 7)){ return (n % MOD + MOD) % MOD; }
inline LL gcd(LL a, LL b){ return b == 0LL ? a : gcd(b, a % b); }
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

/** PROGRAMA PRINCIPAL **/

int N, K;
int initial[ 205 ];
int countKeys[ 20 ][ 205 ];
int open[ 21 ];
int ans[ 21 ];
bool dp[ 1 << 20 ];
bool done[ 1 << 20 ];
bool run(int mask)
{
	bool &ret = dp[ mask ];

	if ( done[mask] ) return ret;
	
	done[mask] = true;
	
	if ( mask == 0 ) return ret = true;
	
	ret = false;
	forn(i, N) if ( mask & (1 << i) )
	{
		int cnt = initial[ open[i] ];
		forn(j, N) if ( (mask & (1 << j)) == 0 )
		{
			cnt += countKeys[j][ open[i] ];
			if ( open[j] == open[i] ) cnt--;
		}
		ans[ N - __builtin_popcount(mask) ] = i + 1;
		if ( cnt > 0 && run(mask ^ (1 << i)) )
		{
			ret = true;
			break;
		}
	}
	return ret;
}

int main()
{
	int T;
	int x;

	cin >> T;
	forn(testCase, T)
	{	
		cin >> K >> N;
		
		clean( initial );
		forn(i, K)
		{
			cin >> x;
			initial[ x ]++;
		}

		forn(i, N)
		{
			cin >> open[ i ];

			int k;
			cin >> k;
			
			clean( countKeys[ i ] );
			
			forn(j, k)
			{
				cin >> x;
				countKeys[ i ][ x ]++;
			}
		}

		clean( done );
		int ret = run( (1 << N) - 1 );
		if ( ret == false ) cout << "Case #" << (testCase+1) << ": IMPOSSIBLE" << endl;
		else
		{
			cout << "Case #" << (testCase+1) << ":";
			forn(i, N) cout << " " << ans[ i ];
			cout << endl;
		}
	}

	return 0;
}
