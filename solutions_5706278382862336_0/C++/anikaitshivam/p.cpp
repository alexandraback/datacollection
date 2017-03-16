#include<cstdio>
#include<cmath>
#define lli long long int

lli arr[50], N;

lli GCD(lli a, lli b)
{
	if(b==0)
		return a;
	return GCD(b,a%b);
}

void make()
{
	lli t;
	N=0;
	t=pow(2,N);
	while(t<=1000000000000)
	{
		arr[N++]=t;
		t=pow(2,N);
	}
}


bool check(lli temp)
{
	lli i;

	for(i=0;i<N;i++)
		if(arr[i]==temp)
			return 1;
	return 0;
}

lli find(lli P, lli Q)
{
	lli i;
	for(i=0;i<N;i++)
		if(arr[i]*P>=Q)
			return i;
}


int main()
{
	lli t, T, P, Q, gcd, temp, ans;

	scanf("%lld",&T);

	make();

	for(t=1;t<=T;t++)
	{
		printf("Case #%lld: ",t);

		scanf("%lld/%lld",&P,&Q);

		gcd=GCD(P,Q);
		P/=gcd;
		Q/=gcd;

		if(check(Q))
		{
			ans=find(P,Q);
			printf("%lld\n",ans);

		}
		else
			printf("impossible\n");




	}
	return 0;
}
