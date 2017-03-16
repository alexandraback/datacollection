#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <assert.h>

#define REP(i, n) for (int i = 0; i < (n); i++) 

using namespace std;

const int N = 64;

char a[N][N];
int m, n, tot;

void fillAll() {
	REP(i, m) REP(j, n) {
		if (i * n + j < tot) a[i][j] = '*';
	}
}

void output() {
	REP(i, m) {
		REP(j, n) {
			putchar(a[i][j]);
		}
		putchar('\n');
	}
}

bool check(int x, int y, int left) {
	int rs = m - x;
	int cs = n - y; 
	if (left >= min(rs, cs)) return false;
	if (min(rs, cs) < 2) return false;
	for (int i = x; i < m - 2; i++) {
		for (int j = y; j < n - 2; j++) {
			if (left) {
				a[i][j] = '*';
				left--;
			}
		}
	}
	if (left) return false;
	return true;
}

bool solve() {
	if (check(0, 0, tot)) return true;
	for (int r = 0; r <= tot / n; r++) {
		REP(i, m) REP(j, n) a[i][j] = '.';
		a[m-1][n-1] = 'c';
		REP(i, r) REP(j, n) a[i][j] = '*';
		int left = tot - r * n;
		for (int i = r; i < m; i++) {
			for (int j = 0; j < left / (m - r); j++) {
				a[i][j] = '*';
			}
		}
		if (check(r, left / (m - r), left % (m - r))) return true;
	}
	return false;
}

int main() {
	freopen("D:/c-large.in", "r", stdin);
	freopen("D:/c-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	REP(t, T) {
		scanf("%d %d %d", &m, &n, &tot);
		printf("Case #%d:\n", t + 1);
		REP(i, m) REP(j, n) a[i][j] = '.';
		a[m-1][n-1] = 'c';
		if (m == 1 || n == 1 || tot == m * n - 1) {
			fillAll();
			output();
		} else {
			if (solve()) output();
			else puts("Impossible");
		}
	}
	return 0;
}