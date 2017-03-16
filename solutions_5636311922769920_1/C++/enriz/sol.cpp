#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

long long k, c, s;

bool isG(long long idx, long long p) {
	long long gc = 0;
	while (gc < c) {
		if (idx % k == p || idx == p)
			return true;
		idx /= k;
		++gc;
	}
	return false;
}

long long pow(long long a, long long b) {
	long long rt = 1;
	while (b > 0) {
		rt *= a;
		--b;
	}
	return rt;
}

long long computeC(long long st, long long ed) {
	long long rt = 0;
	for (long long i = 0; i + st <= ed; ++i) {
		rt += (i + st) * pow(k, ed - st - i);
	}
	return rt;
}

#define MIN(x, y) ((x) < (y) ? (x) : (y))

bool testCase() {
	if (k > s * c) {
		return false;
	}
	for (long long i = 0; i < k; ){
		long long maxn = MIN(i + c - 1, k - 1);
		cout << " " << (computeC(i, maxn) + 1); //+1 since index starts with 1
		i = maxn + 1;
	}
	return true;
}

int main(){
	long long n;

	cin >> n;
	//cerr << "tests " << n << endl;
	for (long long i = 0; i < n; ++i) {
		cin >> k >> c >> s;

		cout << "Case #" << (i + 1) << ":";
		if (!testCase()) {
			cout << " IMPOSSIBLE";
		}
		cout << endl;
	}
	return 0;
}