#include<stdio.h>
int main()
{
	freopen("A-small-attempt2.in","r",stdin);
	freopen("A-small-attempt2.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int a=1;a<=t;a++)
	{
		long long n;
		long long arr[15];
		long long sum=0;
		long long x=0;
		scanf("%lld",&n);
		if(n%10==0)
		{
			n-=1;
			sum+=1;
		}
		
		int s=0;
		for(long long i=n; i!=0; i/=10,s++)
			arr[s]=i%10;
		
		for(int i=0;i<s/2;i++)
		{
			x*=10;
			x+=arr[s-i-1];
		}
		for(int i=s/2;i<s;i++,x*=10);	x+=1;
		//printf("ch x=%lld\n",x);
		if(n>=x)
		{
			sum+=n-x+1;
			s=0;	n=0;
			for(long long i=x; i!=0; i/=10,s++)
				arr[s]=i%10;
			for(int i=0;i<s;i++)
			{
				n*=10;
				n+=arr[i];
			}
			if(n==x)
				sum-=1;
			//printf("ch n=%lld\n",n);
		}
		
		x=9999990000001;	// x = 999999 000000 1	13digit
		if(n>=x)	
		{
			sum+=n-x+1;
			n=1000000999999;
		}
		x=999999000001;		// x = 999999 000001	12 digit
		if(n>=x)
		{
			sum+=n-x+1;
			n=100000999999;
		}
		x=99999000001;		// x= 99999 00000 1		11 digit
		if(n>=x)
		{
			sum+=n-x+1;
			n=10000099999;
		}
		x=9999900001;		// x= 99999 00001	10 digit
		if(n>=x)
		{
			sum+=n-x+1;
			n=1000099999;
		}
		x=999900001;	// x= 9999 0000 1	9 digit
		if(n>=x)
		{
			sum+=n-x+1;
			n=100009999;
		}
		x=99990001;		// x= 9999 0001		8 digit
		if(n>=x)
		{
			sum+=n-x+1;
			n=10009999;
		}
		x=9990001;		// x= 999 000 1		7 digit
		if(n>=x)
		{
			sum+=n-x+1;
			n=1000999;
		}
		x=999001;		// x= 999 001	6digit
		if(n>=x)
		{
			sum+=n-x+1;
			n=100999;
		}
		x=99001;	// x=99001	5digit
		if(n>=x)
		{
			sum+=n-x+1;
			n=10099;
		}
		x=9901;		// x=9901	4digit
		if(n>=x)
		{
			sum+=n-x+1;
			n=1099;
		}
		x=901;	// x=901	3digit
		if(n>=x)
		{
			sum+=n-x+1;
			n=109;
		}
		x=91;	// x=91		2digit
		if(n>=x)
		{
			sum+=n-x+1;
			n=19;
		}
		sum+=n;
		printf("Case #%d: %lld\n",a,sum);
	}
}
