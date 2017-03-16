#include <iostream>
#include <vector>

int main() {
	int T;
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		std::cin >> N;
		std::vector<int> one(N);
		std::vector<int> two(N);
		std::vector<int> done(N);
		for (int i = 0; i < N; ++i) {
			std::cin >> one[i] >> two[i];
		}
		int score = 0;
		int rounds = 0;
		while (score < 2*N) {
			++rounds;
			bool out = false;
			for (int i = 0; i < N; ++i) {
				if (done[i] < 2 && two[i] <= score) {
					score += 2 - done[i];
					done[i] = 2;
					out = true;
					break;
				}
			}
			if (out) {
				continue;
			}
			int max_two = -1;
			int best_i = -1;
			for (int i = 0; i < N; ++i) {
				if (done[i] < 1 && one[i] <= score) {
					if (best_i == -1 || two[i] > max_two) {
						best_i = i;
						max_two = two[i];
					}
				}
			}
			if (best_i == -1) {
				break;
			}
			++score;
			done[best_i] = 1;
		}
		std::cout << "Case #" << t << ": ";
		if (score == 2*N) {
			std::cout << rounds << std::endl;
		}
		else {
			std::cout << "Too Bad" << std::endl;
		}
	}
}
