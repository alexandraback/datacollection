#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

void init() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    init();
	int t;
	cin >> t;
	rep(tt, t) {
		int n, m, k;
		cin >> n >> m >> k;
		if( m < n ) swap(n, m);
		int c=0, r=0;
		for(int i=2; i<=(k+4)/2; i++) {
			if( (k+4) % i == 0 ) {
				c = i;
				r = (k+4) / i;
				if( r < c )  swap(c, r);
				if( c<n && r<m )  break;
			}
		}
		cout << "Case #" << (tt+1) << ": ";
		if( c < 2 || r < 2 ) {
			cout << k << endl;
		} else {
			cout << 2*(c-2) + 2*(r-2) << endl;
		}
	}
	return 0;
}
