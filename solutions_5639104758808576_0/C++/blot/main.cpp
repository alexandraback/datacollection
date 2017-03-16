#include <algorithm>
#include <cstdint>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>

using namespace std;

int solve(const string& s) {
	int c = 0;
	int res = 0;

	for (int i = 0; i < s.length(); ++i) {
		if (c < i) {
			res += (i - c);
			c = i;
		}
		c += s[i] - '0';
	}

	return res;
}

int main(int argc, char** argv)
{
	ifstream input("./in.txt");
	ofstream output("./out.txt");

	int T;
	input >> T;

	for (int i = 1; i <= T; ++i) {
		int s;
		string str;
		input >> s >> str;
		output << "Case #" << i << ": " << solve(str) << endl;
	}

	return 0;
}
