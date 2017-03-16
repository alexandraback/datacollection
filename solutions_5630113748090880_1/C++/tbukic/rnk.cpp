#include <iostream>
#include <string>
#include <deque>

int main() {
	int t;
	std::cin >> t;
	
	const int LIMIT = 2500;
	int n, max, h;
	int heights[LIMIT];
	
	for (int i = 0; i < t; ++i) {
	
		std::cin >> n;
		
		// init
		for (int i = 0; i < LIMIT; ++i) {
			heights[i] = 0;
		}
		
		max = n*(2*n - 1);
		for (int i =0; i < max; ++i) {
			std::cin >> h;
			heights[h - 1]++;
		}
		
		std::cout << "Case #" << i + 1 << ":";
		for (int i = 0; i < LIMIT; ++i) {
			if (heights[i]%2 > 0) {
				std::cout << " " << i + 1;
			}
		}
		std::cout << std::endl;
	}

	return 0;
}
