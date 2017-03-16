#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

const int inf = 1<<30;
const int MAXN = 110;

int p[MAXN][MAXN];
bool usedRow[MAXN];
bool usedCol[MAXN];
set< int > all;

void solve() {
	all.clear();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int  j = 0; j < m; j++) {
			scanf("%d", &p[i][j]);
			all.insert(p[i][j]);
		}

	for (set<int>::iterator it = all.begin(); it != all.end(); it++) {
		int cur = *it;
		memset(usedRow, 0, sizeof(usedRow));
		memset(usedCol, 0, sizeof(usedCol));
		for (int i = 0; i < n; i++) {
			int maxval = -1;
			for (int j = 0; j < m; j++) {
				maxval = max(maxval, max(cur, p[i][j]));
			}

			if (maxval == cur) {
				usedRow[i] = true;
			}
		}

		for (int i = 0; i < m; i++) {
			int maxval = -1;
			for (int j = 0; j < n; j++) {
				maxval = max(maxval, max(cur, p[j][i]));
			}

			if (maxval == cur) {
				usedCol[i] = true;
			}
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (p[i][j] == cur && !usedRow[i] && !usedCol[j]) {
					printf("NO\n");
					return;
				}
			}
	}
	printf("YES\n");
}

int main() {
	freopen("B-small-attempt0.in","r", stdin);
	freopen("B_output.txt","w", stdout);
	int T;
	scanf("%d\n", &T);
	for (int i = 0; i < T; i++) {
		printf("Case #%d: ", i + 1);
		solve();
	}
}
