#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string>

#define FORr(i,A,B)	for (int i=(A); i<(B); ++i)
#define FOR(i, N)	FORr(i,0,N)

using namespace std;

int 	get_int()		{int a; 	scanf("%d", &a); 	return a;}
double	get_double()	{double a;	scanf("%lf", &a);	return a;}
char	get_char()		{char c; 	scanf("%c", &c); 	return c;}

__int64 get_s64()		{__int64 a; scanf("%lld", &a);  return a;}

char str_buf[100000];
string	get_str()		{scanf("%s", str_buf); return str_buf;}

bool routine( int curr, bool* use1, bool* use2, __int64* numset, int N );
bool routine2( int curr, bool* use1, bool* use2, __int64* numset, int N );

__int64 sum1 = 0;

bool check( bool* use1, bool* use2, __int64* numset, int N ) {
	__int64 ret1 = 0, ret2 = 0;
	FOR(i, N) {
		if (use1[i]) ret1 += numset[i];
		else if ( use2[ i ] ) ret2 += numset[i];
	}
	if ( ret1 == 0 ) return false;
	return ret1 == ret2;
}

bool routine2( int curr, bool* use1, bool* use2, __int64* numset, int N ) {
	if ( curr == N ) return false;

	if ( curr == 0 ) {
		sum1 = 0;
		FOR(i, N) {
			if (use1[i]) sum1 += numset[i];
		}
		if (sum1 == 0) return false;

		// ‘S•”‘«‚µ‚Ä‚à‘«‚è‚È‚¢ê‡
		__int64 sum2_all = 0;
		FOR( i, N ) {
			if (use1[i] == false) sum2_all += numset[i];
		}
		if (sum1 > sum2_all) return false;
	}

	if ( use1[curr] == false ) {
		use2[curr] = true;
		if ( check( use1, use2, numset, N ) ) return true;
		else if ( routine2( curr + 1, use1, use2, numset, N ) ) return true;
	}

	use2[curr] = false;
	if ( check( use1, use2, numset, N ) ) return true;
	else if ( routine2( curr + 1, use1, use2, numset, N ) ) return true;

	return false;
}

bool routine( int curr, bool* use1, bool* use2, __int64* numset, int N ) {
	if ( curr == N ) return false;

	use1[curr] = true;
	if ( check( use1, use2, numset, N ) ) return true;
	else if ( routine2( 0, use1, use2, numset, N ) ) return true;
	else if ( routine( curr + 1, use1, use2, numset, N ) ) return true;

	use1[curr] = false;
	if ( check( use1, use2, numset, N ) ) return true;
	else if ( routine2( 0, use1, use2, numset, N ) ) return true;
	else if ( routine( curr + 1, use1, use2, numset, N ) ) return true;

	return false;

#if 0
	use1[curr] = true;
	use2[curr] = false;
	if ( check( use1, use2, numset, N ) ) return true;
	else if ( routine( curr + 1, use1, use2, numset, N ) ) return true;

	use1[curr] = false;
	use2[curr] = true;
	if ( check( use1, use2, numset, N ) ) return true;
	else if ( routine( curr + 1, use1, use2, numset, N ) ) return true;

	use1[curr] = false;
	use2[curr] = false;
	if ( check( use1, use2, numset, N ) ) return true;
	else if ( routine( curr + 1, use1, use2, numset, N ) ) return true;

	return false;
#endif
}

void solve()
{
	printf( "\n" );
	int N = get_int();

	bool use1[500];
	bool use2[500];

	__int64 numset[500];

	FOR(i, N) {
		use1[i] = false;
		use2[i] = false;
		numset[i] = get_s64();
	}

	if ( routine( 0, use1, use2, numset, N ) ) {
		FOR(i, N) if (use1[i]) printf( "%lld ", numset[i] );
		printf( "\n" );
		FOR(i, N) if (use2[i]) printf( "%lld ", numset[i] );
	} else {
		printf( "Impossible" );
	}
}

int main()
{
	int T = get_int();
	FOR (t, T)
	{
		printf("Case #%d: ", t + 1);
		solve();
		printf("\n");
	}
}
