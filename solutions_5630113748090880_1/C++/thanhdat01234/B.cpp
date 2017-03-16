#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

void openFile() {
	freopen("in.inp", "r", stdin);
	freopen("ou.out", "w", stdout);
}

int M, N, cnt[3000], T;

int main(int argc, char **argv) {
	openFile();
	scanf("%d", &T);
	for (int itest = 0; itest < T; ++itest) {
		scanf("%d", &N);
		M = 2 * N - 1;
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < M; ++i)
			for (int j = 0, x; j < N; ++j) {
				scanf("%d", &x);
				++cnt[x];
			}
		printf("Case #%d:", itest + 1);
		for (int i = 1; i <= 2500; ++i)
			if (cnt[i] & 1) printf(" %d", i);
		printf("\n");
	}

	return 0;
}
