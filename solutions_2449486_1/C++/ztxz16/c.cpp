#include <stdio.h>
#include <stdlib.h>

int n, m, a[105][105];
int test, tt, i, j, i2, j2;
bool no, tmp;

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &test);
    for (tt = 1; tt <= test; tt++)
    {
		scanf("%d%d",&n,&m);
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		no = 0;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				for (i2 = 1; i2 <= n; i2++)
					if (a[i2][j] > a[i][j])
						break;
				if (i2 > n)
					continue;
				for (j2 = 1; j2 <= m; j2++)
					if (a[i][j2] > a[i][j])
						break;
				if (j2 > m)
					continue;
				no = 1;
				break;
			}
			
			if (no == 1)
				break;
		}
		
		if (no == 1)
			printf("Case #%d: NO\n",tt);
		else
			printf("Case #%d: YES\n",tt);
    }
    
    return 0;
}
