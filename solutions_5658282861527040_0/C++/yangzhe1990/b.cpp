#include <iostream>

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int A, B, K;
		std::cin >> A >> B >> K;
		int count = 0;
		for (int a = 0; a < A; ++a)
			for (int b = 0; b < B; ++b)
				if ((a & b) < K)
					++count;
		std::cout << "Case #" << i + 1 << ": " << count << '\n';
	}
}
