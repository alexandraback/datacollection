
#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

int check(int a, int b, int n) {
	int res = 0;
	int digcount = (int)(log(n)/log(10)) + 1;
	set<int> ns;
	for (int i = 1; i < digcount; ++i) {
		int dec = pow(10, i);
		int dec2 = pow(10, digcount - i);
		int left = n / dec;
		int right = n % dec;
		int n1 = right * dec2 + left;
		if (n1 > n && n1 >= a && n1 <= b && ns.find(n1) == ns.end()) {
			ns.insert(n1);
			++res;
		}
	}
	return res;
}

int main(int argc, char argv[]) {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int res = 0;

		int a, b;
		cin >> a >> b;

		for (int j = a; j < b; ++j)
			res += check(a, b, j);

		cout << "Case #" << i + 1 << ": " << res << endl;
	}
	return 0;
}