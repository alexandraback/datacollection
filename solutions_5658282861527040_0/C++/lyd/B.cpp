#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

long long a,b,k;

int main()
{
	int T;
	int ca = 1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&a,&b,&k);
		long long ans = 0;
		for(long long i=0;i<a;i++)
		{
			for(long long j=0;j<b;j++)
			{
				if( (i&j) < k )
					ans++;
			}
		}
		printf("Case #%d: %lld\n",ca++,ans);
	}
	return 0;
}

