#include <iostream>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
int length(int n) {
	int count = 0;
	while(n > 0 ) {
		n = n/10;
		count++;
	}
	return count;
}
int main() {
	int T;
	int A,B,x,xlen,xpow,count;
	cin >> T;
	for ( int i = 1; i <= T; i++ ) {
		count = 0;
		cin >> A >> B;
		xlen = length(A);
		xpow = pow(10,xlen-1);
		for (x= A; x < B; x++ ) {
			int temp = x;
			set<int> myset;
			for ( int j = 0; j < xlen; j++ ) {
				x = (x%10) * xpow + x/10 ;
				if ( x > temp && x <= B && (myset.find(x) == myset.end())){
					myset.insert(x);
					count++;
				}
			}
		}
		cout << "Case #" << i << ": " << count << endl;
	}
}
