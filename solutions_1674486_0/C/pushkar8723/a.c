#include <stdio.h>
int main()
{
	int t, n, k, i, m, p;
	scanf("%d", &t);
	for(i = 1; i <= t; i++)
	{
		int flag = 0, flag1 = 0, flag2 = 0, mark[1000] = {0}, mark1[1000] = {0};
		scanf("%d", &n);
		m = n;
		while(m--)
		{
			scanf("%d", &k);
			if(k > 1)
				flag2 = 1;
			else
				mark1[k-1] = 1;			
			while(k--)
			{
				scanf("%d", &p);
				mark[p-1] = mark[p-1] + 1;
			}
		}
		for(m = 0; m < n; m++)
			if(mark[m] > 1)
			{
				flag = 1;
				break;
			}
		for(m = 0; m < n; m++)
			if(mark[m] == 0)
				break;
		if(m == n)
			flag1 = 1;
		else
		{
			for(m = 0; m < n; m++)
				if(mark[m] >= 2 && mark1[m] == 0)
					flag1 = 1;
		}
		if( flag == 1 && flag1 == 1 && flag2 == 1)
			printf("Case #%d: Yes\n", i);
		else
			printf("Case #%d: No\n", i);
	}
	return 0;
}
