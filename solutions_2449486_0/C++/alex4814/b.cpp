#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define EPS 1e-8
#define MAXN 105
#define PI acos(-1.0)

int T, N, M;
int height[MAXN][MAXN];

int greater(int r, int c)
{
	int fr = 0, fc = 0;
	for (int j = 0; j < M; ++j) {
		if (height[r][j] > height[r][c]) fc = 1;
	}
	for (int i = 0; i < N; ++i) {
		if (height[i][c] > height[r][c]) fr = 1;
	}
	return fc & fr;
}

int ok()
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (greater(i, j)) return 0;
		}
	}
	return 1;
}

int main()
{
	scanf("%d", &T);
	for (int n_case = 1; n_case <= T; ++n_case) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				scanf("%d", &height[i][j]);
			}
		}
		printf("Case #%d: ", n_case);
		puts(ok() ? "YES" : "NO");
	}
	return 0;
}
