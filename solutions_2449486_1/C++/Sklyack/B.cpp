#include <cstdio>

const int MAXN=100;
int A[MAXN][MAXN], rm[MAXN], cm[MAXN];

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, T;
	int n, m, i, j;
	bool pos;

	scanf("%d", &T);
	for(t=1; t<=T; ++t)
	{
		scanf("%d%d", &n, &m);
		for(j=0; j<m; ++j)
			cm[j]=0;
		for(i=0; i<n; ++i)
		{
			rm[i]=0;
			for(j=0; j<m; ++j)
			{
				scanf("%d", A[i]+j);
				if(rm[i]<A[i][j])
					rm[i]=A[i][j];
				if(cm[j]<A[i][j])
					cm[j]=A[i][j];
			}
		}
		pos=true;
		for(i=0; i<n; ++i)
			for(j=0; j<m; ++j)
				pos &= (A[i][j]==rm[i] || A[i][j]==cm[j]);

		printf("Case #%d: %s\n", t, pos ? "YES" : "NO");
	}
	return 0;
}
