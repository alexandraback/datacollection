#include <iostream>
#include <vector>

using namespace std;

char NextC(char c1, char c2);
char PrevC(char c1, char c2);

int main(void)
{
	int T, n = 1, L, X;

	cin >> T;

	while (n <= T) {
		cin >> L >> X;
		X = X > 8 ? 8 + X % 8 : X;
		string s;
		cin >> s;
		long I, J, K;
		char ci = s[0];
		char cj = '1';
		char ck = s[L - 1];
		bool found = false;
		I = 0;
		K = L * X - 1;
		vector <int> vI;
		while (I < L * 4 - 1 && I < L * X - 1) {
			if (ci == 'i') {
				vI.push_back(I);
			}
			I++;
			ci = NextC(ci, s[I % L]);
		}
		vector <int> vK;
		while (K > 0 && K > L * (X - 4)) {
			if (ck == 'k') {
				vK.push_back(K);
			}
			K--;
			ck = PrevC(s[K % L], ck);
		}
		int vIi = 0, vKi = 0;
		for (vIi = 0; vIi < vI.size(); vIi++) {
			cj = '1';
			J = vI[vIi] + 1;
			for (vKi = 0; vKi < vK.size(); vKi++) {
				for (; J < vK[vKi]; J++) {
					cj = NextC(cj, s[J % L]);
				}
				if (cj == 'j') {
					found = true;
					vKi = vK.size();
					vIi = vI.size();
					break;
				}
			}
		}
		cout << "Case #" << n++ << ": ";
		if (found) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}

char NextC(char c1, char c2)
{
	if (c1 == '1') {
		return c2;
	}
	if (c1 == '-') {
		return c2 - 32;
	}
	if (c1 == c2) {
		return '-';
	}
	if (c2 - c1 == 32) {
		return '1';
	}
	if (c2 == 'i') {
		if (c1 == 'k') {
			return 'j';
		} else if (c1 == 'K') {
			return 'J';
		} else if (c1 == 'j') {
			return 'K';
		} else {
			return 'k';
		}
	} else if (c2 == 'j') {
		if (c1 == 'k') {
			return 'I';
		} else if (c1 == 'K') {
			return 'i';
		} else if (c1 == 'i') {
			return 'k';
		} else {
			return 'K';
		}
	} else {
		if (c1 == 'i') {
			return 'J';
		} else if (c1 == 'I') {
			return 'j';
		} else if (c1 == 'j') {
			return 'i';
		} else {
			return 'I';
		}
	}
}

char PrevC(char c1, char c2)
{
	if (c2 == '1') {
		return c1;
	}
	if (c2 == '-') {
		return c1 - 32;
	}
	if (c2 == c1) {
		return '-';
	}
	if (c1 - c2 == 32) {
		return '1';
	}
	if (c1 == 'i') {
		if (c2 == 'k') {
			return 'J';
		} else if (c2 == 'K') {
			return 'j';
		} else if (c2 == 'j') {
			return 'k';
		} else {
			return 'K';
		}
	} else if (c1 == 'j') {
		if (c2 == 'k') {
			return 'i';
		} else if (c2 == 'K') {
			return 'I';
		} else if (c2 == 'i') {
			return 'K';
		} else {
			return 'k';
		}
	} else {
		if (c2 == 'i') {
			return 'j';
		} else if (c2 == 'I') {
			return 'J';
		} else if (c2 == 'j') {
			return 'I';
		} else {
			return 'i';
		}
	}
}
