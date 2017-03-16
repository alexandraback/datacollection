#include <cstdio>
#include <algorithm>
#include <queue>
using std::priority_queue;

const int N = 1000 + 10;

int n;
priority_queue<int> Q, tmp;

int calc(int maxp)
{
	tmp = Q;
	int res = 0;
	while(tmp.top() > maxp)
	{
		int x = tmp.top(); tmp.pop();
		while(x > maxp)
		{
			tmp.push(maxp);
			x -= maxp;
			res++;
		}
	}
	return res + maxp;
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		while(!Q.empty()) Q.pop();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			Q.push(x);
		}
		int res = 0x3f3f3f3f;
		for(int maxp = 1; maxp <= Q.top(); maxp++)
			res = std::min(res, calc(maxp));
		printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}
