#include <stdio.h>
#define MAX_N 10010

int L, X, N;
int A[MAX_N], P[MAX_N][MAX_N];
int table[5][5] = {{0, }, {0, 1, 2, 3, 4}, {0, 2, -1, 4, -3}, {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1}};

void init();
int solve();
int mul(int a, int b);

int main()
{
	int T, t, ans;
	char answer[2][5] = {"NO", "YES"};
	FILE* fp = fopen("C-small.out", "w");

	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		init();
		ans = solve();
		fprintf(fp, "Case #%d: %s\n", t, answer[ans]);
	}
	fclose(fp);
	return 0;
}

void init() {
	char tmp;
	int A_tmp[MAX_N], i, j;

	scanf("%d %d\n", &L, &X);
	N = L * X;
	for(i = 0; i < L; i++) {
		scanf("%c", &tmp);
		A_tmp[i] = tmp - 'g';
	}
	getchar();
	for(i = 0, j = 0; i < N; i++, j++) {
		j = (j % L);
		A[i] = A_tmp[j];
	}
	
	for(i = 0; i < N; i++) {
		P[i][i] = A[i];
		for(j = i + 1; j < N; j++) {
			P[i][j] = mul(P[i][j - 1], A[j]);
		}
	}
}

int solve() {
	int i, j;

	for(i = 0; i <= N - 3; i++) {
		if(P[0][i] != 2)	continue;
		for(j = i + 1; j <= N - 2; j++) {
			if(P[i + 1][j] != 3)	continue;
			if(P[j + 1][N - 1] == 4)	return 1;
		}
	}
	return 0;
}

int mul(int a, int b) {
	int neg = 1;

	if(a < 0) {
		neg *= -1;
		a *= -1;
	}
	if(b < 0) {
		neg *= -1;
		b *= -1;
	}
	return (neg * table[a][b]);
}
