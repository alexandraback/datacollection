#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct Node
{
	long long v;
	int idx;
} a[10010];
int T, n;
long long e, r, sum[110], x[110], v[110];
bool flag[110];
/*
bool cmp(Node p, Node q)
{
	return p.v > q.v || p.v == q.v && p.idx < q.idx;
}
*/

int find(int p, int q)
{
	int ret = p;
	while (!flag[ret]) ret++;
	for (int i = ret + 1; i <= q; i++)
		if (flag[i] && v[i] > v[ret]) ret = i;
	return ret;
}

int main()
{
	int ca = 0;
	scanf("%d", &T);
	while (T--)
	{
		ca++;
		scanf("%lld%lld%d", &e, &r, &n);
		if (r > e) r = e;
		for (int i = 1; i <= n; i++)
			scanf("%lld", &v[i]);
		memset(sum, 0, sizeof(sum));
		memset(x, 0, sizeof(x));
		for (int i = 1; i <= n; i++)
		{
			memset(flag, true, sizeof(flag));
			while (sum[i] < i * r)
			{
				int k = find(1, i);
				long long z = e - x[k];
				for (int j = k; j <= i; j++)
					z = min(z, e + (j - 1) * r - sum[j]);
				z = min(z, i * r - sum[i]);
				x[k] += z;
				for (int j = k; j <= n; j++)
					sum[j] += z;
//				cout << k << " " << z << " " << sum[1] << " " << sum[2] << endl;
				flag[k] = false;
			}
		}
/*		for (int ii = 1; ii <= n; ii++)
			cout << x[ii] << " ";
		cout << endl;
*/		memset(flag, true, sizeof(flag));
		while (sum[n] < (n - 1) * r + e)
		{
			int k = find(1, n);
			long long z = e - x[k];
			for (int j = k; j <= n; j++)
				z = min(z, e + (j - 1) * r - sum[j]);
			x[k] += z;
			for (int j = k; j <= n; j++)
				sum[j] += z;
			flag[k] = false;
		}
		long long sum = 0;
		for (int i = 1; i <= n; i++)
			sum += x[i] * v[i];
		printf("Case #%d: %d\n", ca, sum);
/*		for (int ii = 1; ii <= n; ii++)
			cout << x[ii] << " ";
		cout << endl;
*/	}
	return 0;
}
