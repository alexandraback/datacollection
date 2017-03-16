// run: $exec < a-small.in > a-small.out
#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		std::cout << "Case #" << ti << ": ";
		std::string s;
		std::cin >> s;
		std::string ans{s[0]};
		for (int i = 1; i < (int)s.size(); i++) {
			std::string t1 = std::string(1, s[i]) + ans;
			std::string t2 = ans + std::string(1, s[i]);
			ans = std::max(t1, t2);
		}
		std::cout << ans << '\n';
	}
}

