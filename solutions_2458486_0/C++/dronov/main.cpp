#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 30
#define INF 1000000000
int N, M;
int start;
vector < vector < int > > cnt(MAXN), newKeys(MAXN);
int g[MAXN][MAXN];
bool used[MAXN], bad[MAXN];
vector < int > cur, ans;
int c = 0;
void dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < N; i++) {
		if (i != v && g[v][i] && !used[i]) {
			cur.push_back(i);
			dfs(i);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d\n", &test);
	start = 28;
	for (int test1 = 0; test1 < test; test1++) {
		int Ki;
		for (int i = 0; i < cnt.size(); i++)
			cnt[i].clear();
		memset(g, 0, sizeof(g));
		memset(used, 0, sizeof(used));
		for (int i = 0; i < newKeys.size(); i++)
			newKeys[i].clear();

		scanf("%d%d\n", &Ki, &N);
		vector < int > myKeys(Ki);
		for (int i = 0; i < Ki; i++)
			scanf("%d", &myKeys[i]);
		for (int i = 0; i < N; i++) {
			int x, kol;
			scanf("%d%d", &x, &kol);
			cnt[x].push_back(i);
			for (int j = 0; j < kol; j++) {
				scanf("%d", &x);
				newKeys[i].push_back(x);
			}
		}

		for (int i = 0; i < N; i++) {
			for (size_t j = 0; j < newKeys[i].size(); j++)
				for (size_t k = 0; k < cnt[newKeys[i][j]].size(); k++)
					g[i][cnt[newKeys[i][j]][k]] = 1;
		}

		for (size_t i = 0; i < myKeys.size(); i++)
			for (size_t j = 0; j < cnt[myKeys[i]].size(); j++)
				g[start][cnt[myKeys[i]][j]] = 1;
		
		int kol;
		int q = 0;
		int qq = 0;
		memset(bad, 0, sizeof(bad));
		for (int i = 0; i < N; i++)
			if (g[start][i])
				qq++;
		
		bool ok = false;
		ans.clear();
		cur.clear();
		for (int i = 0; i < N && !ok; i++) {
			memset(used, 0, sizeof(used));
			memset(bad, 0, sizeof(bad));

			kol = 0;
			q = myKeys.size();
			int c = q;
			for (int j = 0; j < qq; j++) {
				c = q;
				cur.clear();
				kol = 0;
				memset(used, 0, sizeof(used));
			
				for (int k = 0; k < N && c; k ++)
					if (g[start][k] && !bad[k]) {
						bad[k] = 1;
						c--;
						cur.push_back(k);
						dfs(k);
					}
				for (int k = 0; k < N; k++)
					if (used[k])
						kol++;
				if (kol == N) {
					ans = cur;
					ok = true;
					break;
				}

			}
		}
			
		printf("Case #%d: ", test1 + 1);
		if (!ans.empty()) {
			for (int i = 0; i < ans.size(); i++)
				printf("%d ", ans[i] + 1);
			printf("\n");
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
		

}