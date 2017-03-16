// run: $exec < b-large.in > b-large.out
#include <iostream>
#include <string>

std::string s;

int main()
{
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		std::cout << "Case #" << ti << ": ";
		std::cin >> s;
		int t = 1;
		for (int i = 1; i < (int)s.size(); i++)
			if (s[i] != s[i - 1]) t++;
		if (s[s.size() - 1] == '+') t--;
		std::cout << t << '\n';
	}
}

