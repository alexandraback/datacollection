#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

int64_t calc(int64_t r, int64_t t) {
	for (int64_t i = 0;; ++i) {
		int64_t m = 2 * (r + 2 * i) + 1;
		t -= m;
		if (t < 0)
			return i;
	}
	return 0;
}

void solve(istream &in, ostream &out) {
	int T;
	in >> T;

	for (int caseNumber = 1; caseNumber <= T; ++caseNumber) {
		int64_t r, t;
		in >> r >> t;

		out << "Case #" << caseNumber << ": " << calc(r, t) << endl;
	}
}

int main() {
	solve(cin, cout);
	return 0;
}

