#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

static int lines[111][111];
static int ans[111];
static int used[111];
static int levelPair[111][2];

void solve(int n) {
	int missingK = -1;
	for (int k = 0 ; k < n ; k++) {
		int req = (k == 0) ? 0 : max(lines[levelPair[k-1][0]][k], lines[levelPair[k-1][1]][k]);
		int posOne = -1;
		int posTwo = -1;
		int min = 1000000;
		for (int i = 0 ; i < 2*n-1 ; i++) {
			if (used[i] || lines[i][k] <= req) {
				continue;
			}
			if (min > lines[i][k]) {
				min = lines[i][k];
				posOne = i;
				posTwo = -1;
			} else if (min == lines[i][k]) {
				posTwo = i;
			}
		}
		if (posOne == -1 || posTwo == -1) {
			missingK = k;
			break;
		}
		levelPair[k][0] = posOne;
		levelPair[k][1] = posTwo;
		used[posOne] = used[posTwo] = 1;
	}

	for (int k = n-1 ; k > missingK ; k--) {
		int req = (k == n-1) ? 1000000 : min(lines[levelPair[k+1][0]][k], lines[levelPair[k+1][1]][k]);
		int posOne = -1;
		int posTwo = -1;
		int max = 0;

		// printField(n);
		// printf("%d req %d\n", k, req);

		for (int i = 0 ; i < 2*n-1 ; i++) {
			if (used[i] || lines[i][k] >= req) {
				continue;
			}
			if (max < lines[i][k]) {
				max = lines[i][k];
				posOne = i;
				posTwo = -1;
			} else if (max == lines[i][k]) {
				posTwo = i;
			}
		}
		levelPair[k][0] = posOne;
		levelPair[k][1] = posTwo;
		used[posOne] = used[posTwo] = 1;
	}

	int lastLine = -1;
	for (int i = 0 ; i < 2*n-1 ; i++) {
		if (!used[i]) {
			lastLine = i;
			break;
		}
	}
	ans[missingK] = lines[lastLine][missingK];
	for (int i = 0 ; i < n ; i++) {
		if (i == missingK) {
			continue;
		}
		if (lines[levelPair[i][0]][missingK] == lines[lastLine][i]) {
			ans[i] = lines[levelPair[i][1]][missingK];
		} else if (lines[levelPair[i][1]][missingK] == lines[lastLine][i]) {
			ans[i] = lines[levelPair[i][0]][missingK];
		} else {
			ans[i] = -1;
		}
	}
}

int main(void) {
	int T;
	int n;
	cin >> T;
  for (int t = 1 ; t <= T ; t++) {
		cin >> n;
		for (int i = 0 ; i < n * 2 - 1 ; i++) {
			for (int j = 0 ; j < n ; j++) {
				cin >> lines[i][j];
			}
		}
		for (int i = 0 ; i < 2*n-1 ; i++) {
			used[i] = 0;
		}

    solve(n);

    printf("Case #%d:", t);
		for (int i = 0 ; i < n ; i++) {
			printf(" %d", ans[i]);
		}
		printf("\n");
  }
	return 0;
}
