
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <bitset>
#include <map>
#include <set>
using namespace std;

bool isConsonant(char c) {
	return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int64_t calc(const string &str, int n) {
	int s = 0, t = 0;
	int64_t sum = 0;
	int L = str.size();
	int numConsonants = 0;
	for (;;) {
		while (numConsonants < n && s < L)
			if (isConsonant(str[s++]))
				++numConsonants;
			else
				numConsonants = 0;
		if (numConsonants < n)
			break;
		sum += L - s + 1;
		if (s - ++t < n)
			--numConsonants;
	}
	return sum;
}

void solve(istream &in, ostream &out) {
	int T;
	in >> T;

	for (int t = 1; t <= T; ++t) {
		string str;
		int n;
		in >> str >> n;

		out << "Case #" << t << ": " << calc(str, n) << endl;
	}
}

int main() {
	solve(cin, cout);
	return 0;
}
