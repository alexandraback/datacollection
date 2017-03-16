#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct node
{
	int idx, v;
};

bool myCompare(node n1, node n2)
{
	return (n1.v > n2.v);
}

struct t_node
{
	int max, min;
};

t_node* segt;
int n;

void insert(int j)
{
	int l = 0, r = n+1, x = 1, k = (l + r) / 2;
	while (l != r)
	{
		if (j > segt[x].max)
			segt[x].max = j;
		if ((j < segt[x].min) || (segt[x].min == 0))
			segt[x].min = j;
		if (j > k)
		{
			l = k + 1;
			x = x * 2 + 1;
		}
		else
		{
			r = k;
			x = x * 2;
		}
		k = (l + r) / 2;
	}
	segt[x].max = j;
	segt[x].min = j;
}

int get_max(int x, int l, int r, int i, int j)
{
	int k = (l + r) / 2;
	int temp1, temp2;
	
	if ((l == i) && (r == j))
		return segt[x].max;
	if (i > k)
		return get_max(x * 2 + 1, k + 1, r, i, j);
	if (j <= k)
		return get_max(x * 2, l, k, i, j);
	temp1 = get_max(x * 2, l, k, i, k);
	temp2 = get_max(x * 2 + 1, k + 1, r, k + 1, j);
	if (temp1 < temp2)
		return temp2;
	return temp1;
}

int get_min(int x, int l, int r, int i, int j)
{
	int k = (l + r) / 2;
	int temp1, temp2;
	
	if ((l == i) && (r == j))
		return segt[x].min;
	if (i > k)
		return get_min(x * 2 + 1, k + 1, r, i, j);
	if (j <= k)
		return get_min(x * 2, l, k, i, j);
	temp1 = get_min(x * 2, l, k, i, k);
	temp2 = get_min(x * 2 + 1, k + 1, r, k + 1, j);
	if (temp1 == 0)
		return temp2;
	return temp1;
}

node sn[10005];
int v[10005];
int be[10005];
int af[10005];

int main()
{
	int t, e, r, i, j, tt, a, b, c, d;
	long long res;
	node temp;

	cin >> t;
	for (tt = 1; tt <= t; ++tt)
	{
		res = 0;
		cin >> e >> r >> n;
		segt = new t_node[n  *4];
		memset(be, 0, sizeof(be));
		memset(af, 0, sizeof(af));
		
		for (i = 1; i <= n; ++i)
		{
			cin >> v[i];
			temp.v = v[i];
			temp.idx = i;
			sn[i-1] = temp;
		}
		
		insert(n + 1);
		af[0] = e;
		
		sort(sn, sn + n, myCompare);
		for (i = 0; i < n; ++i)
		{
			j = sn[i].idx;
			a = get_max(1, 0, n+1, 1, j);
			b = get_min(1, 0, n+1, j, n+1);
			c = min(e, r * (j - a) + af[a]);
			d = max(0, be[b] - r * (b - j));
			res += (c - d) * sn[i].v;
			be[j] = c;
			af[j] = d;
			insert(j);
		}
		
		cout << "Case #" << tt << ": " << res << endl;
	}

	return 0;
}
