#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int ans[405];
int own[405];
int need[405];
bool M[405][405];
vector<int> inside[405];
bool was[405];
int n, k;

void Clear() {
	memset(was, 0, sizeof was);
	memset(own, 0, sizeof own);
	memset(ans, 0, sizeof ans);
	memset(M, 0, sizeof M);
	memset(need, 0, sizeof need);
	for (int i = 0; i < 205; ++i) {
		inside[i].clear();
	}
}

bool used[405];
bool at_iter[405];
int cur[405];
int desire[405];

void Use(int v) {
	used[v] = true;
	--cur[need[v]];
	--desire[need[v]];
	for (int i = 0; i < inside[v].size(); ++i) {
		++cur[inside[v][i]];
	}
}

bool DFS(int v, int d) {
	if (at_iter[v] || used[v]) {
		return false;
	}
	at_iter[v] = true;
	if (M[v][d]) {
		return true;
	}
	for (int i = 0; i < n; ++i) {
		if (M[v][need[i]]) {
			if (DFS(i, d)) {
				return true;
			}
		}
	}
	return false;
}

// It's really slow, but I hope it's good enough. =|
bool Check() {
	memcpy(used, was, sizeof used);
	memcpy(cur, own, sizeof own);
	memset(desire, 0, sizeof desire);
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			++desire[need[i]];
		}
	}
	bool changed = true;
	while (changed) {
		changed = false;
		for (int i = 0; i < n; ++i) {
			if (cur[need[i]] == 0) {
				continue;
			}
			memset(at_iter, 0, sizeof at_iter);
			if (DFS(i, need[i])) {
				changed = true;
				Use(i);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (!used[i] && desire[need[i]] <= cur[need[i]]) {
				Use(i);
				changed = true;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int I = 0; I < T; ++I) {
		Clear();
		printf("Case #%d: ", I + 1);
		scanf("%d%d", &k, &n);
		for (int i = 0; i < k; ++i) {
			int x;
			scanf("%d", &x);
			++own[x];
		}
		for (int i = 0; i < n; ++i) {
			int q;
			scanf("%d%d", &need[i], &q);
			for (int j = 0; j < q; ++j) {
				int x;
				scanf("%d", &x);
				inside[i].push_back(x);
				M[i][x] = true;
			}
		}
		if (!Check()) {
			puts("IMPOSSIBLE");
		} else {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (was[j]) {
						continue;
					}
					if (own[need[j]] > 0) {
						was[j] = true;
						--own[need[j]];
						for (int k = 0; k < inside[j].size(); ++k) {
							++own[inside[j][k]];
						}
						if (Check()) {
							ans[i] = j + 1;
							break;
						}
						++own[need[j]];
						for (int k = 0; k < inside[j].size(); ++k) {
							--own[inside[j][k]];
						}
						was[j] = false;
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				printf("%d ", ans[i]);
			}
			puts("");
		}
	}
	return 0;
}