#include <iostream>
#include <boost/math/special_functions/binomial.hpp>
using namespace std;
const bool debug = false;

int main() {
	int T;
	cin >> T;
	for(int c=1; c<=T; c++) {
		int N,X,Y;
		cin >> N >> X >> Y;
		if(X<0)
			X = -X;
		int n = (X+Y)/2;
		n = 2*n+1; // liczba diamentow przy podstawie
		int l = n/2; //dodatkowe diamenty po jednej stronie
		int M = ((1+n)*(2*l+1))/2;
		int m = ((n-1)*(2*l-1))/2;
		if(debug) {
			cout << "n="<<n<<", l="<<l<<endl;
			cout << "M="<<M<<", m="<<m<<endl;
		}
		cout << "Case #" << c <<": ";
		if(N >= M || X==0) {
			cout << 1 << endl;
			continue;
		}
		if(N < m) {
			cout << 0 << endl;
			continue;
		}
		int r = N-m;
		if(debug)
			cout << "r=" << r << endl;
		double p = 0;
		for(int i=Y+1; i<=r; i++) {
			p += boost::math::binomial_coefficient<double>(r, i) * pow(0.5, r);
		}
		if(Y+1==n)
			p = 0;
		cout << p << endl;

		//boost::math::binomial_coefficient<double>(10, 2);
		
	}
}


			
