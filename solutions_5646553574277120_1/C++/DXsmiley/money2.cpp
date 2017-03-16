#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <set>

int T, C, D, V;

bool possible[100];

int find() {
	for (int i = 0; i <= V; ++i) {
		if (!possible[i]) return i;
	}
	return 100;
}

void set(int value) {
	for (int i = V; i >= 0; --i) {
		if (possible[i]) {
			possible[i + value] = true;
		}
	}
}

int main() {
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cerr << t + 1 << " ";
		std::fill(possible, possible + 100, false);
		possible[0] = true;
		std::cin >> C >> D >> V;
		// std::vector<int> coins;
		std::set<int> coins;
		for (int i = 0; i < D; ++i) {
			int c;
			std::cin >> c;
			// coins.push_back(c);
			coins.insert(c);
		}
		int cost = 0;
		for (int i = 1; i <= V; i *= 2) {
			if (coins.count(i) == 0) {
				++cost;
			}
		}
		// std::sort(coins.begin(), coins.end());
		// int cp = 0, cost = 0;
		// coins.push_back(100);
		// while (true) {
		// 	int smallest = std::min(coins[cp], find());
		// 	if (smallest == 100) break;
		// 	if (smallest == coins[cp]) ++cp;
		// 	else ++cost;
		// 	set(smallest);
		// }
		std::cout << "Case #" << t + 1 << ": " << cost << '\n';
	}
}