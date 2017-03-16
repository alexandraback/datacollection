// run: $exec < d-small.in > d-small.out
#include <iostream>

int k, c, s;

int main()
{
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		std::cout << "Case #" << ti << ":";
		std::cin >> k >> c >> s;
		for (int i = 1; i <= k; i++) {
			long long t = i;
			for (int j = 2; j <= c; j++) t = (t - 1) * k + i;
			std::cout << ' ' << t;
		}
		std::cout << '\n';
	}
}

