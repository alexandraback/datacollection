#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int nTest; cin >> nTest;
	for(int i = 0; i < nTest; ++i) {
		double c, f, x; cin >> c >> f >> x;
		double res = 1e9, rate = 2, time = 0;
		while(time + x / rate + 1e-9 < res) {
			res = time + x / rate;
			time += c / rate;
			rate += f;
		}
		printf("Case #%d: %.12lf\n", i + 1, res);
	}
	return 0;
}
