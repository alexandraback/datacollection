#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
int a[1200001] = {0};
main()
{
	FILE *fo, *fp;
	fp = fopen("aa.in", "r");
	fo = fopen("aa.out", "w");
	int tot;
	fscanf(fp, "%d", &tot);
	for (int tt = 1; tt <= tot; tt++)
	{
		int n, m, ans = 100000000, now = 0;
		fscanf(fp, "%d%d", &m, &n);
		for (int i = 1; i <= n; i++)
			fscanf(fp, "%d", &a[i]);
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
		{
			if (m > a[i])
			{
				m += a[i];
			} else
			{
				ans = min(ans, now + n - i + 1);
				if (m == 1) {now = ans;break;}
				m += m - 1;
				now++;
				i--;
			}
		}
		if (now < ans) ans = now;
		fprintf(fo,"Case #%d: %d\n", tt, ans);
	}
	fclose(fp);
	fclose(fo);
	return 0;
}
