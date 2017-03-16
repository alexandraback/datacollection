#include <stdio.h>

int n, hik[1000][4];

void switc()
{
	int t0 = hik[0][0], t1 = hik[0][1], t2 = hik[0][2];
	hik[0][0] = hik[1][0];
	hik[0][1] = hik[1][1];
	hik[0][2] = hik[1][2];
	hik[1][0] = t0;
	hik[1][1] = t1;
	hik[1][2] = t2;
	return; 
}

int main()
{
	int tt, k;
	scanf("%d", &tt);
	for(k = 1; k <= tt; k++)
	{
		scanf("%d", &n);
		int i;
		for(i = 0; i < n; i++)
			scanf("%d%d%d", &hik[i][0], &hik[i][1], &hik[i][2]);
		if(n == 1)
		{
			printf("Case #%d: 0\n", k);
			continue;
		}
		if(n == 2)
		{
			if(hik[0][2] < hik[1][2])
				switc();
			double frac0 = (360 - hik[0][0]) / 360.0;
			double tim0 = frac0 * hik[0][2];
			double frac1 = (360 - hik[1][0]) / 360.0;
			double tim1 = frac1 * hik[1][2] + hik[1][2];
			//printf("%lf %lf %lf %lf\n", tim0, tim1, frac0, frac1);
			if(tim1 <= tim0)
				printf("Case #%d: 1\n", k);
			else
				printf("Case #%d: 0\n", k);
		}
		else
			printf("Case #%d: 0\n", k);
	}
	return 0;
}
