#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		long long m,n,k;
		scanf("%lld %lld %lld",&n,&m,&k);
		if(k<=4) printf("%lld\n",k );
		else if(m<=2 || n<=2)
		{
			printf("%lld\n",k );
		}
		else if(k<(m*n-4))
		{
			long long min=m*n;
			for (long long i = 1; i < m; ++i)
			{
				long long initial =3*i +2;
				long long remaining = k-initial;
				if(remaining<=0)
				{
					if(2*i + 2 < min) min = 2*i +2;
					continue;
				}
				else
				{
					long long req = 2*i + 2 + 2*remaining/(i+3) + remaining%(i+3);
					if(remaining/(i+3) <= n-2)
					{
						if(req<min) min = req;
					}
				}
			}
			for (long long i = 1; i < n; ++i)
			{
				long long initial =3*i +2;
				long long remaining = k-initial;
				if(remaining<=0)
				{
					if(2*i + 2 < min) min = 2*i +2;
					continue;
				}
				else
				{
					long long req = 2*i + 2 + 2*remaining/(i+3) + remaining%(i+3);
					if(remaining/(i+3) <= m-2)
					{
						if(req<min) min = req;
					}
				}
			}
			printf("%lld\n",min );
		}
		else
		{
			printf("%lld\n",2*(m+n-4) + k+4-m*n );
		}
	}

}