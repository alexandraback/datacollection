
#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int test = 1; test <= T; test++) {
		int R, C, W;
		cin >> R >> C >> W;

		int score = 0;

		// rule out all but one row
		score += (R - 1) * (C/W);

		// rule out all but the final slot
		score += C/W - 1;

		int final_slot = C - (C/W - 1)*W;

		if (final_slot == W)
			score += W;
		else
			score += W + 1;

		printf("Case #%d: %d\n", test, score);
	}
}