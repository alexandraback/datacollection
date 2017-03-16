#include <stdio.h>

int pot[] = 
{	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000
};


int rot(int num,int dig)
{
	int ret = num/10;
	ret+=(num%10)*pot[dig-1];
	return ret;
}


int main()
{
	int t;
	scanf("%d",&t);
	for(int tcnt=1; tcnt<=t; ++tcnt)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		int dig;
		long long int resp = 0;
		for(dig=0;b/pot[dig]>0;++dig);
		for(int c = a; c<=b; ++c)
		{
			int tmp = rot(c,dig);
			while(tmp!=c)
			{
				if(tmp<c && tmp>=a)
					++resp;
				tmp = rot(tmp,dig);
			}
		}
		printf("Case #%d: %lld\n",tcnt,resp);
	}
	return 0;
}

