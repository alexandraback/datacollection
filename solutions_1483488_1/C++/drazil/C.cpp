#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int used[11000000] ;
int ten[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000} ;

int main(void)
{
	int a, b ;
	int t ;
	int c, i ;

	scanf("%d",&t) ;
	for(c=1;c<=t;c++)
	{
		memset(used,0,sizeof(used)) ;
		int d = 0, ans = 0, tmp ;
		scanf("%d%d",&a,&b) ;
		tmp = a ;
		while(tmp)
		{
			d++ ;
			tmp /= 10 ;
		}
		
		int n ;
		for(n=a;n<=b;n++)
		{
			for(i=1;i<d;i++)
			{
				if((n%ten[i])/ten[i-1]!=0)
				{
					tmp = (n%ten[i])*ten[d-i]+(n/ten[i]) ;
					if(tmp>n&&tmp<=b&&used[tmp]!=n)
					{
						used[tmp] = n ;
						ans++ ;
					}
				}
			}
		}
		
		printf("Case #%d: %d\n",c,ans) ;
	}
	
	return 0 ;
}
