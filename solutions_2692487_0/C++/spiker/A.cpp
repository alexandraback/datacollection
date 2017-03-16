#include <string>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

int main(void)
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for (int q = 1; q <= T; q++)
	{
		long long A, a[105];
		int n;
		scanf("%lld%d",&A, &n);
		for (int i = 0; i < n; i++)
			scanf("%lld",&a[i]);
		sort(a,a+n);
		int cnt = 0;
		int ans = -1;
		long long curn = A;
		for (int i = 0; i < n; i++)
		{
			if (curn > a[i])
			{
				curn += a[i];
			} else
			{
				int del = (n-i);
				if (curn == 1)
				{
					ans = cnt+del;
					cnt += del;
					break;
				}
				int add = 0;
				while (curn <= a[i])
				{
					curn += (curn -1);
					add++;
				}
				if (ans == -1)
					ans = cnt+del; else
					ans = min(ans, cnt+del);
				cnt += add;
				curn += a[i];
			}
		}
		if (ans == -1)
			ans = cnt; else
			ans = min(ans,cnt);
		if (ans > n)
			ans = n;
		if (ans == -1)
			ans = 0;
		printf("Case #%d: %d\n", q, ans);
	}
	return 0;
}