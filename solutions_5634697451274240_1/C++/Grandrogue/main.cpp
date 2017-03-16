#include <fstream>
#include <string>

using namespace std;

ifstream fin("B-large.in");
ofstream fout("out.txt");

int main() {
	int tests;
	fin >> tests;

	string s;
	for(int test = 0; test < tests; ++test) {
		fin >> s;
		int r = -1, ans = 0;
		for (int i = s.length() - 1; i >= 0; --i) {
			if (s[i] == '-') {
				r = i;
				break;
			}
		}

		while (r >= 0) {
			int l = -1;
			while (s[l + 1] == '+') {
				++l;
			}

			if (l >= 0) {
				for (int i = 0; i <= l; ++i) {
					s[i] = '-';
				}
				++ans;
			}

			for (int i = 0; i <= r / 2; ++i) {
				swap(s[i], s[r - i]);
			}

			for (int i = 0; i <= r; ++i) {
				s[i] = (s[i] == '+') ? '-' : '+';
			}

			++ans;
			
			while ((r >= 0) && (s[r] == '+')) {
				--r;
			}
		}

		fout << "Case #" << test + 1 << ": " << ans << endl;
	}

	return 0;
}
