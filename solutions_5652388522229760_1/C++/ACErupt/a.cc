// run: $exec < a-large.in > a-large.out
#include <iostream>

bool vis[10];
long long n;

int main()
{
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		std::cout << "Case #" << ti << ": ";
		std::cin >> n;
		if (!n) { std::cout << "INSOMNIA\n"; continue; }
		int not_vis = 10;
		for (int i = 0; i < 10; i++) vis[i] = false;
		long long tn = 0;
		for (; not_vis; ) {
			tn += n;
			for (long long tmp = tn; tmp; tmp /= 10)
				if (!vis[tmp % 10]) {
					vis[tmp % 10] = true;
					not_vis--;
				}
		}
		if (not_vis) { std::cout << "INSOMNIA\n"; continue; }
		else std::cout << tn << '\n';
	}
}

