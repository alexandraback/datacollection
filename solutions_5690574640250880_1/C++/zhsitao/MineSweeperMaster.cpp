#define IOSTREAM_TO_FSTREAM

#include<iostream>
#ifdef IOSTREAM_TO_FSTREAM
#include<fstream>
#endif

using namespace std;

void swap(int& a, int &b) {
	int t = a;
	a = b;
	b = t;
}

void transpose(char s[100][100], int r, int c) {
	char t[100][100];
	for (int i = 0 ; i < c ; i++) {
		for (int j = 0 ; j < r ; j++) {
			t[i][j] = s[i][j];
		}
	}
	for (int i = 0 ; i < r ; i++) {
		for (int j = 0 ; j < c ; j++) {
			s[i][j] = t[j][i];
		}
	}
}

int judge(char s[100][100], int r, int c, int b) {		//r <= c && 1 <= b && b <= r * c
	int t = 0;
	if (b == 1 || r < 2 || (b >= 2 * c && b % c != 1)) {
		for (int i = 0 ; i < r ; i++) {
			for (int j = 0 ; j < c ; j++, t++) {
				if (t < b) {
					s[i][j] = '.';
				} else {
					s[i][j] = '*';
				}
			}
		}
		return true;
	}
	if (b >= 4 && b < 2 * c && b % 2 == 0) {
		for (int i = 0 ; i < r ; i++) {
			for (int j = 0 ; j < c ; j++) {
				if (i < 2 && j < b / 2) {
					s[i][j] = '.';
				} else {
					s[i][j] = '*';
				}
			}
		}
		return true;
	}
	if (r > 2 && b >= 9 && b <= 2 * c + 3) {		//b % 2 == 1
		for (int i = 0 ; i < r ; i++) {
			for (int j = 0 ; j < c ; j++) {
				if ((i < 2 && j < (b - 3) / 2) || (i == 2 && j < 3)) {
					s[i][j] = '.';
				} else {
					s[i][j] = '*';
				}
			}
		}
		return true;
	}
	if (b > 3 * c && b % c == 1) {		//r > 3
		for (int i = 0 ; i < r ; i++) {
			for (int j = 0 ; j < c ; j++, t++) {
				if (t == b - 2 && j == c - 1) {
					s[i][j] = '*';
					t--;
				} else if (t < b) {
					s[i][j] = '.';
				} else {
					s[i][j] = '*';
				}
			}
		}
		return true;
	}
	cout << "Impossible" << endl;
	return false;
}

int main() {
#ifdef IOSTREAM_TO_FSTREAM
	ifstream fin;
	fin.open("C-large.in");
	cin.rdbuf(fin.rdbuf());
	ofstream fout;
	fout.open("C-large.out");
	cout.rdbuf(fout.rdbuf());
#endif
	int n;
	int r, c, m, b;
	bool trans;
	char s[100][100];
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		trans = false;
		for (int j = 0 ; j < 100 ; j++) {
			for (int k = 0 ; k < 100 ; k++) {
				s[j][k] = '#';
			}
		}
		cin >> r >> c >> m;
		if (r > c) {
			trans = true;
			swap(r, c);
		}		//r <= c
		b = r * c - m;
		cout << "Case #" << i << ": " << endl;
		if (judge(s, r, c, b)) {
			if (trans) {
				swap(r, c);
				transpose(s, r, c);
			}
			for (int j = 0 ; j < r ; j++) {
				for (int k = 0 ; k < c ; k++) {
					if (j == 0 && k == 0) {
						cout << 'c';
					} else {
						cout << s[j][k];
					}
				}
				cout << endl;
			}
		}
	}
	return 0;
}
