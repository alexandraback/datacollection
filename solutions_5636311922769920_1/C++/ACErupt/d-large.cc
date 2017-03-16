// run: $exec < d-large.in > d-large.out
#include <iostream>

long long k, c, s;

int main()
{
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		std::cout << "Case #" << ti << ":";
		std::cin >> k >> c >> s;
		int r = (k + std::min(k, c) - 1) / std::min(k, c);
		if (s < r) { std::cout << " IMPOSSIBLE\n"; continue; }
		long long now = 1;
		for (int i = 1; i <= r; i++) {
			long long t = std::min(now, k);
			for (int j = 2; j <= c; j++)
				t = (t - 1) * k + std::min(k, now + j - 1);
			now += c;
			std::cout << ' ' << t;
		}
		std::cout << '\n';
	}
}

