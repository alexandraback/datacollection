#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int solve(const vector<int> & motes, int a, int del)
{
	int ret = 0;
	int n = motes.size();
	for (int i = 0; i < n - del; ++i)
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
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		printf("Case #%d: ", t);
		int a, n;
		scanf("%d%d", &a, &n);
		vector<int> motes(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &motes[i]);
		sort(motes.begin(), motes.end());

		int ans = n;
		for (int i = 0; i <= n; ++i)
			ans = min(ans, solve(motes, a, i) + i);
		printf("%d\n", ans);
	}
	return 0;
}
