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

		std::string str;
		std::getline(std::cin, str);

		int numFlips = 0;
		for (size_t j=1; j < str.size(); j++) {
			if (str[j-1] != str[j])
				++numFlips;
		}
		if (str.back() == '-')
			++numFlips;

		std::cout << numFlips;
		std::cout << "\n";
	}

	return 0;
}
