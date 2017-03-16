#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<__int64> v;
	for ( __int64 i = 1; i <= 10000000; i++ ) {
		char buf[32];
		sprintf( buf, "%lld", i );
		int j, n = strlen(buf);
		for ( j = 0; j*2 < n; j++ ) {
			if ( buf[j] != buf[n-j-1] ) break;
		}
		if ( j*2 < n ) {
			continue;
		}

		sprintf( buf, "%lld", i*i );
		j, n = strlen(buf);
		for ( j = 0; j*2 < n; j++ ) {
			if ( buf[j] != buf[n-j-1] ) break;
		}
		if ( j*2 < n ) {
			continue;
		}

		v.push_back(i*i);
	}

	int T;
	cin >> T;
	for ( int t = 1; t <= T; t++ ) {
		__int64 A, B;
		cin >> A >> B;
		printf( "Case #%d: %d\n", t, upper_bound(v.begin(),v.end(),B) - lower_bound(v.begin(),v.end(),A) );
	}
	return 0;
}
