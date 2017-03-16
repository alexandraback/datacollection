#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

typedef unsigned long long ull;

int main() {
	
	int t;
	std::cin >> t;

	for (int test = 0; test < t; ++test) {
		std::cout << "Case #" << (test + 1) << ": ";

		unsigned long long B, M;
		std::cin >> B >> M;

		unsigned long long max = 1;
		for (int i = 0; i < B - 2; ++i)
			max *= 2;

		if (M > max) {
			std::cout << "IMPOSSIBLE" << std::endl;
			continue;
		}

		std::cout << "POSSIBLE" << std::endl;

		std::vector<bool> bits;
		bits.push_back(M == max);
		if (M == max)
			M--;
		for (int i = 1; i < B; ++i) {
			bits.push_back(M % 2);
			M /= 2;
		}
		std::reverse(bits.begin(), bits.end());

		for (bool b : bits)
			std::cout << (b ? '1' : '0');
		std::cout << std::endl;

		for (int i = 1; i < B - 1; ++i) {
			for (int j = 0; j < B; ++j) {
				if (i >= j)
					std::cout << '0';
				else
					std::cout << '1';
			}
			std::cout << std::endl;
		}

		for (int j = 0; j < B; ++j)
			std::cout << '0';
		std::cout << std::endl;
	}

}