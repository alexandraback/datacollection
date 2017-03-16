#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
	int val;
	int id;
	double need;
}v[300];
bool cmp(node a ,node b)
{
	return (a.val > b.val);
}
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A.out" ,"w", stdout);
	int cas, n, sum, i, sum1;
	scanf("%d", &cas);
	for (int t = 1; t <= cas; t++)
	{
		sum  = 0;
		scanf("%d", &n);
		for(i = 1; i <= n; i++)
		{
			scanf("%d", &v[i].val);
			v[i].id = i;
			sum += v[i].val;
			v[i].need = 0;
		}
		sort(v + 1, v + 1 + n, cmp);
		int k = n;
		sum1 = sum;
		for(i = 1; i <= n; i++)
		{
			if (v[i].val * k < sum  + sum1)
			{
				break;
			}
			k--;
			sum1 -= v[i].val;
			v[i].need = 0;
		}
		for(; i <= n; i++)
		{
			v[i].need = 100.0 * ((sum + sum1) / (1.0 * k) - v[i].val)/sum;
		}
		double ans[300];
		for(i = 1; i <= n; i++)
		{
			ans[v[i].id] = v[i].need;
		}
		printf("Case #%d:", t);
		for(i = 1; i <= n; i++)
		{
			printf(" %.6lf", ans[i]);
		}
		printf("\n");
	}
}