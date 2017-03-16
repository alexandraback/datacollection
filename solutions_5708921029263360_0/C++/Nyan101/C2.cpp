#include <stdio.h>

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);	
	int T;
	int J, P, S, K;
	int PS[11][11], JP[11][11], SJ[11][11];
	int ans;
	
	scanf("%d", &T);
	for(int test_case=1;test_case<=T;test_case++)
	{
		scanf("%d %d %d %d", &J, &P, &S, &K);
		for(int i=0;i<11;i++)
		{
			for(int j=0;j<11;j++)
			{
				JP[i][j] = 0;
				PS[i][j] = 0;
				SJ[i][j] = 0;
			}
		}
		ans = 0;
		int p = 1;
		int s = 1;
		for(int j=1;j<=J;j++)
		{
			for(int a=1;a<=P;a++)
			{
				for(int b=1;b<=S;b++)
				{
					if(JP[j][p]<K && PS[p][s]<K && SJ[s][j]<K)
					{
						JP[j][p]++;
						PS[p][s]++;
						SJ[s][j]++;
						ans++;
					}
					s = ((s<S)? (s+1):1);
				}
				p = ((p<P)? (p+1):1);
			}
		}
		printf("Case #%d: %d\n", test_case, ans);

		for(int i=0;i<11;i++)
		{
			for(int j=0;j<11;j++)
			{
				JP[i][j] = 0;
				PS[i][j] = 0;
				SJ[i][j] = 0;
			}
		}
		p = 1;
		s = 1;
		for(int j=1;j<=J;j++)
		{
			for(int a=1;a<=P;a++)
			{
				for(int b=1;b<=S;b++)
				{
					if(JP[j][p]<K && PS[p][s]<K && SJ[s][j]<K)
					{
						JP[j][p]++;
						PS[p][s]++;
						SJ[s][j]++;
						printf("%d %d %d\n", j, p, s);
					}
					s = ((s<S)? (s+1):1);
				}
				p = ((p<P)? (p+1):1);
			}
		}
	}

	return 0;
}