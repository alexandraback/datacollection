#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 105
int val[N];
int num[N];
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main()
{
	int n, i, a;
	int tcase, icase = 1;
	scanf("%d", &tcase);
	while(tcase--)
	{
		scanf("%d%d", &a, &n);
		for(i = 0; i < n; i++)
			scanf("%d", &val[i]);
		qsort(val, n, sizeof(int), cmp);
		memset(num, 0, sizeof(num));
		int sum = 0;
		printf("Case #%d: ", icase++);
		bool flag = true;
		for(i = 0; i < n; i++)
		{
			if(val[i] < a)
			{
				a += val[i];
				if(i)
					num[i] = num[i - 1];
			}
			else
			{
				if(a - 1 == 0)
				{
					flag = false;
					break;
				}
				int t1 = 0;
				while(a <= val[i])
				{
					a += (a - 1);
					t1++;
				}
				a += val[i];
				if(i)
					num[i] = num[i - 1] + t1;
				else
					num[i] = t1;
			}
		}
		if(!flag)
		{
			printf("%d\n", n - i);
		}
		else
		{
			int min = 0x7fffffff;
			min = num[0] + n - 1 > n?n:num[0] + n - 1;
			for(i = 1; i < n; i++)
			{
				if(min > num[i] + n - i - 1)
				   min = num[i] + n - i - 1;
			}	
			printf("%d\n", min);
		}
	}
	return 0;
}
