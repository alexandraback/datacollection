#include <bits/stdc++.h>

using namespace std;

int bf[1010];

bool test(int n, int tot)
{
	if (n == 1)
		return true;
	
	for (int mask = 0; mask < (1 << tot); mask++)
	{
		if (__builtin_popcount(mask) != n) continue;

		vector<int> v;
		for (int i = 0; i < tot; i++)
		{
			if ((mask >> i)&1)
				v.push_back(i+1);
		}
		do
		{
			bool ok = true;
			for (int i = 0; i < n; i++)
			{
				int left = (n + (i-1))%n, right = (i+1)%n;
				int cur = v[i], l = v[left], r = v[right];
				if (l != bf[cur] and r != bf[cur])
					ok = false;
			}
			if (ok)
				return true;
			
		} while(next_permutation(v.begin(), v.end()));
	}
	return false;
}

int main()
{
	int T, cnt = 0;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", bf+i);
		int ans = -1;
		for (int i = n; i >= 1 and ans == -1; i--)
		{
			if (test(i, n))
				ans = i;
		}
		printf("Case #%d: %d\n", ++cnt, ans);
	}
	return 0;
}
