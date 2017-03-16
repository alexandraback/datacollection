#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long *array, sum1, sum2;
int ok;

int cmp(const void *a, const void *b)
{
	long long x, y;
	x = *(long long *)a;
	y = *(long long *)b;
	return x-y;
}

void solve2(int st, int n, int target)
{
	int i,var;
	if (target == 0)
		ok = 1;
	else
		for (i = st + 1; i < n; ++i)
		{
			if (array[i] != 0)
			{
				var = array[i];
				array[i] = 0;
				solve2(i, n, target - var);
				if (ok == 1)
				{
					printf("%d ",var);
					return;
				}
				array[i] = var;
			}
		}
}

void solve(int st, int n, int sum)
{
	int i, var;
	if(sum != 0)
	{
		solve2(-1,n,sum);
		if (ok == 1)
			printf("\n");
	}
	for(i = st+1; i < n; ++i)
	{
		if (array[i] != 0 && ok == 0)
		{
			var = array[i];
			array[i] = 0;
			solve(i,n,sum+var);
			if (ok == 1)
			{
				printf("%d ",var);
				return;
			}
			array[i] = var;
		}
	}
}

int main()
{
	int t, n, i, x;
	scanf("%d", &t);
	x = 1;
	while (t)
	{
		t--;
		scanf("%d",&n);
		array = malloc(n * sizeof(long long));
		sum1 = sum2 = 0;
		ok = 0;
		for (i = 0; i < n; ++i)
		{
			scanf("%lld", &array[i]);
		}
		qsort(array, n, sizeof(long long), cmp);
		printf("Case #%d:\n",x);
		solve(-1,n, 0);
		if (ok == 1)
			printf("\n");
		else
			printf("Impossible\n");
		x++;
	}



	return 0;
}
