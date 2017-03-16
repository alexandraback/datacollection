#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <iostream>

using namespace std;

int dyn[6][11];
__int64 e, r, n;
vector<int> v;

int solve( int ce, int cn )
{
	if( cn >= n ) {
		return 0;
	}
	int& ans = dyn[ce][cn];
	if( ans != -1 ) {
		return ans;
	}
	ans = 0;
	for( int de = 0; de <= ce; de++ ) {
		int temp = de * v[cn] + solve( min( e, ce - de + r ), cn + 1 );
		ans = max( ans, temp );
	}
	return ans;
}

int main()
{
	freopen( "data.in", "r", stdin );
	freopen( "data.out", "w", stdout );
	
	int t;
	cin >> t;
	for(  int k = 0; k < t; k++ ) {
		cin >> e >> r >> n;
		v.clear();
		v.resize( n );
		for( int i = 0; i < n; i++ ) {
			int num;
			scanf( "%d", &(v[i]) );
		}
		
		for( int i = 0; i <= e; i++ ) {
			for( int j = 0; j <= n; j++ ) {
				dyn[i][j] = -1;
			}
		}
		int ans = solve( e, 0 );
		printf( "Case #%d: ", k + 1 );
		cout << ans << endl;
	}



	return 0;
}