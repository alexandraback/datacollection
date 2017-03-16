#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool palin(long long x) {
	string s = to_string(x);
	return equal(s.begin(), s.end(), s.rbegin());
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long a, b;
		cin >> a >> b;
		int r = 0;
		for (long long x = a; x <= b; x++)
			if (palin(x)) {
				auto s = (long long)sqrt(x);
				if (s*s == x && palin(s))
					r++;
			}
		cout << "Case #" << (i+1) << ": " << r << "\n";
	}
}
