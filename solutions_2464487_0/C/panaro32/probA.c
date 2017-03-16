#include <stdio.h>
#include <stdlib.h>

#define bignum long long int

int main()
{
	int T,i;
	scanf("%d",&T);
	bignum r,t,s;
	for(i=0;i<T;i++)
	{
		scanf("%lld%lld",&r,&t);
		s=0;
		r++;
		while(t>=2*r-1)
		{
			s++;
			t-=2*r-1;
			r+=2;
		}
		printf("Case #%d: %lld\n",i+1,s);
	}
	return 0;
}
