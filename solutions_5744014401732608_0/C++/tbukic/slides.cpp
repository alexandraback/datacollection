#include <iostream>
#include <string>
#include <vector>

int main() {

	int t;
	
	std::cin >> t;

	for (int i = 0; i < t; ++i) {
		int b;
		long long m, max;
		std::cin >> b >> m;
		
		max = b;
		max = (max - 2)*(max - 1) / 2 + 1;
		if (max < m) {
			std::cout << "Case #" << i + 1 << ": IMPOSSIBLE" << std::endl;
		} else {
			std::cout << "Case #" << i + 1 << ": POSSIBLE" << std::endl;
			
			long long paths = 1;
			for (int row = 1; row < b; ++row) {
				for (int column = 0; column < row; ++column) {
					std::cout << '0';
				}
				for (int column = row + 1; column < b; ++column) {
					if (paths < m) {
						++paths;
						std::cout << '1';
					} else {
						std::cout << '0';
					}
				}
				std::cout << '1' << std::endl;
			}
			
			for (int i = 0; i < b; ++i) {
				std::cout << '0';
			}
			std::cout << std::endl;
		
		}
		
	}

	return 0;
}
