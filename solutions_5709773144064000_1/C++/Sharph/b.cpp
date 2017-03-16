// Compiler: g++-4.8 (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
// Flags: -O2 -Wall -g -std=c++0x
// Aina häviää

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	
	int T;
	cin >> T;
	
	cout.precision(15);
	for(int t = 0; t < T; ++t) {
		double C, F, X;
		cin >> C >> F >> X;
		
		double ret;
		if(C >= X) {
			ret = X / 2.0;
		} else {
			int n = ceil(X / C - 2.0 / F - 1);
			ret = (X - C) / (2.0 + (double)n * F);
			for(int i = n; i >= 0; --i) {
				ret += C / (2.0 + (double)i * F);
			}
		}
		
		cout << "Case #" << t + 1 << ": " << ret << "\n";
	}
	
	return 0;
}
