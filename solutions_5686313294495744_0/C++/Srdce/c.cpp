#include<bits/stdc++.h>

using namespace std;

int t , n;
pair < string , string > a[20];
set < string > m0 , m1;

int main() {
	cin >> t;
	for( int ca = 1 ; ca <= t ; ca++ ) {
		cin >> n;
		for( int i = 0 ; i < n ; i++ )
			cin >> a[i].first >> a[i].second;
		int ans = 0;
		for( int i = 0 ; i < (1<<n) ; i++ ) {
			int tot = 0;
			m0.clear();
			m1.clear();
			for( int j = 0 ; j < n ; j++ )
				if( i&(1<<j) )
					tot++;
				else {
					m0.insert( a[j].first );
					m1.insert( a[j].second );
				}
			bool flag = 1;
			for( int j = 0 ; j < n ; j++ )
				if( i&(1<<j) )
					flag &= m0.find( a[j].first ) != m0.end() && m1.find( a[j].second ) != m1.end();
			if( flag )
				ans = max( ans , tot );
		}
		cout << "Case #" << ca << ": " << ans << endl;
	}
	return 0;
}
