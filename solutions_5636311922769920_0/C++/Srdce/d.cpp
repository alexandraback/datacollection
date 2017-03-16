#include<bits/stdc++.h>

using namespace std;

int main() {
	long long t , k , c , s;
	cin >> t;
	for( int ca = 1 ; ca <= t ; ca++ ) {
		cin >> k >> c >> s;
		cout << "Case #" << ca << ":";
		if( k == 1 ) {
			cout << " 1" << endl;
			continue;
		}
		if( k/c+!!(k%c) > s ) {
			cout << " IMPOSSIBLE" << endl;
			continue;
		}
		long long cur = 0;
		for( int i = 0 ; i < k ; i++ ) {
			cur = cur*k+i;
			if( i%c == c-1 ) {
				cout << " " << cur+1;
				cur = 0;
			}
		}
		if( cur )
			cout << " " << cur+1;
		cout << endl;
	}
	return 0;
}
