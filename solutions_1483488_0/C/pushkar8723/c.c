#include <stdio.h>
#include <math.h>
int size(int a)
{
	int count=0;
	while(a != 0)
	{
		count++;
		a = a/10;
	}
	return count;
}
int po(int a, int b)
{
	int res = 1;
	while(b--)
	 res*= a;
	return res;
}
int main()
{
	int t, a, b, i, k, m, n, p, count;
	scanf("%d", &t);
	for(k = 1; k <= t; k++)
	{
		count = 0;
		scanf("%d %d", &a, &b);
		for(i = a; i <= b; i++)
		{
			n = i;
			p = size(i);
			for(m = 1; m < p; m++)
			{
				n = n/10 + (n%10)*po(10,p-1);
				if(n > i  && n <= b)
				{  
					count++;
					//printf("%d %d\n", i,n);
				}					
			}
		}
		printf("Case #%d: %d\n", k, count);
	}
	return 0;
}
