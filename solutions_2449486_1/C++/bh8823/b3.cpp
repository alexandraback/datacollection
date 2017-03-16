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
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int dx[]={1,0,-1,0,1,-1,1,-1};

int board[MAXL][MAXL];
int n, m;
bool checked[MAXL][MAXL];
int MIN;
bool rows[MAXL];
bool cols[MAXL];
	//	vector<int> rowleft;
	//	vector<int> colleft;

void findMin() {
	int temp = 100;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (checked[i][j]) continue;
		if(board[i][j] < temp) temp = board[i][j];
	}
	MIN = temp;
}
bool checkrow(int idx) {
	for (int i = 0; i < m; i++) {
		if (!checked[idx][i] && board[idx][i] != MIN) {
			return false;
		}
	}
	return true;
}

bool checkcol(int idx) {
	for (int i = 0; i < n; i++) {
		if (!checked[i][idx] && board[i][idx] != MIN) {
			return false;
		}
	}
	return true;
}

bool calc() {
	int rleft = n;
	int cleft = m;
	while(rleft != 0 || cleft != 0) {
		findMin();
		bool found = false;
		bool row = false;
		int idx = -1;
		for (int i = 0; i < n; i++) {
			if (!rows[i] && checkrow(i)) {
				for (int j = 0; j < m; j++) {
					checked[i][j] = true;
				}
				rows[i] = true;
				found = true;
				row = true;
				idx = i;
				rleft--;
				break;
			}
		}
		if (!found) {
			for (int i = 0; i < m; i++) {
				if (!cols[i] && checkcol(i)) {
					for (int j = 0; j < n; j++) {
						checked[j][i] = true;
					}
					cols[i] = true;
					found = true;
					row = false;
					idx = i;
					cleft--;
				}
			}
		}
		if (!found) {
			return false;
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
		memset(rows, false, sizeof(rows));
		memset(cols, false, sizeof(cols));
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