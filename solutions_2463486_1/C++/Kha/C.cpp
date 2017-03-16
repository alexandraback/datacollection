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
	vector<long long> all;
	for (long long x = 1; x <= 111111111; x++)
		if (palin(x)) {
			auto s = x*x;
			if (palin(s))
				all.push_back(s);
		}

	for (int i = 0; i < t; i++) {
		long long a, b;
		cin >> a;
		int r = 0;
		if (cin.fail()) {
			cin.clear();
		} else {
			cin >> b;
			cin.clear();
			r = count_if(all.begin(), all.end(), [a,b](long long &x) { return a <= x && x <= b; });
		}

		cout << "Case #" << (i+1) << ": " << r << "\n";
	}
}
