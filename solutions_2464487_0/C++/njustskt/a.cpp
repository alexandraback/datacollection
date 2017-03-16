#include <cstdio>
#include <cstring>
#define LL long long
LL R,T;
int main()
{
	int t,d = 1,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&R,&T);
		R = 2*R - 1;
		for( i = 1 ; i <= T ; i ++)
		{
			if(T >= (2*i*i + i*R) && T < (2*(i+1)*(i+1) + (i+1)*R))
			{
				printf("Case #%d: %d\n",d++,i);
			}
		}
	}
	return 0;
}
