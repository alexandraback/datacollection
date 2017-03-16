
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int cnt[200], neededKey[20];
vector<int> hasKeys[20], path;
bool v[1 << 20];

bool dfs(int state) {
	if (state == 0) return true;
	if (v[state]) return false;
	v[state] = true;
	int tmp = state;
	while (tmp > 0) {
		int i = __builtin_ctz(tmp & -tmp);
		if (cnt[neededKey[i]] > 0) {
			cnt[neededKey[i]] --;
			for (int j = 0; j < hasKeys[i].size(); j ++)
				cnt[hasKeys[i][j]] ++;
			path.push_back(i);
			if (dfs(state - (1 << i))) return true;
			path.pop_back();
			for (int j = 0; j < hasKeys[i].size(); j ++)
				cnt[hasKeys[i][j]] --;
			cnt[neededKey[i]] ++;
		}
		
		tmp -= 1 << i;
	}
	return false;
}

void work() {
	int k, n;
	scanf("%d%d", &k, &n);
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < k; i ++) {
		int x;
		scanf("%d", &x);
		x --;
		cnt[x] ++;
	}
	for (int i = 0; i < n; i ++) {
		scanf("%d", &neededKey[i]);
		neededKey[i] --;
		hasKeys[i].clear();
		int t;
		scanf("%d", &t);
		for (int j = 0; j < t; j ++) {
			int x;
			scanf("%d", &x);
			x --;
			hasKeys[i].push_back(x);
		}
	}
	memset(v, false, sizeof(v));
	path.clear();
	if (dfs((1 << n) - 1)) {
		for (int i = 0; i < path.size(); i ++)
			if (i < path.size() - 1) {
				printf("%d ", path[i] + 1);
			} else {
				printf("%d\n", path[i] + 1);
			}
	} else {
		printf("IMPOSSIBLE\n");
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; test ++) {
		printf("Case #%d: ", test + 1);
		work();
	}

	return 0;
}