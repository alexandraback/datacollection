#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

#define INF (2000000000)

const int nmax = 8;

char c[nmax][nmax];
int n = 4;


bool playerCheck(char p, char opposite) {

	bool good = true;

	for(int i = 0; i < n; ++i) {

		good = true;

		for(int j = 0; j < n; ++j) {
			if (c[i][j] == '.' || c[i][j] == opposite) {
				good = false;
				break;
			}
		}

		if (good) {
			printf("%c won\n", p);
			return true;
		}
	}

	for(int i = 0; i < n; ++i) {

		good = true;

		for(int j = 0; j < n; ++j) {
			if (c[j][i] == '.' || c[j][i] == opposite) {
				good = false;
				break;
			}
		}

		if (good) {
			printf("%c won\n", p);
			return true;
		}
	}

	good = true;

	for(int i = 0; i < n; ++i) {
		if (c[i][i] == '.' || c[i][i] == opposite) {
			good = false;
			break;
		}
	}

	if (good) {
		printf("%c won\n", p);
		return true;
	}

	good = true;

	for(int i = 0; i < n; ++i) {
		if (c[i][n - i - 1] == '.' || c[i][n - i - 1] == opposite) {
			good = false;
			break;
		}
	}

	if (good) {
		printf("%c won\n", p);
		return true;
	}

	return false;

}

void check() {

	if (playerCheck('X', 'O') || playerCheck('O', 'X')) {
		return;
	}

	bool good = true;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if (c[i][j] == '.') {
				good = false;
				break;
			}
		}
	}

	if (good) {
		puts("Draw");
		return;
	}

	puts("Game has not completed");

}

void readTest() {

	for(int i = 0; i < n + 1; ++i) {
		gets(c[i]);
	}

}

void solveTest() {
	check();
}

int main()
{
	freopen("A.in", "rt", stdin);

	bool submit = true;

	if (submit) {
		freopen("A.out", "wt", stdout);
	}

	int t;
	scanf("%d\n", &t);
	for(int tt = 0; tt < t; ++tt) {
		readTest();
		printf("Case #%d: ", tt + 1);
		solveTest();
		if (submit) {
			cerr << "Case " << tt + 1 << " done\n";
		}
	}
	return 0;
}