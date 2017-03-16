#include <cstdio>
#include <memory.h>

FILE *inf = fopen("A-small-attempt0.in", "r");
FILE *outf = fopen("small.out", "w");

const int MAXN = 1010;
const int MAXM = 11;

int adj[MAXN][MAXM];
int ca[MAXN];

int cnt[MAXN];
bool dfs(int v) {
	cnt[v] = 1;
	for (int i = 0; i < ca[v]; i++) {
		int to = adj[v][i];
		if (cnt[to] == 1) {
			cnt[to] = 2;
			return true;
		} else if (dfs(to)) return true;
	}
	return false;
}

int main() {
	int T; fscanf(inf, "%d", &T);
	for (int Tt = 0; Tt < T; Tt++) {
		int N; fscanf(inf, "%d", &N);
		for (int i = 0; i < N; i++) {
			fscanf(inf, "%d", &ca[i]);
			for (int j = 0; j < ca[i]; j++) {
				int v; fscanf(inf, "%d", &v);
				--v; adj[i][j] = v;
			}
		}
		fprintf(outf, "Case #%d: ", Tt+1);
		bool flag = false;
		for (int i = 0; i < N && !flag; i++) {
			memset(cnt, 0, sizeof(cnt));
			if (dfs(i)) flag = true;
		}
		if (flag) fprintf(outf, "Yes\n");
		else fprintf(outf, "No\n");
	}
}