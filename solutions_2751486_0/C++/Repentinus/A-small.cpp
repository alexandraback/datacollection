#include <iostream>
#include <string>

using namespace std;

long long solve(string const& s, int n) {
	long long r = 0;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; i + j < s.size(); ++j) {
			int c = 0;
			for (int a = i; a <= i + j; ++a) {
				switch (s[a]) {
					case 'a':
					case 'e':
					case 'i':
					case 'o':
					case 'u':
						c = 0;
						break;
					default:
						++c;
				}
				if (c >= n) {
					++r;
					break;
				}
			}
		}
	}
	return r;
}

int main(int argc, char const* const* argv)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string s;
		int n;
		cin >> s >> n;
		cout << "Case #" << (i + 1) << ": " << solve(s, n) << endl;
	}
	return 0;
}
