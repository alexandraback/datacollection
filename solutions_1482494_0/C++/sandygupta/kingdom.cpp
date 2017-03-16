#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int star1[1002] ; 
int star2[1002] ;
int flag[1002] ; 

int main()
{
	int t ; 
	int i ;
	int n ;
	int ans ; 
	int st ; 
	int cc ; 
	int use ; 
	int currStar ;
	int total = 1 ;
	int status ; 
	scanf("%d",&t);

	while(t--)
	{
		memset(flag , 0 , sizeof(flag));
		scanf("%d",&n);
		for(i = 0 ; i < n ;i++)
			scanf("%d%d",&star1[i],&star2[i]);

		currStar = 0 ; 
		ans = 0 ;
		st = 0 ; 


		while(1)
		{
			cc = 0; 
			for(i = 0 ; i < n ; i++)
			{
				if(star2[i] <= currStar || star1[i] <= currStar)
				{	
					cc = 1 ; 
					break ;
				}
			}
			if(cc == 0)
				break ;

			status = 0 ; 

			for(i = 0 ; i < n ; i++)
			{
				if(flag[i] == 0)
				{
					if(star2[i] <= currStar)
					{
						flag[i] = 1 ; 
						currStar += 2 ;
						ans ++ ; 
						status = 1 ; 
					}
				}
			}

			if(status == 0)
			{
				for(i = 0 ; i < n ; i++)
				{
					if(flag[i] == 1)
					{
						if(star2[i] <= currStar)
						{
							currStar += 2 ; 
							ans ++ ; 
							status = 1 ;
							break ; 
						}
					}
				}
			}

			if(status == 0)
			{
				for(i =0 ; i < n ; i++)
				{
					if(star1[i] <= currStar)
					{
						currStar += 1 ; 
						ans ++ ; 
						status = 1 ; 
						break ; 
					}
				}
			}

			use = 0 ; 

			for(i = 0 ; i < n ; i++)
			{
				if(flag[i] == 0)
				{
					use = 1 ; 
					break ; 
				}
			}
			if(use == 0)
				break ; 
		}

		use = 0  ;
		for(i = 0 ; i < n ; i++)
		{
			if(flag[i] == 0)
			{
				use = 1 ; 
				break ; 
			}
		}
		if(use == 1)
			printf("Case #%d: Too Bad\n",total++);
		else
			printf("Case #%d: %d\n",total++,ans);
	}
	return 0;
}
