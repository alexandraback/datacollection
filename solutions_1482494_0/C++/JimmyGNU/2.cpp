#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int ans, n, a[1010], b[1010], p[1010];
void update (int r)
{
	if (ans < 0 || ans > r)
	{
		ans = r;
	}
	return;
}
void test()
{
	int s = 0, r = 0;
	priority_queue<int, vector<int>, greater<int> >q;
	for (int i = 0; i < n; ++i)
	{
		int k = p[i];
		if (s >= b[k] && s >= a[k])
		{
			s += 2;
			++r;
		}
		else if (s >= a[k])
		{
			s += 1;
			++r;
			q.push (b[k]);
		}
		else
		{
			return;
		}
		while (!q.empty() && s >= q.top())
		{
			++s;
			++r;
			q.pop();
		}
	}
	update (r);
	return;
}
int main()
{
	int T;
	scanf ("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		scanf ("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf ("%d%d", &a[i], &b[i]);
			p[i] = i;
		}
		ans = -1;
		do
		{
			test();
		}
		while (next_permutation (p, p + n));
		printf ("Case #%d: ", nCase);
		if (ans < 0)
		{
			printf ("Too Bad\n");
		}
		else
		{
			printf ("%d\n", ans);
		}
	}
	return 0;
}
