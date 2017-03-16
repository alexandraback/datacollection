#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define MAXN 1000
#define INF 1000000000

int a[MAXN][MAXN];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d\n", &test);
	for (int q = 1; q <= test; q++) {
		int N, M;
		scanf("%d%d\n", &N, &M);
		vector < int > row(N, -INF);
		vector < int > column(M, -INF);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				scanf("%d", &a[i][j]);
				row[i] = max(row[i], a[i][j]);
				column[j] = max(column[j], a[i][j]);
			}
		bool ok = true;
		for (int i = 0; i < N && ok; i++)
			for (int j = 0; j < M && ok; j++) {
				if (a[i][j] < row[i] && a[i][j] < column[j]) {
					ok = false;
					break;
				}

				if (a[i][j] >= row[i])
					row[i] = a[i][j];
				if (a[i][j] >= column[j])
					column[j] = a[i][j];
			}
		if (ok)
			printf("Case #%d: YES\n", q);
		else
			printf("Case #%d: NO\n", q);
	}

	return 0;
}