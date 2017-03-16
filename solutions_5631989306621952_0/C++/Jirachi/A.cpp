#include <bits/stdc++.h>

int T;
std::string s;

int main() {
	freopen("A.in", "r", stdin);
	std::cin >> T;
	for (int cs = 1; cs <= T; cs++) {
		std::cin >> s;
		printf("Case #%d: ", cs);
		std::string answer;
		for (int i = 0; i < (int)s.length(); i++) {
			answer = std::max(s[i] + answer, answer + s[i]);
		}
		std::cout << answer << std::endl;
	}
	return 0;
}
