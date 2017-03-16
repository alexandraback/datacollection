#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;

long long now;
long long n;
long long f[11];
long long factor[11];

bool check()
{
	bool o = 1;
	for (int base = 2;o && base <= 10;++ base)
	{
		bool w = 0;
		for (long long x = 2;x * x <= f[base];++ x)
			if (f[base] % x == 0)
			{
				w = 1;
				factor[base] = x;
				break;
			}
		o &= w;
	}
	return o;
}

int main()
{
//	freopen("out","w",stdout);
	{
		long long x = 1;
		for (int i = 1;i <= 15;++ i)
			x *= 2;
		now = x;
	}
	++ now;
	printf("Case #1:\n");
	for (int i = 1;i <= 50;++ i)
	{
		do
		{
			now += 2;
	//		cerr << "I'm running " << now << endl;
			for (int base = 2;base <= 10;++ base)
			{
				long long t = now;
				long long x = 1;
				f[base] = 0;
				while (t)
				{
					if (t & 1)
						f[base] += x;
					x *= base;
					t >>= 1;
				}
			}
		}while (!check() );
		printf("%I64d", f[10]);
//		cerr << "get " << f[10] << endl;
		for (int base = 2;base <= 10;++ base)
			printf(" %I64d", factor[base]);
		puts("");
	}
	return 0;
}
