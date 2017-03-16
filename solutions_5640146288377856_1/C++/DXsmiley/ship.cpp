#include <iostream>

int T, R, C, W;

int main() {
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		int score = 0;
		std::cin >> R >> C >> W;
		while (R > 1) {
			--R;
			score += C / W;
		}
		while (C > W * 2 - 1) {
			C -= W;
			score += 1;
		}
		if (C == W) {
			score += W;
		} else {
			score += W + 1;
		}
		std::cout << "Case #" << t << ": " << score << '\n';
	}
}