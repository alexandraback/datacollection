#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int rec_solve(int c, int w) {
	if (w == c) {
		return w;
	} else if (c < 2 * w) {
		return w + 1;
	} else {
		return 1 + rec_solve(c - w, w);
	}
}

int main() {
	int ncases;

	cin >> ncases;

	for (int cx = 1; cx <= ncases; cx++) {
		int result;

		int r, c, w;

		cin >> r >> c >> w;

		result = rec_solve(c, w) + (r-1) * (c / w);

		cout << "Case #" << cx << ": " << result << endl;
	}

	return 0;
}
