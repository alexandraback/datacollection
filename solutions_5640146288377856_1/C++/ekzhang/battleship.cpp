#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream in ("battleship.in");
	ofstream out("battleship.out");

	int T;
	in >> T;
	for (int tc = 1; tc <= T; tc++) {
		out << "Case #" << tc << ": ";
		int R, C, W;
		in >> R >> C >> W;
		if (W == 1) {
			out << R * C << endl;
			continue;
		}
		int ans1 = R * (C / W) + W;
		if (C % W == 0) {
			ans1--;
		}
		out << ans1 << endl;
	}

	return 0;
}
