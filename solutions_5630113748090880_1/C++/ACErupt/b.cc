// run: $exec < b-large.in > b-large.out
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

int const maxn = 55;
int count[3000];
int a[maxn][maxn];
int n;

int main()
{
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		std::cout << "Case #" << ti << ":";
		std::memset(count, 0, sizeof(count));
		std::cin >> n;
		for (int i = 0, x; i < 2 * n - 1; i++)
			for (int j = 0; j < n; j++) {
				std::cin >> x;
				count[x]++;
			}
		std::vector<int> ans;
		for (int i = 0; i < 3000; i++)
			if (count[i] & 1) ans.push_back(i);
		std::sort(ans.begin(), ans.end());
		for (int i = 0; i < (int)ans.size(); i++)
			std::cout << ' ' << ans[i];
		std::cout << '\n';
	}
}

