#include <cstdio>
#include <cmath>

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tc = 0;++tc <= t;tc) {
		int d[50][50] = { 0, }, b;
		long long m;
		scanf("%d %lld", &b, &m);
		for (int i = 0;i < b - 1;++i)
			for (int j = i + 1;j<b;++j)
				d[i][j] = 1;

		printf("Case #%d: ", tc);
		long long max = pow(2, b - 2);
		if (max < m)printf("IMPOSSIBLE\n");
		else {
			max -= m;
			for (int i = 1;i < b-1;++i) {
				if (max & 1)
					d[i][b - 1] = 0;
				max >>= 1;
			}
			printf("POSSIBLE\n");
			for (int i = 0;i < b;++i) {
				for (int j = 0;j < b;++j)
					printf("%d", d[i][j]);
				printf("\n");
			}
		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}