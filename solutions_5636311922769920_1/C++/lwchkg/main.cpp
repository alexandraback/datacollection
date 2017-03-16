// Compile with TDM-GCC-64 5.1 with c++11 features

#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	int N;
	std::cin >> N;
	std::string str;
	std::getline(std::cin, str);

	for (int i=0; i < N; i++) {
		std::cout << "Case #" << (i+1) << ":";

		int k, c, s;
		cin >> k >> c >> s;
		int t = (k-1) / c + 1;
		if (t > s) {
			cout << " IMPOSSIBLE\n";
			continue;
		}

		for (int j = 0; j < k; j += c) {
			int64_t v = 1;
			int64_t pos = 0;
			for (int j2 = c - 1; j2 >= 0; --j2) {
				int64_t p = (j2 > k - j - 1) ? 0 : (j + j2);
				//cout << p << ":" << v << "#";
				pos += p * v;
				v *= k;
			}
			++pos;
			cout << " " << pos;
		}

		std::cout << "\n";
	}

	return 0;
}
