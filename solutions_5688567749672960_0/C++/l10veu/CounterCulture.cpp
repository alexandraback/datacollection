#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int MAX = 1000000;

long long ans[MAX + 1];

long long numericReverse(long long a)
{
	long long ret = 0;
	while (a)
	{
		ret = ret * 10 + a % 10;
		a /= 10;
	}
	
	return ret;
}

int main()
{
	std::fill(ans, ans+MAX+1, MAX+1);
	
	ans[1] = 1;
	for (int i=1; i<=MAX; ++i)
	{
		long long next = i+1;
		if (ans[i] + 1 < ans[next])
			ans[next] = ans[i] + 1;

		next = numericReverse(i);
		if (ans[i] + 1 < ans[next])
			ans[next] = ans[i] + 1;
	}
	
	int t;
	scanf("%d", &t);
	for (int tc=1; tc<=t; ++tc)
	{
		long long N;
		scanf("%lld", &N);
		printf("Case #%d: %lld\n", tc, ans[N]);
	}
	
	return 0;
}