
#include <iostream>

int main(void) {
	int T;
	int K;
	int C;
	int S;

	int loop;
	int gold;
	long long res;

	std::cin >> T;
	for (int i = 0; i < T; i++) {
		std::cin >> K >> C >> S;
		std::cout << "Case #" << i + 1 << ":";
		loop = (K - 1) / C + 1;
		if (loop > S) std::cout << " IMPOSSIBLE" << std::endl;
		else {
			gold = 0;
			for (int i = 0; i < loop; i++) {
				res = gold;
				gold++;
				for (int j = 1; j < C; j++) {
					if (gold >= K) {
						for (int k = j; k < C; k++) res *= K;
						break;
					}
					else {
						res = res * K + gold;
						gold++;
					}
				}
				std::cout << ' ' << res + 1;
			}
			std::cout << std::endl;
		}
	}
	return 0;
}