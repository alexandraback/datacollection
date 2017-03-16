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
	int t, n, m, i, j, k, x, p, q;
	scanf( "%d", &t );
	FOR( i, 1, t ) {
		VI v;
		VVI vov;
		v.pb(0);
		vov.pb(v);
		v.clear();
		scanf( "%d", &n );
		REP( j, n ) {
			scanf( "%d", &m );
			while( m > 0 ) {
				scanf( "%d", &x );
				v.pb(x);
				m--;
			}
			if( v.size() == 0 ) v.pb(-1);
			vov.pb( v );
			v.clear();
			//puts("ok");
		}
		p = 0;
		FOR( j, 1, n ) {
			//cout << " :-" << vov[j][0] << "\n";
			if( vov[j][0] != -1 ) {
				//puts("***");
				int a[2000] = {0};
				VI tmp;
				tmp = vov[j];
				REP( k, tmp.size() ) a[tmp[k]] = 1;
				while( tmp.size() > 0 ) {
					x = tmp[0];
					//cout << "x = " << x << "\n";
					tmp.erase( tmp.begin() );
					if( vov[x][0] > 0 ) {
						REP( k, vov[x].size() ) {
							q = vov[x][k];
							//cout << "q = " << q << "\n";
							if( a[q] == 1 ) {
								p = 1;
								break;
							}
							a[q] = 1;
							tmp.pb( q );
						}
					}
				}
				if( p == 1 ) break;
			}
		}
		printf( "Case #%d: ", i );
		if( p == 1 ) puts("Yes");
		else puts("No");
	}
	return 0;
}
