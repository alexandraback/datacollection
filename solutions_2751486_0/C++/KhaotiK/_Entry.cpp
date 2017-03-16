#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <hash_map>
#include <hash_set>
#include <map>
#include <memory>
#include <numeric>
#include <random>
#include <regex>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define all( cont ) cont.begin(), cont.end()
#define rep( i, n ) for( int i=0; i<n; i++ )
#define repd( i, n, d ) for( int i=0; i<n; i+=d )

const char* inname = "As.in";
const char* outname = "As.out";

inline bool IsCon( char c )
{
	switch(c)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return false;
	default:
		return true;
	}
}

int main( int argc, char** argv )
{
	int T;
	freopen( inname, "r", stdin );
	freopen( outname, "w", stdout );
	
	char str[1000001];
	int n;

	int f, b;

	int sum;

	scanf( "%d", &T );
	for( int iT=1; iT<=T; iT++ ) {
		printf( "Case #%d: ", iT );
		memset( str, 0, 1000001 );
		scanf( "%s %d", str, &n );

		sum = 0;
		
		f = b = 0;

		int len = strlen( str );
		for( int f=0; f<len; f++ ) {
			for( int b=0; b<=f; b++ ) {
				int tot = 0;
				for( int i=b; i<=f; i++ ) {
					if( IsCon(str[i]) ) tot++;
					else tot = 0;
					if( tot >= n ) { sum++; break; }
				}
			}

		}

		printf( "%d\n", sum );
	}
	return 0;
}
