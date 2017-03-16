#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <tuple>
#include <functional>

using namespace std;

typedef long long tl; //type long
int _tc;

#define LEN(x) (sizeof(x) / sizeof(*x))
#define ABS(x) ((x > 0) ? (x) : -(x))

bool testCase() {
	int b;
	tl m;
	cin >> b >> m;
	tl c = m;
	if (m > (1ll << max(b - 2, 0))) {
		return false;
	}
	cout << "POSSIBLE" << endl;
	for (int i = 0; i < b; ++i) {
		tl a = c;
		tl sum = 0;
		for (int j = 0; j < b; ++j) {
			if (j > i) {			
				tl digit = (1ll << max(b - j - 2, 0));
				//cerr << digit << endl;
				if (a >= digit) {
					a -= digit;
					cout << 1;
					continue;
				}
			}
			cout << 0;
		}
		c = c;
		cout << endl;
	}
	return true;
}

int main(){
	int ntc;

	cin >> ntc;
	//cerr << "tests " << n << endl;
	for (int _tc = 0; _tc < ntc; ++_tc) {
		cout << "Case #" << (_tc + 1) << ": ";
		if (!testCase()) {
			cout << "IMPOSSIBLE" << endl;
		}
		//cout << endl;
	}
	return 0;
}