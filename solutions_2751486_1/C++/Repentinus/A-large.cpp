#include <iostream>
#include <string>

using namespace std;

long long solve(string const& s, int n) {
	long long r = 0;
	int c = 0, d = 0;
	for (int i = 0; i < s.size(); ++i) {
		switch (s[i]) {
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
			r += (i - n - d + 2) * (s.size() - i);
			d = i - n + 2;
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
