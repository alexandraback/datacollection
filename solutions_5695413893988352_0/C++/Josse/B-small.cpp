#include <iostream>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

unsigned l;

struct solution {
	int c, j;
	bool operator<(const solution& other) const {
		if (abs(c - j) != abs(other.c - other.j))
			return abs(c - j) < abs(other.c - other.j);
		if (c != other.c)
			return c < other.c;
		return j < other.j;
	}
	friend ostream& operator<<(ostream& os, const solution& s) {
		char tmp[30];
		sprintf(tmp, "%0*d %0*d", (int) l, s.c, (int) l, s.j);
		os << tmp;
		return os;
	}
};

bool fits(const string& s, int x) {
	char tmp[30];
	sprintf(tmp, "%0*d", (int) l, x);
	assert(strlen(tmp) == l);
	for (unsigned i = 0; i < l; i++) {
		if (tmp[i] != s[i] && s[i] != '?')
			return false;
	}
	return true;
}

solution solve() {
	string C, J;
	cin >> C >> J;
	assert(C.size() >= 1 && C.size() <= 3);
	assert(C.size() == J.size());
	l = C.size();
	for (string::iterator it = C.begin(); it != C.end(); it++) {
		assert(isdigit(*it) || *it == '?');
	}
	for (string::iterator it = J.begin(); it != J.end(); it++) {
		assert(isdigit(*it) || *it == '?');
	}
	solution best = (solution) {-1, -1};
	int len[] = {1, 10, 100, 1000};
	for (int a = 0; a < len[l]; a++) {
		if (!fits(C, a)) continue;
		for (int b = 0; b < len[l]; b++) {
			if (fits(J, b)) {
				solution cur = (solution) {a, b};
				if (best.c == -1 || cur < best)
					best = cur;
			}
		}
	}
	return best;
}

int main() {
	int T;
	cin >> T;
	assert(T >= 1 && T <= 200);
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}
