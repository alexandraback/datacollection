#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(const vector<long long> & motes, long long a, long long del)
{
	long long ret = 0;
	long long n = motes.size();
	for (long long i = 0; i < n - del; ++i)
		if (a > motes[i])
			a += motes[i];
		else
		{
			if (a == 1)
				return n;
			a += a - 1;
			++ret;
			--i;
		}
	return ret;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long T;
	scanf("%lld", &T);
	for (long long t = 1; t <= T; ++t)
	{
		printf("Case #%lld: ", t);
		long long a, n;
		scanf("%lld%lld", &a, &n);
		vector<long long> motes(n);
		for (long long i = 0; i < n; ++i)
			scanf("%lld", &motes[i]);
		sort(motes.begin(), motes.end());

		long long ans = n;
		for (long long i = 0; i <= n; ++i)
			ans = min(ans, solve(motes, a, i) + i);
		printf("%lld\n", ans);
	}
	return 0;
}
