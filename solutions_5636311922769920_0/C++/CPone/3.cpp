#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory>
#include <iterator>

void conquer() {
	uint64_t K, C, S;
	std::cin >> K >> C >> S;
	if (C*S < K) {
		std::cout << "IMPOSSIBLE";
		return;
	}
	uint64_t k(K);
	if (k%C) {
		k += C - k%C;
	}
	std::vector<uint64_t> vec(k);
	std::iota(vec.begin(), vec.begin() + K, 0);
	for (uint64_t j = 0; j < vec.size(); j += C) {
		uint64_t x = 0;
		for (uint64_t jj = j; jj < j + C; ++jj) {
			x *= K;
			x += vec[jj];
		}
		std::cout << (x + 1) << " ";
	}
}

int main(int argc, char **argv) {
	int T;
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		std::cout << "Case #" << t << ": ";
		conquer();
		std::cout << "\n";
	}
}
