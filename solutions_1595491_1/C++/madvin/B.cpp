#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	int s,p,N,threshold,v;
	int r,rs;
	for ( int i = 1; i <= T; i++ ) {
		cin >> N >> s >> p;
		threshold = 3*(p-1);
		r = rs = 0;
		for ( int j = 0; j < N; j++ ) {
			cin >> v;
			if ( v > threshold ) {
				r++;
			}
			else if (v == threshold - 1 || (v == threshold && p > 1)) {
				rs++;
			}
		}
		if (s < rs) {
			rs = s;
		}
		cout << "Case #" << i << ": " << r + rs << endl;
	}
	
}
