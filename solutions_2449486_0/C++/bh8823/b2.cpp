#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MAXL 100
using namespace std;
const int INF = 987654321;
const int MOD = 1000000007;

int board[MAXL][MAXL];
int n, m;
bool checked[MAXL][MAXL];

bool checkrow(int idx) {
	for (int i = 0; i < m; i++) {
		if (board[idx][i] == 2) {
			return false;
		}
	}
	return true;
}

bool checkcol(int idx) {
	for (int i = 0; i < n; i++) {
		if (board[i][idx] ==  2) {
			return false;
		}
	}
	return true;
}

bool calc() {
	for (int i = 0 ; i < n; i++) {
		if (checkrow(i)) {
			for (int j = 0; j < m; j++) {
				checked[i][j] = true;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (checkcol(i)) {
			for (int j = 0; j < n; j++) {
				checked[j][i] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && !checked[i][j]) {
				//printf("%d %d\n", i,j);
				return false;

			}
		}
	}
	return true;
}
int main() {
	int T;
	scanf("%d", &T);

	int loop = 1;
	while (loop <= T) {
		memset(checked, false, sizeof(checked));
		scanf("%d",&n);
		scanf("%d",&m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d",&board[i][j]);

		printf("Case #%d: ", loop);
		if (calc()) {
			puts("YES");
		} else {
			puts("NO");
		}
		loop++;
	}

	return 0;
}