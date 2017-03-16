#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
using namespace std;

int T;
string C, J;
int CC, JJ;
int ansCC, ansJJ;

void DFS_J(int step) {
	if (step == J.length()) {
		if (ansCC == -1) {
			ansCC = CC;
			ansJJ = JJ;
			return;
		} else if (abs(CC - JJ) < abs(ansCC - ansJJ)) {
			ansCC = CC;
			ansJJ = JJ;
			return;
		} else if (abs(CC - JJ) == abs(ansCC - ansJJ)) {
			if (CC < ansCC) {
				ansCC = CC;
				ansJJ = JJ;
				return;
			} else if (CC == ansCC && JJ < ansJJ) {
				ansCC = CC;
				ansJJ = JJ;
				return;
			}
		}
	} else {
		int backup = JJ;
		if (J[step] != '?') {
			JJ = JJ * 10 + J[step] - '0';
			DFS_J(step + 1);
			JJ = backup;
		} else {
			for (int i = 0; i < 10; i++) {
				JJ = JJ * 10 + i;
				DFS_J(step + 1);
				JJ = backup;
			}
		}
	}
}
void DFS_C(int step) {
	if (step == C.length()) {
		DFS_J(0);
	} else {
		int backup = CC;
		if (C[step] != '?') {
			CC = CC * 10 + C[step] - '0';
			DFS_C(step + 1);
			CC = backup;
		} else {
			for (int i = 0; i < 10; i++) {
				CC = CC * 10 + i;
				DFS_C(step + 1);
				CC = backup;
			}
		}
	}
}

void output(int a, int len) {
	if (len >= 3 && a < 100) putchar('0');
	if (len >= 2 && a < 10) putchar('0');
	printf("%d", a);
}

int main() {
	cin >> T;
	for (int test = 1; test <= T; test++) {
		printf("Case #%d: ", test);

		cin >> C >> J;

		ansCC = -1; ansJJ = -1;
		CC = 0; JJ = 0;
		DFS_C(0);

		output(ansCC, C.length());
		putchar(' ');
		output(ansJJ, J.length());
		puts("");
	}
	return 0;
}
