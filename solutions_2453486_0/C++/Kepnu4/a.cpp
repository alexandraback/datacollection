#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <ctime>

using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

char a[10][10];

void load() {
	for (int i = 0;i < 4;i++) {
	 	gets(a[i]);
	}
	scanf("\n");
}

bool eq (char a, char b) {
 	if (a == 'T') return true;
 	return a == b;
}

bool check (char a1, char a2, char a3, char a4, char x) {
 	return eq(a1, x) && eq (a2, x) && eq (a3, x) && eq (a4, x);
}

void solve(int test) {
	for (int i = 0;i < 4;i++) {
	 	if (check (a[i][0], a[i][1], a[i][2], a[i][3], 'X') ||
	 		check (a[0][i], a[1][i], a[2][i], a[3][i], 'X')) {
	 		printf ("Case #%d: X won\n", test);
	 		return;
	 	}

	 	if (check (a[i][0], a[i][1], a[i][2], a[i][3], 'O') ||
	 		check (a[0][i], a[1][i], a[2][i], a[3][i], 'O')) {
	 		printf ("Case #%d: O won\n", test);
	 		return;
	 	}
	}

	if (check (a[0][0], a[1][1], a[2][2], a[3][3], 'X') ||
		check (a[0][3], a[1][2], a[2][1], a[3][0], 'X')) {
		printf ("Case #%d: X won\n", test);
		return;
	}

	if (check (a[0][0], a[1][1], a[2][2], a[3][3], 'O') ||
		check (a[0][3], a[1][2], a[2][1], a[3][0], 'O')) {
		printf ("Case #%d: O won\n", test);
		return;
	}

	for (int i = 0;i < 4;i++) {
	 	for (int j = 0;j < 4;j++) {
	 	 	if (a[i][j] == '.') {
	 	 		printf ("Case #%d: Game has not completed\n", test);
	 	 		return;
	 	 	}
	 	}
	}

	printf ("Case #%d: Draw\n", test);
}

int main() {
 	freopen ("a.in", "r", stdin);
 	freopen ("a.out", "w", stdout);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		load();
 		solve(i);
 	}

 	return 0;
}