#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {

		int S_max;
		cin >> S_max;
		int h = 0, n = 0;
		for (int i = 0; i <= S_max; ++i) {
			char c;
			cin >> c;
			int nw = (int)(c - '0');
			if (h < i) {
				n += i - h;
				h = i;
			}
			h += nw;
		}

		cout << "Case #" << t << ": " << n << endl;
	}

	return 0;
}