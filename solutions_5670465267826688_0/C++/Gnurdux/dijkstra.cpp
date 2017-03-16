#include <iostream>
using namespace std;

int prodtable[4][4] = { { 0, 1, 2, 3 }, { 1, 4, 3, 6 }, { 2, 7, 4, 1 }, { 3, 2, 5, 4 } };

int mult(int q1, int q2) {
	return prodtable[q1&3][q2&3]^((q1^q2) & 4);
}

struct step {
	int poss[25][25];
};

step operator*(step s1, step s2) {
	step ans;

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			ans.poss[i][j] = false;
			for (int k = 0; k < 25; k++) {
				ans.poss[i][j] = ans.poss[i][j] || (s1.poss[i][k] && s2.poss[k][j]);
			}
		}
	}
	return ans;
}

step multstep(int which) {
	step ans;
	for (int s = 0; s < 3; s++) {
		for (int n = 0; n < 8; n++) {
			for (int j = 0; j < 25; j++)
				ans.poss[8*s+n][j] = false;
			ans.poss[8*s+n][8*s+mult(n, which)] = true;
			if (mult(n, which) == s+1) ans.poss[8*s+n][8*(s+1)] = true;
		}
	}
	return ans;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		long long L, X;
		cin >> L >> X;

		step base = multstep(0);
		for (int i = 0; i < L; i++) {
			char c;
			cin >> c;
			base = base * multstep(c-'i'+1);
		}
		step ans = multstep(0);
		while (X > 0) {
			if (X&1) ans = ans * base;
			base = base * base;
			X /= 2;
		}
		cout << "Case #" << t << (ans.poss[0][24] ? ": YES\n" : ": NO\n");
	}

	return 0;
}
