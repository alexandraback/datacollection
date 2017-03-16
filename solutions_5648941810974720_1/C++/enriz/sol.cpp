#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long tl; //type long
int _tc;

#define LEN(x) (sizeof(x) / sizeof(*x))

char const * str[] = {
	"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

bool testCase() {
	std::string ss;
	cin >> ss;
	int result[10];

	int nz = std::count(ss.begin(), ss.end(), 'Z');
	result[0] = nz;
	int nx = std::count(ss.begin(), ss.end(), 'X');
	result[6] = nx;
	int ns = std::count(ss.begin(), ss.end(), 'S');
	result[7] = ns - nx;
	int ng = std::count(ss.begin(), ss.end(), 'G');
	result[8] = ng;
	int nf = std::count(ss.begin(), ss.end(), 'F');
	result[4] = std::count(ss.begin(), ss.end(), 'U');
	result[5] = std::count(ss.begin(), ss.end(), 'V') - result[7];
	result[3] = std::count(ss.begin(), ss.end(), 'H') - result[8];
	result[2] = std::count(ss.begin(), ss.end(), 'W');
	result[9] = std::count(ss.begin(), ss.end(), 'I') - result[5] - result[6] - result[8];
	result[1] = std::count(ss.begin(), ss.end(), 'N') - result[7] - result[9] * 2;
	for (unsigned int i = 0; i < LEN(result); ++i) {
		for (int a = 0; a < result[i]; ++a) {
			cout << i;
		}
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
			cout << " IMPOSSIBLE";
		}
		cout << endl;
	}
	return 0;
}