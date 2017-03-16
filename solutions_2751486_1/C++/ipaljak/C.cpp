#include <cstdio>
#include <cstring>

#define MAXN 1000010

using namespace std;

int T, len, N;
int lo[MAXN], hi[MAXN];

char s[MAXN];

inline bool vowel ( char x ){
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

inline void solve( int t ){

	scanf( "%s", s ); len = strlen ( s );
	scanf( "%d", &N );

	int ptr = 0, cnt = 0;
	while ( ptr < len ){

		
		if ( vowel( s[ptr] ) ){ ++ptr; continue; }
	
		int tmp = 0;
		while ( ptr < len && !vowel( s[ptr] ) ){
			++tmp;
			if ( tmp >= N ){ lo[cnt] = ptr - N + 1; hi[cnt] = ptr; ++cnt; }
			++ptr;
		}
	
	}
	
	long long sol = 0;
	int prevHi = 0;
	
	for ( int i = 0; i < cnt; ++i ){
		//printf( "- %d %d -\n", lo[i], hi[i] );
		long long l = 0, d = len - hi[i] - 1;
		if ( lo[i] > prevHi ) l = ( long long ) lo[i] - prevHi;	
		sol += ( long long ) ( l + 1 ) * ( d + 1 );
		//printf( "# %lld %lld #\n", l, d );
		prevHi = lo[i] + 1;
;	}
	
	printf( "Case #%d: %lld\n", t, sol );

}

int main( void ){

	scanf( "%d", &T );
	for ( int i = 0; i < T; ++i ) solve( i + 1 ); 
	
	return 0;

}
