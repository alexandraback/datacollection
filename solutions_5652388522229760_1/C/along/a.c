#include <stdio.h>
#include <iostream>
using namespace std;

int f[10];
int nleft;

void mark(long long n)
{
	while(n > 0)
	{
		long long t = n%10; n/=10;
		if (f[t] == 0) nleft--;
		f[t] = 1;
	}
}

int main()
{
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		long long n, p;
		cin >> n;
		p = 1;
		if (n == 0)
		{
			printf("Case #%d: INSOMNIA\n", cc);
			continue;
		}

		for(int i=0; i<10; i++) f[i] = 0;
		nleft=10;

		while(n%10 == 0)
		{
			n/=10; p*=10; f[0] = 1; nleft=9;
		}

		long long r = n;
		for(int i=1; ;i++)
		{
			mark(r);
			if (nleft == 0)
				break;
			r += n;	
		}
		r*=p;
		printf("Case #%d: %lld\n", cc, r);
	}
}
