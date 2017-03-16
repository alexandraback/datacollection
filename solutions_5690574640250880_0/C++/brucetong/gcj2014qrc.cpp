//Problem: Google Code Jam 2014 Qualification Round C
//Name: Minesweeper Master
//Author: Bruce K. B. Tong
//Tag: Ad Hoc

#include <cstdio>
#include <iostream>

using namespace std;

#define SMALL
//#define LARGE

#define SIZE 50

char b[SIZE][SIZE];

int solve(int R, int C, int M) {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			b[i][j] = '.';

	//special cases
	if (M == R*C-1) {
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				b[i][j] = '*';
		b[R-1][C-1] = 'c';
		return 1;	//possible
	} else if (R == 1) {
		int j = 0;
		while (M-- > 0 && j < C) b[0][j++] = '*';
		b[R-1][C-1] = 'c';
		return 1;	//possible
	} else if (C == 1) {
		int i = 0;
		while (M-- > 0 && i < R) b[i++][0] = '*';
		b[R-1][C-1] = 'c';
		return 1;	//possible
	}

	int i = 0, j = 0, num;
	while (M > 0 && i < R-2) {
		if (M >= C) num = C;
		else if (M == C - 1) num = C - 2;
		else num = M;
		M -= num;
		for (int j = 0; j < num; j++)
			b[i][j] = '*';
		i++;
	}
	j = 0;
	while (M > 0) {
		if (M >= 2) {
			b[i][j] = b[i+1][j] = '*';	//asserted: i+1 < R
			M -= 2;
		} else {		//M == 1
			int k = C - 1;
			b[i][j] = b[i+1][j] = '*';
			while (i-1 >= 0 && k > j && b[i-1][k] == '.') k--;
			if (i-1 >= 0 && k > j) {
				b[i-1][k] = '.';
				j++;
				if (k == C - 1) {
					if (k-2 <= j) return 0;		//impossible
					b[i][j] = b[i+1][j] = '*';
					b[i-1][k-1] = b[i-1][k-2] = '.';
				}
			} else
				return 0;		//impossible
			M -= 1;
		}
		j++;
	}
	if (i == R - 2 && j == C - 1 && j > 0) return 0;	//impossible
	b[R-1][C-1] = 'c';
	return 1;	//possible
}

int main() {
	freopen("C-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("C-small-attempt0.in", "rt", stdin);
		freopen("C-small-attempt0.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("C-large.in", "rt", stdin);
		freopen("C-large.out", "wt", stdout);
	#endif

	int T;		//1 <= T <= 230 (or 140)
	int R, C;	//1 <= R, C <= 5 (or 50)
	int M;		//0 <= M < R*C
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> R >> C >> M;
		cout << "Case #" << i << ": " << endl;
		int ans = solve(R, C, M);
		if (ans) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++)
					cout << b[i][j];
				cout << endl;
			}
		} else {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}