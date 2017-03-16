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

int lawn[ 102 ][ 102 ];
bool ok[ 102 ][ 102 ];

int main()
{
	int T;

	cin >> T;
	forn(testCase, T)
	{
		int N, M;
		cin >> N >> M;
		forn(i, N) forn(j, M) cin >> lawn[i][j];

		clean( ok );

		// Rows
		forn(r, N)
		{
			int h = lawn[r][0];
			forn(c, M) h = max( h, lawn[r][c] );
			forn(c, M) if ( lawn[r][c] == h ) ok[r][c] = true;
		}
		// Cols
		forn(c, M)
		{
			int h = lawn[0][c];
			forn(r, N) h = max( h, lawn[r][c] );
			forn(r, N) if ( lawn[r][c] == h ) ok[r][c] = true;
		}

		string ans = "YES";
		forn(i, N) forn(j, M) if ( !ok[i][j] ) ans = "NO";

		cout << "Case #" << (testCase+1) << ": " << ans << endl;
	}

	return 0;
}
