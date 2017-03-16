// Compile with TDM-GCC-64 5.1 with c++11 features

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
		std::cout << "Case #" << (i+1) << ": ";

		int x;
		cin >> x;
		if (x == 0) {
			cout << "INSOMNIA\n";
			continue;
		}

		std::vector<bool> digitsSeen(10, false);
		for (int nx = x; ; nx += x) {
			for (int a = nx; a > 0; a /= 10) {
				int r = a % 10;
				digitsSeen[r] = true;
			}
			bool allDigitsSeen = true;
			for (bool digitSeen : digitsSeen)
				if (!digitSeen)
					allDigitsSeen = false;
			if (allDigitsSeen) {
				std::cout << nx;
				break;
			}
		}

		std::cout << "\n";
	}

	return 0;
}
