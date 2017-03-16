#include <cstdio>
#include <queue>
using namespace std;

struct Thing
{
	long long type, num;
	Thing(long long a, long long b)
	{ type = a, num = b; }
};

int n, m;
long long ans;
long long min(long long a, long long b)
{ return a < b ? a : b; }

void dfs(queue<Thing> a, queue<Thing> b, long long now)
{
	if(a.empty() || b.empty())
	{
		if(now > ans) ans = now;
	}
	else
	{
		while(a.front().type == b.front().type)
		{
			long long inc = min(a.front().num, b.front().num);
			now += inc;
			a.front().num -= inc;
			b.front().num -= inc;
			if(now > ans) ans = now;
			while(a.front().num < 1) 
			{
				a.pop();
				if(a.empty()) return;
			}
			while(b.front().num < 1) 
			{
				b.pop();
				if(b.empty()) return;
			}
		}
		if(now > ans) ans = now;

		queue<Thing> c;
		//if(ch) dfs(a, b, now);
		c = a;
		c.pop();
		dfs(c, b, now);
		c = b;
		c.pop();
		dfs(a, c, now);
	}
}

void work()
{
	queue <Thing> a, b;
	ans = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i ++)
	{
		long long y, x;
		scanf("%lld %lld", &y, &x);
		a.push(Thing(x, y));
	}
	for(int i = 0; i < m; i ++)
	{
		long long y, x;
		scanf("%lld %lld", &y, &x);
		b.push(Thing(x, y));
	}
	dfs(a, b, 0);
	printf("%lld\n", ans);
}

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i ++)
	{
		printf("Case #%d: ", i);
		work();
	}
	return 0;
}
