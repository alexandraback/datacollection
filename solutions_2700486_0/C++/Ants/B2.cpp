#include <iostream>
#include <algorithm>

using namespace std;

double probs[ 256 ][ 257 ] = ... //genereted by combi.py

int main() {
	int T;
	cin >> T;
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(16);
	cerr.setf(ios::fixed, ios::floatfield);
	cerr.precision(16);

	for (int t = 1; t <= T; t++) {
		int N,X,Y;
		cin >> N >> X >> Y;
		if (X < 0) X = -X;
		int n = (X+Y)/2;
		int M = N - 2*n*n+n;
		int H = 2*n;
		int h = Y+1;
		double p;
		if (X == 0 && M < 4*n+1) p = 0.0;
		else if (M >= H+h) p = 1.0;
		else if (M < 0) p = 0.0;
		else p = probs[M][h];
		
		
		cout << "Case #" << t << ": " << p << endl;
	
		cerr << "X,Y = " << X << "," << Y << endl;
		cerr << "N = " << N << endl;
		cerr << "p = " << p << endl;
		cerr << "----------------------------------" << endl;
		cerr << "n = " << n << endl;
		cerr << "M = " << M << endl;
		cerr << "H = " << H << endl;
		cerr << "h = " << h << endl;
		cerr << "----------------------------------" << endl;
		
	}
	return 0;
}

