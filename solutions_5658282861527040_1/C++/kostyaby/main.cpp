#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

long long _a, _b, _c;
long long a[ 50 ], b[ 50 ], c[ 50 ];
long long f[ 50 ][ 2 ][ 2 ][ 2 ];

int main (int argc, const char * argv[])
{
	int t; cin >> t;
	for ( int it = 1; it <= t; it++ )
	{
		cin >> _a >> _b >> _c;
		for ( int i = 0; i < 50; i++ )
		{
			a[i] = _a % 2; _a /= 2;
			b[i] = _b % 2; _b /= 2;
			c[i] = _c % 2; _c /= 2;
		}
		reverse( a, a + 50 );
		reverse( b, b + 50 );
		reverse( c, c + 50 );
		memset( f, 0, sizeof( f ) );
		f[0][0][0][0] = 1;
		for ( int i = 0; i < 49; i++ )
			for ( int j = 0; j < 2; j++ )
				for ( int k = 0; k < 2; k++ )
					for ( int l = 0; l < 2; l++ )
					{
						for ( int d1 = 0; d1 < 2; d1++ )
							for ( int d2 = 0; d2 < 2; d2++ )
							{
								if ( d1 == 1 && j == 0 && a[i + 1] == 0 ) continue;
								if ( d2 == 1 && k == 0 && b[i + 1] == 0 ) continue;
								int d3 = d1 & d2;
								if ( d3 == 1 && l == 0 && c[i + 1] == 0 ) continue;
								int _i = i + 1;
								int _j = j; if ( d1 == 0 && a[i + 1] == 1 ) _j = 1; 
								int _k = k; if ( d2 == 0 && b[i + 1] == 1 ) _k = 1; 
								int _l = l; if ( d3 == 0 && c[i + 1] == 1 ) _l = 1; 
								f[_i][_j][_k][_l] += f[i][j][k][l];
							}
					}
		long long answer = f[49][1][1][1];
		/*for ( int j = 0; j < 2; j++ )
			for ( int k = 0; k < 2; k++ )
				for ( int l = 0; l < 2; l++ )
					answer += f[49][j][k][l];*/
		cout << "Case #" << it << ": " << answer << "\n";
	}
    return 0;
}