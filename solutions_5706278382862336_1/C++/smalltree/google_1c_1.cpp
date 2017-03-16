#include <iostream>
#include <cstdio>
using namespace std;
long long gcd(long long x,long long y)
{
	if (y==0)
		return x;
		else return gcd(y,x%y);
}
int main()
{
	int t;
	long long a,b,c;
	cin>>t;
	for (int i=0;i<t;i++)
	{
		scanf("%lld/%lld",&a,&b);
		c=gcd(b,a);
		a=a/c;
		b=b/c;
		c=0;
		while (b%2==0)
		{
			c++;
			b=b/2;
		}
		long long d=0,j=1;
		while (a>(j*2))
		{
			d++;
			j=j*2;
		}
		if (b>1)
			cout<<"Case #"<<i+1<<": impossible"<<endl;
			else cout<<"Case #"<<i+1<<": "<<c-d<<endl;
	}
}
