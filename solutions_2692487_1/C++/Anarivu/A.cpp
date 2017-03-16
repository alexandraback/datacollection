#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;

long long a[105];
int n;
int res;

void func(long long w)
{
	int pre = 0;
	for(int p = 0; p < n; p++)
	{
		int ans = pre + n - p;
		if(w > a[p])
			w += a[p], ans = pre + n - p - 1;
		else
		{
			if(w > 1)
			{
				while(w <= a[p])
					pre++, w += w-1;
				ans = min(ans, pre + n - p - 1);
				w += a[p];
			}
			else 
				break;
		}
		res = min(res, ans);
	}
}
 
int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T;
	scanf("%d", &T);
	int tc = 1;

	while(T > 0)
	{
		T--;
		printf("Case #%d: ", tc);
		tc++;

		int w;
		scanf("%d%d", &w, &n);
		for(int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		sort(a, a+n);

		res = n;
		func(w);
		printf("%d\n", res);
	}

	return 0;
}