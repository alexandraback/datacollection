#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
double f[5001][5001] = {0};
main()
{
	FILE *fp, *fo;
	fp = fopen("bb.in", "r");
	fo = fopen("bb.out", "w");
	int tot;
	fscanf(fp, "%d", &tot);
	for (int tt = 1; tt <= tot; tt++)
	{
	//	printf("%d\n", tt);
		double pob;
		int n, vx, vy;
		memset(f, 0, sizeof(f));
		fscanf(fp, "%d%d%d", &n, &vx, &vy);
		int s1, s2;
		vx = abs(vx);
		vy = abs(vy);
		s1 = (vx + vy) >> 1;
		s1++;
		s2 = vy;
		int si = 0;
		for (int j = 1; j < s1; j++, si+= 2)
		{
			n -= (si * 2 +1);
			if (n <= 0)
				break;
		}
		if (n >= si * 2 + 1)
			pob = 1;
		else if (n <= 0)
			pob = 0;
		else
		{
			f[0][0] = 1;
			for (int i = 0; i < n; i++)
			{
				for (int j = max(0, i-si); j <= si && j <= i; j++)
				{
					int k = i - j;
					if (k >= 0 && k <= si)
					{
						if (j == si)
							f[i+1][j] += f[i][j];
						else if (k == si)
							f[i+1][j+1] += f[i][j];
						else
						{
							f[i+1][j] += f[i][j]*0.5;
							f[i+1][j+1] += f[i][j]*0.5;
						}
					}
				}
			}
			if (vy != si)
			{
				pob = 0;
				for (int j = vy+1; j <= si && j <= n; j++)
					pob += f[n][j];
			
			}else
				pob = (n >= 2 * si + 1);
		}
		fprintf(fo, "Case #%d: %.7lf\n", tt, pob);
	}
	fclose(fp);
	fclose(fo);
	return 0;
}
