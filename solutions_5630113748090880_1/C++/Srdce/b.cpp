#include<bits/stdc++.h>

using namespace std;

map < int , int > m;

int main() {
	int t;
	cin >> t;
	for( int ca = 1 ; ca <= t ; ca++ ) {
		int n , x;
		cin >> n;
		m.clear();
		for( int i = 1 ; i < 2*n ; i++ )
			for( int j = 1 ; j <= n ; j++ ) {
				cin >> x;
				m[x]++;
			}
		cout << "Case #" << ca << ": ";
		for( map < int , int > :: iterator it = m.begin() ; it != m.end() ; it++ )
			if( it->second&1 )
				cout << it->first << " ";
		cout << endl;
	}
	return 0;
}
