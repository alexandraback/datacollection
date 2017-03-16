#include<bits/stdc++.h>

using namespace std;

int status;

void seperate( long long x ) {
	while( x ) {
		status |= (1<<(x%10));
		x /= 10;
	}
}

int main() {
	int t;
	cin >> t;
	for( int ca = 1 ; ca <= t ; ca++ ) {
		long long n;
		cin >> n;
		cout << "Case #" << ca << ": ";
		status = 0;
		for( int i = 1 ; i <= 10000000 ; i++ ) {
			seperate( i*n );
			if( status == 1023 ) {
				cout << i*n << endl;
				break;
			}
		}
		if( status != 1023 )
			cout << "INSOMNIA" << endl;
	}
	return 0;
}
