#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

#define MAXN 1000
#define INF 1000000000
vector < int > a;
int E, R, N;
int bestSum;
void dfs(int e, int v, int sum) {
	if (v == a.size()) {
		bestSum = max(bestSum, sum);
		return;
		}
	for (int i = 0; i <= e; i++) {
		dfs(min(E, e - i + R), v + 1, sum + i * a[v]);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		cin >> E >> R >> N;
		a.clear();
		a.resize(N);
		bestSum = -1;
		for (int i = 0; i < N; i++)
			scanf("%d", &a[i]);
		dfs(E, 0, 0);
		printf("Case #%d: %d\n", t, bestSum);
	}

	return 0;
}