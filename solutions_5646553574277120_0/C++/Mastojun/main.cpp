#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int T;

int C, D, V;
int coins[100];

bool allPossible(vector<bool>& values) {
	for(auto v : values) {
		if(!v) return false;
	}
	return true;
}

int dfs(vector<bool> values, vector<bool>& used, int minValue, int u) {
	if(allPossible(values)) return u;
	if(minValue > V) return 987654321;
	if(u > 5) return 987654321;

	int result = dfs(values, used, minValue + 1, u);

	if(used[minValue]) return result;
	used[minValue] = true;
			
	for(int v = V; v >= 0; v--) {
		if(v >= minValue && values[v - minValue]) {
			values[v] = true;
		}
	}

	result = min(result, dfs(values, used, minValue + 1, u + 1));
	used[minValue] = false;

	return result;
}

int solve() {
	vector<bool> values(V + 1, false);
	vector<bool> used(V + 1, false);
	values[0] = true;

	for(int i = 0; i < D; i++) {
		for(int v = V; v >= 0; v--) {
			if(v >= coins[i] && values[v - coins[i]]) {
				values[v] = true;
			}
		}
		if(coins[i] <= V) used[coins[i]] = true;
	}

	return dfs(values, used, 1, 0);
}

int main() {

	scanf("%d", &T);

	for(int Case = 1; Case <= T; Case++) {
		scanf("%d %d %d", &C, &D, &V);
		for(int d = 0; d < D; d++) {
			scanf("%d", coins + d);
		}
		sort(coins, coins + D);

		printf("Case #%d: %d\n", Case, solve());
	}

	return 0;
}
