#include <iostream>
#include <string>
using namespace std;

uint64_t B;
uint64_t M;
int cnt;
int building[50][50];

void dfs(int point) {
	if (point >= B - 1) {
		cnt++;
		//cout << cnt << endl;
		return;
	}

	for (int i = point + 1; i < B; ++i) {
		if (building[point][i] != 0) {
			dfs(i);
			//cout << i << endl;
		}
	}
}

int check() {
	cnt = 0;
	dfs(0);

	if (cnt == M)
		return 1;
	else
		return 0;
}

int create(int build) {
	if (build == B - 1) {
		return check();
	}

	for (int i = 0; i < (1 << (B - build - 1)); ++i) {
		for (int j = build + 1; j < B; ++j) {
			building[build][j] = (i >> (j - build - 1)) & 1;
		}

		if (create(build + 1))
			return 1;
		
		for (int j = build + 1; j < B; ++j) {
			building[build][j] = 0;
		}
	}
	return 0;
}

int main() {
	int T;
	int t;

	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	cin >> T;
	for (t = 1; t <= T; ++t) {
		cin >> B >> M;
		memset(building, 0, sizeof(building));
		cnt = 0;
		cout << "Case #" << t << ": ";
		if (M > (1L << (B - 2L))) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		cout << "POSSIBLE" << endl;
		
		create(0);

		for (int i = 0; i < B; ++i) {
			for (int j = 0; j < B; ++j) {
				cout << building[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}