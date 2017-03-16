#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;


	for (int t = 1; t <= T; t++) {
		int R, C, W;
		cin >> R >> C >> W;

		int hitrow = C/W;
		int sink = W;
		if (C%W == 0) sink--;

		cout << "Case #" << t << ": " << hitrow * R + sink << '\n';
	}

	return 0;
}
