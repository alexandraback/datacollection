#include <stdio.h>
#include <math.h>
typedef long long LL;

int N,J;
int bit[20],bc;
LL non[20];

LL isprime_f(LL x)
{
	LL xx = sqrt(double(x));
	for(LL a=2;a<=xx;a++)
	{
		if(x%a==0)return a;
	}
	return 1;
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,T,x;
	scanf("%d",&T);

	for(t=1;t<=T;t++)
	{
		int count = 0;
		scanf("%d %d",&N, &J);
		printf("Case #%d: \n",t);
		for(x=0;x<(1<<(N-2));x++)
		{
			LL r = (x<<1) + 1 + (1<<(N-1));
			LL isprime = 0;
			for(LL k=2;k<=10;k++)
			{
				LL rr = r;
				LL w=1;
				LL sum = 0;
				while(rr)
				{
					sum += w*(rr%2);
					w *= k;
					rr/=2;
				}
				LL div = isprime_f(sum);
				if( div == 1 )
				{
					isprime = 1;
					break;
				}
				non[k]  = div;
			}
			if( isprime ) continue;
			count++;
			LL rr = r;
			bc = 0;
			while(rr)
			{
				bit[bc++] = (rr%2);
				rr/=2;
			}
			for(LL k=bc-1;k>=0;k--) printf("%d",bit[k]);
			printf(" ");
			for(int k=2;k<=10;k++)printf("%lld ",non[k]);
			printf("\n");
			if(count>=J)break;
		}
	}
}