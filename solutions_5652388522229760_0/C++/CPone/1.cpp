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
	int n;
	std::cin >> n;
	if (n == 0) {
		std::cout << "INSOMNIA";
		return;
	}
	std::vector<char> digits(10);
	int count = 0;
	int x = 0;
	while (count < 10) {
		x += n;
		int y = x;
		while (y) {
			int d = y % 10;
			if (!digits[d]) {
				digits[d] = true;
				count++;
			}
			y /= 10;
		}
	}
	std::cout << x;
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
