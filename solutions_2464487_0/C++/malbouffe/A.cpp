#include <iomanip>
#include <iostream>
#include "Debug.h"
using namespace std;

const double PI = 4 * atan(1.0);

int I, T;
long double r, t;
long double R;
long double A, B, C, DELTA;

void print() {
	cout << "Case #" << I << ": " << R << endl;
}

void read() {
	cin >> r >> t;
	A = 2.0;
	B = 2.0*r-1.0;
	C = -1.0*t;
	DELTA = B*B - 4*A*C;
}

long double difference(long double n) {
	return A*n*n+B*n+C;
}

void solve() {
	R = floor((0.5*(-B+sqrt(DELTA))/(A)))+1;
	while (difference(R)>0) R--;
}

void main() {
	cin >> T;
	cout << fixed << setprecision(0);
	I = 0;
	while (I++<T) {
		read();
		solve();
		print();
	}
}
