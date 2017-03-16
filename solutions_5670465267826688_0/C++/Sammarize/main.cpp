#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long lint;
int next() {int x; cin >> x; return x;}
lint lnext() {lint x; cin >> x; return x;}

int main() {

	int tests = next();
	int prod[8][8];
	for (int i = 0; i < 4; i++) prod[0][i] = prod[i][0] = i;
	for (int i = 1; i < 4; i++) prod[i][i] = 4;
	prod[1][2] = 3; prod[2][3] = 1; prod[3][1] = 2;
	prod[2][1] = 7; prod[3][2] = 5; prod[1][3] = 6;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			int shift = (i ^ j) >> 2;
			prod[i][j] = prod[i & 3][j & 3] ^ (shift << 2);
		}


	for (int test = 1; test <= tests; test++) {
		
		int l = next();
		lint x = lnext();
		string s;
		cin >> s;
		vector<int> v(0);
		for (int i = 0; i < l; i++) {
			if (s[i] == 'i') v.push_back(1);
			if (s[i] == 'j') v.push_back(2);
			if (s[i] == 'k') v.push_back(3);
		}
		int i = 0;
		int p = 0;
		bool answ = true;
		for (int goal = 1; goal <= 3; goal++) {
			if (answ) for (p = 0; p != goal && i < 12*l; p = prod[p][v[i % l]], i++);
			if (p != goal) answ = false;
		}
		while ((i % l != 0 || p != 3) && i < 12*l) {p = prod[p][v[i % l]]; i++;}
		int cnt = 0;
		if (p == 3) cnt = i / l;
		else answ = false;
		if (answ) {
			int lprod = 0;
			for (int i = 0; i < l; i++) lprod = prod[lprod][v[i]];
			int per = lprod == 0 ? 1 : lprod == 4 ? 2 : 4;
			if (cnt > x) answ = false;
			else if ((x - cnt) % per != 0) answ = false;
		}
		cout << "Case #" << test << ": " << (answ ? "YES" : "NO") << "\n";


	}
}