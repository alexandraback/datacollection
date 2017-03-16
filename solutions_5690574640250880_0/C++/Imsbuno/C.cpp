#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;


int f[55][55][2555];
int g[55][55][2555];
int a[55];
int M, N, A, B;


int extend(int x) {
	if (!x) return x;
	return min(x + 1, N);
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	
	int testCaseNum;
	scanf("%d", &testCaseNum);
	for (int testCase = 1; testCase <= testCaseNum; ++testCase) {
		scanf("%d%d%d", &M, &N, &A);
		printf("Case #%d:\n", testCase);
		if (A == M * N - 1) {
			for (int i = 1; i <= M; ++i) {
				for (int j = 1; j <= N; ++j)
					printf("%c", (i == 1 && j == 1) ? 'c' : '*');
				printf("\n");
			}
			continue;
		}
		
		B = M * N - A;
		memset(f, 0, sizeof(f));
		for (int j = 1; j <= N; ++j) {
			f[1][j][extend(j)] = 1;
			g[1][j][extend(j)] = j;
		}
		
		for (int i = 1; i < M; ++i)
			for (int j = 0; j <= N; ++j)
				for (int k = 1; k <= i * N; ++k)
					if (f[i][j][k])
						for (int p = 0; p <= j; ++p) {
							f[i + 1][p][k + extend(j)] = 1;
							g[i + 1][p][k + extend(j)] = j;
						}

		int I = -1, J, K;				
		for (int j = 0; j <= N; ++j)
			if (f[M][j][B])
				I = M, J = j, K = B;
		
		if (I == -1) {
			printf("Impossible\n");
			continue;
		}
		
		while (I > 0) {
			int JJ = g[I][J][K];
			a[I] = extend(JJ);
			I--;
			J = JJ;
			K -= extend(JJ);
		}
		
		for (int i = 1; i <= M; ++i) {
			for (int j = 1; j <= N; ++j)
				if (i == 1 && j == 1) printf("c"); else
					printf("%c", (j <= a[i]) ? '.' : '*');
			printf("\n");
		}
	}
	
	return 0;
}