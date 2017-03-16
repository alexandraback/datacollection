#include <stdio.h>

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("s.out", "w", stdout);

	int t, cas;
	int n, m, i, j, k;
	int f;
	int field[105][105];

	scanf("%d", &t);
	for (cas=1; cas<=t; cas++)
	{
		scanf("%d%d", &n, &m);
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				scanf("%d", &field[i][j]);
		
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				f=0;
				for (k=0; k<m; k++)
					if (field[i][k]>field[i][j]) f=1;
				for (k=0; k<n; k++)
					if (field[k][j]>field[i][j]) 
						if (f) 
						{
							f=2;
							break;
						}
				if (f==2) break;
			}
			if (f==2) break;
		}
		printf("Case #%d: ", cas);
		if (f==2) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}