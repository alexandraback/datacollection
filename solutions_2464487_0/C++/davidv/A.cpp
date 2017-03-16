#include <cstdio>
#include <algorithm>

using namespace std;

long long paintNeeded(long long n, long long r)
{
	return n*(2*r+1) + 2*n*(n-1);
}

long long maxN(long long r, long long paint)
{
	long long high = min(paint/(2*r+1)+1, 1000000001LL), low = 1;
	
	while (high-low > 1)
	{
		long long mid = (high+low)/2;
		if (paintNeeded(mid,r) > paint)
			high = mid;
		else
			low = mid;
	}
	
	return low;
}

void doCase()
{
	long long r, t;
	
	scanf("%lld %lld", &r, &t);
	
	printf("%lld\n", maxN(r,t));
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i=1; i<=T; i++)
	{
		printf("Case #%d: ", i);
		doCase();
	}
	return 0;
}
