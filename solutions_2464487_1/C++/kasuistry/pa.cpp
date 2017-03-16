
#include <iostream>
#include <gmpxx.h>

using namespace std;

int main(){
	
	mpz_class a, b;
	mpz_class x, y, n;
	int t; cin >> t;

	for(int testcase=1; testcase<=t; ++testcase){
		cin >> a >> b;
		a *= 2;
		y = b;
		x = 0;

		while(x < y-1){
			n = (x+y)/2;
			if(n*(a+2*n-1) <= b){
				x = n;
			}else{
				y = n;
			}
		}
		
		cout << "Case #" << testcase << ": " << x << endl;
	}
	return 0;
}
