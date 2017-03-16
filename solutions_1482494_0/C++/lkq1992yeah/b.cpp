#include <stdio.h>
#include <string.h>
#define MAXN 2000

int needs[MAXN][2];
int complete[MAXN][2];

void Solve()
{
	int n, idx, a, b, i, cnt = 0, ret = 0, flag = 1, star = 0;
	int mval, midx;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		needs[i][0] = a;
		needs[i][1] = b;
	}
	// printf("\n");
	// for (i = 0; i < 2 * n; i++)
		// printf("%d: %d %d %d\n", i, ori[i].idx, ori[i].lvl, ori[i].need);
	memset (complete, 0, sizeof complete);
	/*
	while (cnt < n)
	{
		flag = 0;
		for (i = 0; i < 2 * n; i++)
		{
			idx = ori[i].idx;
			a = ori[i].lvl - 1;
			b = ori[i].need;
			// printf("			i = %d  idx = %d  a = %d  b = %d  star = %d\n", i, idx, a, b, star);
			if (star < b || complete[idx][a] == 1 || complete[idx][1] == 1)
				continue;
			// printf("Now i = %d star = %d lvl = %d need = %d\n", i, star, a, b);
			flag = 1;
			complete[idx][a] = 1;
			ret++;
			if (a == 1)
				cnt++;
			if (a == 0) star += 1;
			else if (a == 1 && complete[idx][0] == 0) star += 2;
			else star += 1;
			
			break;
		}
		if (flag == 0)
			break;
	}
	*/
	// printf("\n");
	while (cnt < n)
	{
		for (i = 0; i < n; i++)
		{
			if (complete[i][1] == 0 && star >= needs[i][1])
			{
				// printf("Now choose Lv2 i = %d star = %d\n", i, star);
				cnt++;
				ret++;
				if (complete[i][0] == 0)
					star += 2;
				else
					star += 1;
				complete[i][1] = complete[i][0] = 1;
				break;
			}
		}
		// printf("i = %d star = %d\n", i, star);
		if (i < n)
			continue;
		for (i = 0, mval = midx = -1; i < n; i++)
		{
			if (complete[i][0] == 0 && star >= needs[i][0])
			{
				if (needs[i][1] > mval)
				{
					mval = needs[i][1];
					midx = i;
				}
			}
		}
		// printf("midx = %d\n", midx);
		if (midx == -1)
			break;
		ret++;
		complete[midx][0] = 1;
		star++;
	}
	
	if (cnt < n)
		printf("Too Bad\n");
	else
		printf("%d\n", ret);
}

int main()
{
	int i, cas;
	scanf("%d", &cas);
	for (i = 1; i <= cas; i++)
	{
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}
