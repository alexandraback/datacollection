#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <fstream>

#define ll long long
#define ull unsigned ll
#define FOR( i, a, b ) for( i = a; i <= b; i++ )
#define REP( i, n ) for( i = 0; i < n ; i++ )
#define pb push_back
#define VI vector<int>
#define VVI vector< vector<int> >
#define VS vector<string>
#define VVS vector< vector<string> >

using namespace std;

int main()
{
	int t, n, m, i, j, k;
	ull x, y, sum, ans;
	scanf( "%d", &t );
	FOR( i, 1, t ) {
		scanf( "%d %d", &n, &m );
		vector< ull > v1,v2;
		vector< vector< ull > > vov1,vov2;
		ull a[200][4] = {0};
		v1.pb(0);v1.pb(0);
		v2.pb(0);v2.pb(0);
		vov1.pb(v1);
		vov2.pb(v1);
		ans = 0;
		REP( j, n ) {
			scanf( "%lld %lld", &x, &y );
			v1[0] = x;
			v1[1] = y;
			vov1.pb(v1);
		}
		REP( j, m ) {
			scanf( "%lld %lld", &x, &y );
			v2[0] = x;
			v2[1] = y;
			vov2.pb(v2);
		}
		FOR( j, 1, m ) {
			FOR( k, 1, n ) {
				sum = max( a[j][k-1], a[j-1][k] );
				//cout << "\n" << vov1[k][1] << ", " <<  vov2[j][1] << "\n";
				if( vov1[k][1] == vov2[j][1] ) {
					x = min( vov1[k][0], vov2[j][0] );
					sum = sum + x;
					vov1[k][0] -= x;
					vov2[j][0] -= x;
				}
				ans = max( ans, sum );
				a[j][k] = sum;
				//cout << "sum = " << sum << " ";
			}
			//cout << "\nsum = " << sum << "\n";
		}
		printf( "Case #%d: %lld\n", i, ans );
	}
	return 0;
}
