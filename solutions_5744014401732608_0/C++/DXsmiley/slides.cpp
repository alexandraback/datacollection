#include <iostream>

int T, B, M;

long long int ways[5000];
long long int choice[5000];

int main() {
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		std::cin >> B >> M;
		ways[B - 1] = 1;
		choice[B - 1] = 0;
		for (int i = B - 2; i >= 0; --i) {
			choice[i] = 0;
			ways[i] = 0;
			for (int j = B - 1; j > i; --j) {
				if (ways[i] + ways[j] <= M) {
					ways[i] += ways[j];
					choice[i] |= (1 << j);
				}
			}
		}
		std::cout << "Case #" << t << ": ";
		if (ways[0] == M) {
			std::cout << "POSSIBLE\n";
			for (int i = 0; i < B; ++i) {
				for (int j = 0; j < B; ++j) {
					if ((1 << j) & choice[i]) {
						std::cout << "1";
					} else {
						std::cout << "0";
					}
				}
				std::cout << "\n";
			}
		} else {
			std::cout << "IMPOSSIBLE\n";
		}
	}
}