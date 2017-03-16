#include<stdio.h>
#include<algorithm>
int in[110][60];
int ans[2500];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int TT = 1; TT <= T; TT++)
	{
		int i, j, n, t;
		scanf("%d", &n);
		for (i = 1; i <= 2500; i++) ans[i] = 0;
		for (i = 1; i <2*n; i++)for (j = 1, in[i][0] = 0; j <= n; j++)
		{
			scanf("%d", &t);
			ans[t]++;
		}
		printf("Case #%d: ", TT);
		for (i = 1; i <= 2500; i++)if(ans[i]%2 == 1) printf("%d ", i);
		printf("\n");
	}
	return 0;
}