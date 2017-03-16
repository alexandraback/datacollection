#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int s[1100][2] ;
int n ;
int rest ;
int beat[1100] ;

int main(void)
{
	int t ;
	int a ;
	scanf("%d",&t) ;
	
	for(a=1;a<=t;a++)
	{
		int ans = 0 ;
		int i ;
		
		scanf("%d",&n) ;
		rest = 2*n ;
		memset(beat,0,sizeof(beat)) ;
		
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&s[i][0],&s[i][1]) ;
		}
		
		int sc = 0 ;
		
		while(rest)
		{
			ans ++ ;
			int tar = -1 ;
			for(i=0;i<n;i++)
			{
				if(beat[i]<2&&s[i][1]<=sc)
				{
					rest -= 2-beat[i] ;
					sc += 2-beat[i] ;
					beat[i] = 2 ;
					tar = -2 ;
					break ;
				}
				else if(beat[i]==0&&s[i][0]<=sc)
				{
					if(tar==-1||s[tar][1]<s[i][1])
					{
						tar = i ;
					}
				}
			}
			if(tar>=0)
			{
				beat[tar] = 1 ;
				rest-- ;
				sc++ ;
			}
			else if(tar==-1)
			{
				break ;
			}
		}
		
		printf("Case #%d: ",a) ;
		if(rest==0)
		{
			printf("%d\n",ans) ;
		}
		else
		{
			printf("Too Bad\n") ;
		}
	}
	
	return 0 ;
}
