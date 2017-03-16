#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>

using namespace std;

typedef __int64 I;

const int N = 1009;
const double eps = 0.00001;
const int INF = 0x3fffffff;

int f[N];

int rng[N];
int maxTree[N][3];

bool isRing(int n, int node) {
	int idx = node;
	for (int i = 0; i < n; i++) {
		if (f[idx] == node) {
			return true;
		}
		idx = f[idx];
	}
	return false;
}

int setRing(int n, int node) {
	int idx = node;
	for (int i = 1; i <= n; i++) {
		if (f[idx] == node) {
			rng[idx] = node;
			return i;
		}
		idx = f[idx];
	}
	return 0;
}

void getTreeNodeNum(int n, int node) {
	int idx = node;
	for (int i = 1; i <= n; i++) {
		int u = f[idx];
		if (rng[u] != -1) {
			int rt = rng[u];
			if (i > maxTree[rt][1]) {
				maxTree[rt][1] = i;
				if (maxTree[rt][0] < maxTree[rt][1]) {
					swap(maxTree[rt][0], maxTree[rt][1]);
				}
			}
			return ;
		}
		idx = f[idx];
	}
}

int main() {
	FILE* stream;
	freopen_s(&stream, "C-small-attempt1.in", "r", stdin);
	freopen_s(&stream, "C-small-attempt1.out", "w", stdout);
	int t;
	scanf_s("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		memset(rng, -1, sizeof(rng));
		memset(maxTree, 0, sizeof(maxTree));
		int n;
		scanf_s("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf_s("%d", f + i);
		}
		for (int i = 1; i <= n; i++) {
			if (rng[i] == -1) {
				bool flag = isRing(n, i);
				if (flag) {
					maxTree[i][0] = setRing(n, i);
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			if (rng[i] == -1) {
				getTreeNodeNum(n, i);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int tmp = 0;
			for (int j = 0; j < 3; j++) {
				tmp += maxTree[i][j];
			}
			ans = max(ans, tmp);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (maxTree[i][0] == 2) cnt++;
		}
		ans = max(ans, cnt * 2);
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}