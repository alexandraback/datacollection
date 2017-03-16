#include <set>
#include <iostream>
#include <string>
#include <vector>
 	
unsigned long long generate(int base, std::vector<int>& digits) {
	// std::cout << "generating from";
	// for (auto r : digits)
	// 	std::cout << " " << r;
	// std::cout << std::endl;

	unsigned long long res = 0;
	for (int& i : digits) {
		res *= base;
		res += (i-1);
	}

	return res+1;
}

int main() {
	int t;
	std::cin >> t;

	for (int tid = 1; tid <= t; ++tid) {
		int k, c, s;
		std::cin >> k >> c >> s;
	
		if (k > c * s) {
			std::cout << "Case #" << tid << ": IMPOSSIBLE" << std::endl;
			continue;
		}

		std::vector<unsigned long long> res;

		int porcja = c;
		int przerobione = 0;
		while (przerobione < k) {
			std::vector<int> nowe;
			// if (k - przerobione < porcja)
			// 	for (int i = 0; i < porcja - (k - przerobione); ++i)
			// 		nowe.push_back(0);
			for (int i = 0; i < porcja; ++i) {
				if (przerobione + i == k)
					break;

				nowe.push_back(przerobione + i + 1);
			}
			res.push_back(generate(k, nowe));

			przerobione += porcja;
		}

		std::cout << "Case #" << tid << ":";
		for (unsigned long long r : res)
			std::cout << " " << r;
		std::cout << std::endl;
	}
}