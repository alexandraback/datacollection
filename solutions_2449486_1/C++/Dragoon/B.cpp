#include<stdio.h>

#define MAX(A, B) ((A)>(B)?(A):(B))
#define MIN(A, B) ((A)<(B)?(A):(B))

int num[102][102], row[102], col[102];

int main()
{
	int T, ks, i, j, R, C, ok;

//	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("B-small-attempt0.out", "w", stdout);

	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	scanf("%d", &T);
	for(ks = 1; ks <= T; ks++)
	{
		scanf("%d%d", &R, &C);

		for(i = 0; i < 100; i++)
			row[i] = col[i] = 0;

		for(i = 0; i < R; i++)
			for(j = 0; j < C; j++)
			{
				scanf("%d", &num[i][j]);

				row[i] = MAX(row[i], num[i][j]);
				col[j] = MAX(col[j], num[i][j]);
			}

		ok = 1;
		for(i = 0; i < R; i++)
			for(j = 0; j < C; j++)
				if( num[i][j] != MIN(row[i], col[j]) )
					ok = 0;

		if(ok) printf("Case #%d: YES\n", ks);
		else printf("Case #%d: NO\n", ks);
	}

	return 0;
}