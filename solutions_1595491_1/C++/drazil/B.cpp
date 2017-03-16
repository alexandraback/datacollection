#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max[110] ;
int sur[110] ;

int main(void)
{
	memset(max,0,sizeof(max)) ;
	memset(sur,0,sizeof(sur)) ;
	
	int a, b, c ;
	for(a=0;a<=10;a++)
	{
		for(b=a;b<=10;b++)
		{
			for(c=b;c<=10;c++)
			{
				if(b-a<=1&&c-b<=1&&c-a<=1)
				{
					if(max[a+b+c]<c) max[a+b+c] = c ;
				}
				else if(b-a<=2&&c-b<=2&&c-a<=2)
				{
					if(sur[a+b+c]<c) sur[a+b+c] = c ;
				}
			}
		}
	}
	
	int t ;
	scanf("%d",&t) ;
	
	for(a=1;a<=t;a++)
	{
		int n, s, p, v, ans = 0 ;
		scanf("%d%d%d",&n,&s,&p) ;
		while(n--)
		{
			scanf("%d",&v) ;
			if(max[v]>=p) ans++ ;
			else if(sur[v]>=p&&s>0)
			{
				s-- ;
				ans++ ;
			}
		}
		printf("Case #%d: %d\n",a,ans) ;
	}
	
	return 0 ;
}
