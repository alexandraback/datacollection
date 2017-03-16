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
	int t, a, b, i, k, m, n, p, count, chk, br[10],flag,z;
	scanf("%d", &t);
	for(k = 1; k <= t; k++)
	{
		count = 0;
		scanf("%d %d", &a, &b);
		for(i = a; i <= b; i++)
		{
			n = i;
			p = size(i);
			chk = 0;
			for(m = 1; m < p; m++)
			{
				n = n/po(10,p-1) + (n%po(10,p-1))*10;
				//printf("%d ", n);
				if(n > i  && n <= b)
				{  
					flag = 0;
					for(z = 0; z < chk; z++)
					{
						if(br[z] == n)
							flag = 1;
					} 
					if(flag == 0)
					{
						count++;
						br[chk] = n;
						chk++;
						//printf("%d %d\n", i,n);
					}
				}				
			}
		}
		printf("Case #%d: %d\n", k, count);
	}
	return 0;
}
