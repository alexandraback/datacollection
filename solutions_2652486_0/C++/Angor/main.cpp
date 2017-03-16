#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <iostream>

using namespace std;

int conf[6];
int maxTwos;

int main()
{
	freopen( "data.in", "r", stdin );
	freopen( "data.out", "w", stdout );
	
	int t;
	cin >> t;
	for(  int kk = 0; kk < t; kk++ ) {
		printf( "Case #%d:\n", kk + 1 );
		int r, n, m, k;
		cin >> r >> n >> m >> k;
		for( int rr = 0; rr < r; rr++ ) {
			for( int i = 0; i <= m; i++ ) {
				conf[i] = 0;
			}
			maxTwos = 0;
			vector<int> prod;
			prod.resize( k );
			for( int i = 0; i < k; i++ ) {
				cin >> prod[i];
				for( int j = 2; j <= m; j++ ) {
					int cnt = 0;
					int num = prod[i];
					while( num % j == 0 ) {
						num /= j;
						cnt++;
					}
					if( j != 2 && j != 4 ) {
						conf[j] = max( conf[j], cnt );
					} else if ( j == 2 && cnt % 2 ) {
						conf[j] = 1;
						maxTwos = max( maxTwos, cnt - 1 );
					} else {
						maxTwos = max( maxTwos, cnt );
					}
				}
			}
			int cnt = 0;
			
			for( int i = 2; i <= m; i++ ) {
				cnt += conf[i];
			}
			if( cnt == n ) {
				for( int i = 2; i <=m; i++ ) {
					for( int j = 0; j < conf[i]; j++ ) {
						cout << i;
					}
				}
				cout << endl;
			} else if( cnt == n-1 && maxTwos > 0 ) {
				for( int i = 2; i <=m; i++ ) {
					for( int j = 0; j < conf[i]; j++ ) {
						cout << i;
					}
				}
				cout << 2 * maxTwos;
				cout << endl;
			} else {
				for( int i = 2; i <=m; i++ ) {
					for( int j = 0; j < conf[i]; j++ ) {
						cout << i;
					}
				}
				int r = n - cnt;
				while( r < maxTwos ) {
					cout << '4';
					r--;
					maxTwos-=2;
				}
				while( r > 0 ) {
					cout << '2';
					r--;
				}
				cout << endl;
			}
		}
	}



	return 0;
}