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

string board[ 4 ];

bool notEnded()
{
	forn(i, 4) forn(j, 4) if ( board[i][j] == '.' ) return true;
	return false;
}

bool won(char c)
{
	int row[4], col[4], diag[2];

	clean( row );
	clean( col );
	clean( diag );

	forn(i, 4) forn(j, 4)
	{
		if ( board[i][j]=='T' || board[i][j]==c )
		{
			row[ i ]++;
			col[ j ]++;

			if ( i==j ) diag[0]++;
			if ( i+j == 3 ) diag[1]++;
		}
	}

	if ( count(row, row+4, 4) > 0 ) return true;
	if ( count(col, col+4, 4) > 0 ) return true;
	if ( count(diag, diag+2, 4) > 0 ) return true;
	return false;
}

int main()
{
	int T;

	cin >> T;
	forn(testCase, T)
	{
		cin.ignore();
		forn(i, 4) getline( cin, board[i] );

		string answer = notEnded() ? "Game has not completed" : "Draw";
		if ( won('X') ) answer = "X won";
		else if ( won('O') ) answer = "O won";

		cout << "Case #" << (testCase+1) << ": " << answer << endl;
	}

	return 0;
}
