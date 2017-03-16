#include<stdio.h>

int not( int a[12] , int x,int n)
{	int i;
	for( i = 0 ; i < n ; i++)
	{	if(a[i] == x)
			return 0;
	}
	return 1;
}
	

int main()
{
	int r,m,n;
	int x,i,j,k,temp,fact;
	int ans[12];
	
	scanf("%d",&x);
	scanf("%d%d%d%d",&r,&n,&m,&k);
	printf("Case #1:\n");
	for( i = 0 ; i < r ; i++)
	{	x = 0;
		for( j = 0 ; j < k && x <12 ; j++)
		{	scanf("%d",&temp);
			if(temp > 1 && temp <= 8)
			{	if(not(ans,temp,x))
				{	ans[x] = temp;
					x++;
				}
			}		
			else if(temp > 1)
			{	fact = 8;
				while(temp && x < 12 && fact > 1)
				{	if( temp % fact == 0 && not(ans,fact,x))
					{	ans[x] = fact;
						x++;
						temp /= fact;
					}
					else fact--;
				}
			}
			//printf("%d",x);
		}
		if(x == 12)
		{	for( ; j < k ; j++)
			  scanf("%d",&temp);
		}
		while(x < 12)
		{	ans[x] = 2;
			x++;
		}
		for( j = 0 ; j < 12 ; j++)
			printf("%d",ans[j]);
		printf("\n");
	}		
	return 0;
}

	
