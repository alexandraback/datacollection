#include <iostream>
#include <string>

using namespace std;

const int SMALL_MAXN = 1000;

string toStr(const int len, int val) {
	string vstr;

	for (int i = 0; i < len; ++i) {
		vstr = (char)('0' + (val % 10)) + vstr;
		val /= 10;
	}

	return vstr;
}

bool match(const string& pat, int val) {
	const int len = (int) pat.size();
	string vstr;

	for (int i = 0; i < len; ++i) {
		vstr = (char)('0' + (val % 10)) + vstr;
		val /= 10;
	}

	if (0 != val) {
		return false;
	}

	for (int i = 0; i < len; ++i) {
		if ('?' == pat[i]) {
			continue;
		}

		if (pat[i] != vstr[i]) {
			return false;
		}
	}

	return true;
}

void solve(const int t) {
	string C;
	string J;

	cin >> C >> J;

	int dist = SMALL_MAXN;
	int cans = 0;
	int jans = 0;

	for (int c = 0; c < SMALL_MAXN; ++c) {
		if (false == match(C, c)) {
			continue;
		}
		for (int j = 0; j < SMALL_MAXN; ++j) {
			if (match(J, j)) {
				const int cdist = abs(c - j);
				if (cdist < dist) {
					cans = c;
					jans = j;
					dist = cdist;
				}
			}
		}
	}
	const int len = (int)C.size();
	cout << "Case #" << t << ": " << toStr(len, cans) << ' ' << toStr(len, jans) << endl;
}

int main() {
	int T = 0;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		solve(i + 1);
	}

	return 0;
}
