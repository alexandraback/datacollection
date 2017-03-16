#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int solve(int kase) {
	long double r, t;
	cin >> r >> t;
	long double N = 0; //-5.0L/4.0L + sqrt((3.L+2.L*r)*(3.L+2.L*r)+8.L*t)/4.0L;
	int i;
	t*=M_PI;
	for (i = 0; N <= t; ++i) {
		N += M_PI * ((r + 2*i+1)*(r+2*i+1) - (r+2*i)*(r+2*i));
	}
	cout << i-1<< endl;
}

int main() {
	int t;
	cin >> t;
	for (int kase = 1; kase <= t; ++kase) {
		cout << "Case #" << kase << ": ";
		solve(kase);
	}
}
