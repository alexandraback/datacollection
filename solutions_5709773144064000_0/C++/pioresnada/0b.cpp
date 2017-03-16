#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
using namespace std;
int main() {
	int t; cin >> t;
	double c, f, x, s, r;
	for (int i = 0; i < t; ++i) {
		cin >> c >> f >> x;
		s = 0; r = 2;
		while (c/r + x/(r+f) < x/r) {
			s += c/r;
			r += f;
		}
		printf("Case #%d: %.7f\n", i+1, s + x/r);
	}
}
