#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 256;

bool find_one;

int c[MAXN][MAXN];
int t[MAXN], k[MAXN];
int key[MAXN];
int out[MAXN], cc[MAXN];
int N, K;
bool visit[MAXN];

void dfs(int d) {
	if (find_one) return;
	if (d == N) {
		find_one = true;
		for (int i=0; i<N; ++i) out[i] = cc[i] + 1;
		return;
	}
	for (int i=0; i<N; ++i) if (!visit[i]) {
		if (!key[t[i]]) continue;
		cc[d] = i;
		visit[i] = true;
		--key[t[i]];
		for (int j=0; j<k[i]; ++j) ++key[c[i][j]];
		dfs(d+1);
		if (find_one) return;
		visit[i] = false;
		++key[t[i]];
		for (int j=0; j<k[i]; ++j) --key[c[i][j]];
	}
}

int main() {
	int tc, cn = 0;
	int x;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &K, &N);
		for (int i=0; i<K; ++i) scanf("%d", &x), ++key[x];
		for (int i=0; i<N; ++i) {
			scanf("%d%d", t+i, k+i);
			for (int j=0; j<k[i]; ++j) scanf("%d", c[i]+j);
		}
//		puts("read over");
		find_one = false;
		memset(visit, false, sizeof(visit));
		dfs(0);
		printf("Case #%d: ", ++cn);
		if (find_one) for (int i=0; i<N; ++i) printf("%d%s", out[i], i==N-1?"\n":" ");
		else puts("IMPOSSIBLE");
	}

	return 0;
}
