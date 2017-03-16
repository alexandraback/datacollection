#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
char p[4844492][15] = {0};
int f[101][10] = {0};
int last, pay, n;
char a[101];
int calc(int v, char *b, int la)
{
	pay = 0;
	int m = strlen(b) -1;
	if (m > n - v)
		return 0;
	for (int i = 0; i < m; i++)
	{
		if (b[i] != a[v+i])
		{
			if (la == 0)
			{
				la = 5;
				pay++;
			} else
				return 0;
		}
		if(la>0)
		la--;
	}
	last = la;
	return 1;
}
main()
{
	int tot;
	FILE *fp, *fo, *fq;
	fq = fopen("dict.txt", "r");
	fp = fopen("cc.in", "r");
	fo = fopen("cc.out", "w");
	fscanf(fp, "%d\n", &tot);
	for (int i = 1; i <= 3844492; i++)
	{
		fgets(p[i], 15, fq);
	}
	for (int tt = 1; tt <= tot; tt++)
	{
		cout << tt;
		fscanf(fp, "%s", a);
		n = strlen(a);
		memset(f, 0, sizeof(f));
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= 5; j++)
				f[i][j] = 1000000;
		f[0][0] = 0;
		for (int i = 0; i < n; i++)
		{
			
			for (int j = 0; j <= 5; j++)
			if(f[i][j] !=1000000)
			{
				for (int l = 1; l <= 3844492; l++)
				{
					if(p[l][0] == 'c' &&p[l][1] =='o'&&p[l][2] =='d' &&p[l][3] == 'e')
						int ii = 0;
					if (calc(i, p[l], j))
					{
						int pop = i+strlen(p[l])-1;
						f[pop][last] = min(f[pop][last], f[i][j] + pay);
						if(pop == 7 && last == 0 && f[pop][last]==1)
							int opo = 0;
					}
				}
			}
		}
		int ans = 1000000;
		for (int i = 0; i <= 5; i++)
				ans = min(ans, f[n][i]);
		fprintf(fo, "Case #%d: %d\n", tt, ans);
	}
	fclose(fp);
	fclose(fo);
	fclose(fq);
	return 0;
}
