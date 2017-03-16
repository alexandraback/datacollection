#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("C-small-attempt1.in");
ofstream fout("C-small-attempt1.out");

#define cin fin
#define cout fout

char g[100][100];

int solve(int r, int c, int s) {
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			g[i][j] = '*';
	if (s == 1) return 1;
	if (r == 1) {
		for (int i = 0; i < s; ++i)
			g[0][i] = '.';
		return 1;
	}
	for (int i = 2; i <= c; ++i) {
		int a = s / i, b = s % i;
		if (a < 2) continue;
		if (b == 0) {
			if (a > r) continue;
			for (int j = 0; j < a; ++j)
				for (int k = 0; k < i; ++k)
					g[j][k] = '.';
			return 1;
		}
		if (a + 1 > r) continue;
		if (b == 1 && (i == 2 || a == 2)) continue;
		for (int j = 0; j < a; ++j)
			for (int k = 0; k < i; ++k)
				g[j][k] = '.';
		for (int j = 0; j < b; ++j)
			g[a][j] = '.';
		if (b == 1) {
			g[a][b] = '.';
			g[a - 1][i - 1] = '*';
		}
		return 1;
	}
	return 0;
}

void run() {
	int r, c, m;
	cin>>r>>c>>m;
	int s = r * c - m;
	if (r <= c) {
		if (!solve(r, c, s)) {
			cout<<"Impossible"<<endl;
			return;
		}
		g[0][0] = 'c';
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j)
				cout<<g[i][j];
			cout<<endl;
		}
	} else {
		if (!solve(c, r, s)) {
			cout<<"Impossible"<<endl;
			return;
		}
		g[0][0] = 'c';
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j)
				cout<<g[j][i];
			cout<<endl;
		}
	}
}

int main() {
	int t;
	cin>>t;
	for (int i = 1; i <= t; ++i) {
		cout<<"Case #"<<i<<":"<<endl;
		run();
	}
	return 0;
}