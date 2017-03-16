#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

bool check(char s[4][5], char c) {
	int cnt1[5], cnt2[5];
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	int p1 = 0, p2 = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
			if (s[i][j] == c || s[i][j] == 'T') {
				++cnt1[i];
				++cnt2[j];
				if (i == j) ++p1;
				if (i + j == 3) ++ p2;	
			}
	}
	if (p1 == 4 || p2 == 4) return true;
	for (int i = 0; i < 4; ++i)
		if (cnt1[i] == 4 || cnt2[i] == 4) return true;
	return false;
}

int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("a1.out", "w", stdout);

	int nc;
	cin >> nc;
	for (int cs = 1; cs <= nc; ++cs) {
		char s[4][5];
		bool full = true;
		for (int i = 0; i < 4; ++i) {
			cin >> s[i];
			for (int j = 0; j < 4; ++j)
				if (s[i][j] == '.') full = false;
		}
		bool o = check(s, 'O');
		bool x = check(s, 'X');
		cout << "Case #" << cs << ": ";
		if (o || x) {
			cout << (o ? 'O' : 'X') << " won" << endl;
		} else {
			cout << (full ? "Draw" : "Game has not completed") << endl;
		}
	}
}
