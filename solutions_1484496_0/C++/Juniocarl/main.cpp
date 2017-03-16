#include <stdio.h>

#define SIZE 250000
int num[SIZE];

int main()
{
	int t;
	scanf("%d",&t);
	int i,j,k,q;
	for(int caso=1;caso<=t;caso++)
	{	
		int n;
		int num[50];
		printf("Case #%d:\n",caso);
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		
		bool f = false;
		for(i=1;i<(1<<20)&&!f;i++)
		{
			for(j=1;j<(1<<20)&&!f;j++)
			{
				if ( (i & j) == 0 )
				{
					int sumA = 0;
					int sumB = 0;
					for( k = 0 ; k < 20 ; k++ )
					{
						if ( i & (1<<k) )
							sumA+= num[k];
					}
					for( q = 0 ; q < 20 ; q++ )
					{
						if ( j & (1<<q) )
							sumB+= num[q];
					}
					if ( sumA == sumB )
					{
						for( k = 0 ; k < 20 ; k++ )
						{
							if ( i & (1<<k) )
								printf("%d ",num[k]);
						}
						printf("\n");
						for( q = 0 ; q < 20 ; q++ )
						{
							if ( j & (1<<q) )
								printf("%d ", num[q]);
						}	
						printf("\n");
						f = true;
					}
				}
			}
			
		}	
		if ( !f )
				printf("Impossible\n");

	}
	return 0;
}