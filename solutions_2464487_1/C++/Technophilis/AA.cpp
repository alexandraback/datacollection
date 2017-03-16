#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
	ifstream in("A-large.in");
	//ifstream in("A-small.in");
	//ifstream in("A.in");
	ofstream out("A-large.out");

	int T; in >> T;
	for (int x = 1; x <= T; x++) {

		long long n = 0;
		long long res = 0;

		long long t, r; in >> r >> t;

		long long l = 1LL, h = t;

		while (1) {
			n = ((l + h) / 2LL);

			if (t / n >= (2LL * n + (2LL * r - 1LL))) {
				res = n;
				l = n + 1;
			} else if (t / n < (2LL * n + (2LL * r - 1LL))) {
				h = n - 1;
			}

			if (h < l) break;
		}

		out << "Case #" << x << ": " << res << endl;
	}

	return 0;
}

