#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int v[510];
bool ha[510];
int n;
struct node
{
	int t;
	int v;
}nn[2000000];
bool cmp(node a, node b)
{
	return (a.v < b.v);
}
int cho, sum, all;
void dfs(int t)
{
	if (t == n + 1)
	{
		nn[all].t = cho;
		nn[all].v = sum;
		all++;
		return ;
	}
	dfs(t + 1);
	cho += (1 << (t - 1));
	sum += v[t];
	dfs(t + 1);
	cho -= (1 << (t - 1));
	sum -= v[t];
}
int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("A.out" ,"w", stdout);
	int cas, i, sum1;
	scanf("%d", &cas);
	for (int t = 1; t <= cas; t++)
	{
		sum  = 0;
		scanf("%d", &n);
		for(i = 1; i <= n; i++)
		{
			scanf("%d", &v[i]);
		}
		sort(v + 1, v + 1 + n);
		memset(ha, 0, sizeof(ha));
		printf("Case #%d:\n", t);
		cho = sum = all = 0;
		dfs(1);
		sort(nn, nn + all, cmp);
		for(i = 0; i < all - 1; i++)
		{
			if (nn[i].v == nn[i + 1].v)
			{
				if ((nn[i].t & nn[i + 1].t) == 0)
				{
					break;
				}
			}
		}
		if (i == all - 1)
		{
			printf("Impossible\n");
			continue;
		}
		int k = i;
		int p = -1;
		for(i = 0; i < n; i++)
		{
			if (nn[k].t & (1 << i))
			{
				if (p != -1)
					printf("%d ", p);
				p = v[i + 1];
			}
		}
		printf("%d\n", p);
		p = -1;
		for(i = 0; i < n; i++)
		{
			if (nn[k + 1].t & (1 << i))
			{
				if (p != -1)
					printf("%d ", p);
				p = v[i + 1];
			}
		}
		printf("%d\n", p);

	}
}