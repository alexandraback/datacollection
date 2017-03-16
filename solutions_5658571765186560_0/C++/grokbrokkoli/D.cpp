#include <iostream>
#include <vector>

int main()
{
	int testCases;
	std::cin >> testCases;
	for (int t = 1; t <= testCases; ++t) {
		int x, r, c;
		std::cin >> x >> r >> c;
		if (r * c % x != 0) {
			std::cout << "Case #" << t << ": " << "RICHARD" << std::endl;
			continue;
		}
		if (x == 1) {
			std::cout << "Case #" << t << ": " << "GABRIEL" << std::endl;
			continue;
		}
		if (x == 2) {
			std::cout << "Case #" << t << ": " << "GABRIEL" << std::endl;
			continue;
		}
		if (x == 3) {
			if (r == 1 || c == 1) {
				std::cout << "Case #" << t << ": " << "RICHARD" << std::endl;
				continue;
			}
			else {
				std::cout << "Case #" << t << ": " << "GABRIEL" << std::endl;
				continue;
			}
		}
		if (x == 4) {
			if(r == 1 || c == 1 || r == 2 || c == 2) {
				std::cout << "Case #" << t << ": " << "RICHARD" << std::endl;
				continue;
			}
			else {
				std::cout << "Case #" << t << ": " << "GABRIEL" << std::endl;
				continue;
			}
		}
	}
}
