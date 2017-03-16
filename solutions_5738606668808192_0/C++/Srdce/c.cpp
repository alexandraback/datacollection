#include<bits/stdc++.h>

using namespace std;

int main() {
	int t , n , j;
	freopen( "c.out" , "w" , stdout );
	cin >> t >> n >> j;
	cout << "Case #1:" << endl;
	for( int i = 0 ; i < j ; i++ ) {
		cout << 1;
		int k = 0 , t = i;
		while( t ) {
			cout << (t&1) << (t&1);
			t >>= 1;
			k++;
		}
		for( ; k+1 < n/2 ; k++ )
			cout << "00";
		cout << 1;
		for( int k = 2 ; k <= 10 ; k++ )
			cout << " " << k+1;
		cout << endl;
	}
	return 0;
}
