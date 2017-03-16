#include <iostream>
#include <cstdio>
using namespace std;
long long pierw[1000000];
int main()
{
	long long pie=1;
	for(int i = 0 ; pie < 10000000000000 ; i++)
	{
		pierw[i]=pie;
		pie*=2;
	}
	int h;
	scanf("%d", &h);
	for(int g = 1 ; g <= h ; g++)
	{
		long long n, k, c;
		char lol;
		scanf("%lld %c %lld", &n, &lol, &k);
		long long a = n;
		long long b = k;
		while (b!=0)
		{
			c = a % b;
			a = b;
			b = c;
		}
		n/=a;
		k/=a;
		int licz=0;
		for(int i = 0 ; pierw[i]<=k ; i++)
		{
			licz=i;
		}
		if(pierw[licz] != k)
		{
			printf("Case #%d: impossible\n", g);
			continue;
		}
		long long beka = 1;
		bool tak=0;
		while(beka < n)
		{
			//cout<<beka<<" -- "<<n << " -- ";
			beka*=2;
			licz--;
			tak=1;
		}
		if(tak==1)
			printf("Case #%d: %d\n", g, licz+1);
		else
			printf("Case #%d: %d\n", g, licz);
		//cout<<pierw[licz]<<endl;
		//printf("%lld / %lld\n",n,k);
		
	}
}
