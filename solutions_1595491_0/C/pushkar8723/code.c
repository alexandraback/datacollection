#include <stdio.h>
int main()
{
	int t, n, s, p, i, k, count, arr[100];
	scanf("%d", &t);
	for(k = 1; k <= t; k++)
	{
		count = 0;
		scanf("%d %d %d", &n, &s, &p);
		for(i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		for(i = 0; i < n; i++)
		{
			if(arr[i]%3 == 0 && arr[i]/3 >= p)
			{
				count++;
			}
			else if(arr[i]%3 != 0 && (arr[i] + (3-arr[i]%3))/3 >= p)
			{
				count++;
			}
			else if((arr[i]+2)%3 == 0 && (arr[i]+2)/3 >= p && s > 0 && arr[i] > 0)
			{
				count++;
				s--;
			}
			else if((arr[i]+2)%3 != 0 && ((arr[i]+2) + (3-(arr[i]+2)%3))/3 >= p && s > 0 && arr[i] > 0)
			{
				count++;
				s--;
			}
		}
		printf("Case #%d: %d\n", k, count);
	}
	return 0;
}
