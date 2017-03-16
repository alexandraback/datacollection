#include <bits/stdc++.h>

using namespace std;

const int MAXN = 60;
int N;
int a[2*MAXN][MAXN];
map<int, int> M;

int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++) {
		scanf("%d", &N);
		M.clear();
		for (int i = 1; i < 2 * N; i++) 
			for(int j = 1; j <= N; j++) {
				scanf("%d", &a[i][j]);
				M[a[i][j]]++;
			}
		printf("Case #%d: ", tt);
		for(auto &v : M) {
			if (v.second % 2 == 1) printf(" %d", v.first);
		}
		puts("");
	}
	return 0;
}
