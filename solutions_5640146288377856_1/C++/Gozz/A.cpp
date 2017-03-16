#include <iostream>
#include <vector>
#include <cstdint>

typedef int64_t i64;

using namespace std;

int main() {
	i64 T;
	cin >> T;
	for (i64 t = 1; t <= T; ++t) {
		i64 R, C, W;
		cin >> R >> C >> W;

		i64 score = 0;
		score += R * C/W;
		score += W-1;
		if (C%W)
			++score;

		cout << "Case #" << t << ": " << score << endl;
	}
	return 0;
}
