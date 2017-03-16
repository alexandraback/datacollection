#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
int main()
{
	int t,k;
	long long a,b,d;
	char c;
	scanf("%d\n",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%lld/%lld",&a,&b);
		printf("Case #%d: ",k);
		d=gcd(a,b);
		a=a/d;
		b=b/d;
		int f=0,x=0,y=0,ans=0;
		while(b>1)
		{
			if(b%2)
			f=1;
			b=b/2;
			x++;
		}
		if(f==1)
		printf("impossible\n");
		else
		{
			while(a>1)
			{

				a=a/2;
				y++;
			}
			printf("%d\n",x-y);
		}
	}
}
