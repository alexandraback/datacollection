#include <stdio.h>
#include <math.h>
typedef long long LL;

int N,J;
int bit[21],bc;
LL non[21];
LL what[21] = 
{ 0, 0, 3, 2, 3, 2, 7, 2, 3, 2, 3,};

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
	freopen("C-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,T,x;
	scanf("%d",&T);

	for(t=1;t<=T;t++)
	{
		int count = 0;
		scanf("%d %d",&N, &J);
		int realN = N;
		if( N > 16 &&  N % 2 ) N = 15;
		else if( N > 16 ) N = 16;

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
			
			for(int k=2;k<=10;k++)
			{
				if( non[k] != what[k] ) 
				{
					isprime = 1;
					break;
				}
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
			if(realN != N)
			{
				printf("1");
				for(LL k=0;k<realN-N;k++) printf("%d",0);
				for(LL k=bc-2;k>=1;k--) printf("%d",bit[k]);
				printf("1");
				printf(" ");
				for(int k=2;k<=10;k++)printf("%lld ",non[k]);
				printf("\n");
			}
			else
			{
				for(LL k=bc-1;k>=0;k--) printf("%d",bit[k]);
				printf(" ");
				for(int k=2;k<=10;k++)printf("%lld ",non[k]);
				printf("\n");
			}
			if(count >= J) break;
		}
		//printf("count : %d\n",count);
	}
}