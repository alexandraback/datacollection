#define IOSTREAM_TO_FSTREAM

#include<iostream>
#include<string.h>
#ifdef IOSTREAM_TO_FSTREAM
#include<fstream>
#endif

using namespace std;

int fact(int v) {
	int s = 1;
	for (int i = 1 ; i <= v ; i++) {
		s *= i;
	}
	return s;
}

bool judge(const char *s) {
	char k[50] = {0};
	char t = s[0];
	k[0] = s[0];
	bool flag = true;
	for (int i = 1 ; i < strlen(s) ; i++) {
		if (t != s[i]) {
			for (int j = 0 ; j < strlen(k) ; j++) {
				if (s[i] == k[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				k[strlen(k)] = s[i];
			} else {
				break;
			}
		}
		t = s[i];
	}
	return flag;
}

void join(int n, char s[][105], int p[15], char r[1100]) {
	for (int i = 0 ; i < 105 ; i++) {
		r[i] = 0;
	}
	for (int i = 0 ; i < n ; i++) {
		strcat(r, s[p[i]]);
	}
}

bool yasuo(int n, char s[][105]) {
	bool flag = true;
	for (int i0 = 0 ; i0 < n ; i0++) {

	char t = s[i0][0];
	char k[105] = {0};
	k[0] = s[i0][0];
	for (int i = 1 ; i < strlen(s[i0]) ; i++) {
		if (t != s[i0][i]) {
			for (int j = 0 ; j < strlen(k) ; j++) {
				if (s[i0][i] == k[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				k[strlen(k)] = s[i0][i];
			} else {
				break;
			}
		}
		t = s[i0][i];
	}
	strcpy(s[i0], k);
	}
	return flag;
}

void pnext(int V, int r[15]) {
	int i = V - 2, j;
	while (i >= 0) {
		if (r[i] < r[i + 1]) {
			for (j = V - 1 ; j > i ; j--) {
				if (r[i] <= r[j]) {
					break;
				}
			}
			int tt = r[i];
			r[i] = r[j];
			r[j] = tt;
			for (j = V - 1 ; j >= 0 ; j--) {
				i++;
				if (i >= j) {
					break;
				}
				int tt = r[i];
				r[i] = r[j];
				r[j] = tt;
			}
			break;
		}
		i--;
	}
}

int main()
{
#ifdef IOSTREAM_TO_FSTREAM
	ifstream fin;
	fin.open("B-small-attempt1.in");
	cin.rdbuf(fin.rdbuf());
	ofstream fout;
	fout.open("B-small-attempt1.out");
	cout.rdbuf(fout.rdbuf());
#endif
	int n0;
	cin >> n0;
	for (int i0 = 1 ; i0 <= n0 ; i0++) {
		int n;
		char c[110][105];
		cin >> n;
		for (int i = 0 ; i < n ; i++) {
			cin >> c[i];
		}
		if (!yasuo(n, c)) {
			cout << "Case #" << i0 << ": 0" << endl;
			continue;
		}
		int p[15];
		char r[1100];
		for (int i = 0 ; i < n ; i++) {
			p[i] = i;
		}
		int s = 0;
		for (int i = 0 ; i < fact(n) ; i++) {
			join(n, c, p, r);
			//cout << r << "__";
			if (judge(r)) {
				s++;
			}
			pnext(n, p);
		}
		cout << "Case #" << i0 << ": " << s << endl;
	}
	return 0;
}
