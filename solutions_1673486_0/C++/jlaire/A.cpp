#include <iomanip>
#include <iostream>
#include <vector>

int main() {
	int T;
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		int A, B;
		std::cin >> A >> B;
		std::vector<double> p(A);
		for (int i = 0; i < A; ++i) {
			std::cin >> p[i];
		}
		double best = 1+B+1;
		double P = 1.0;
		for (int i = 0; i <= A; ++i) {
			best = std::min(best, P*(A-i+B-i+1) + (1-P)*(A-i+B-i+1+B+1));
			P *= p[i];
		}
		std::cout << std::setprecision(6) << std::fixed;
		std::cout << "Case #" << t << ": " << best << std::endl;
	}
}
