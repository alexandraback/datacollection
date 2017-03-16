#include <stdio.h>

int anss[1010000];
int z[20];
int main(void)
{
	int tt ,ii;
	int a ,b ,c;
	int i ,j ,j2;
	int sum;
	
	anss[0]=0;
	for (i=1 ; i<=1000000 ; i++)
	{
		for (j2=0 ; j2<=9 ; j2++)
		{
			z[j2]=1;
		}
		sum=0;
		b=i;
		while (b)
		{
			c=b%10;
			if (z[c])
			{
				z[c]=0;
				sum++;	
			}
			b/=10;
		}
		for (j=2 ;  ; j++)
		{
			b=i*j;
			while (b)
			{
				c=b%10;
				if (z[c])
				{
					z[c]=0;
					sum++;	
				}
				b/=10;
			}	
			if (sum==10)	
			{
				break;	
			}
		}
		anss[i]=j;	
	}
	scanf("%d" ,&tt);
	for (ii=1 ; ii<=tt ; ii++)
	{
		scanf("%d" ,&a);
		if (anss[a]==0)
		{
			printf("Case #%d: INSOMNIA\n" ,ii);			
		}
		else
		{
			printf("Case #%d: %d\n" ,ii ,anss[a]*a);
		}
	}
	
	return 0;
}
