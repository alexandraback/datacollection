#include <bits/stdc++.h>

using namespace std;

int p[1123];
int r[1123];
int clen[1123];
int llen[1123];
int l2en[1123];
int bff[1123];

void uf_init()
{
	for (int i = 0; i < 1123; i++)
	{
		p[i] = i;
		r[i] = 0;
		clen[i] = 0;
		llen[i] = 0;
		l2en[i] = 0;
	}
}

int uf_find(int x)
{
	if (p[x] == x) return x;
	else return p[x] = uf_find(p[x]);
}

void uf_join(int x, int y)
{
	x = uf_find(x);
	y = uf_find(y);
	if (x == y) return;
	if (r[x] < r[y])
	{
		p[x] = y;
	}
	else
	{
		p[y] = x;
		if (r[x] == r[y]) r[x]++;
	}
}

int T;

int main()
{
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		int n;
		cin >> n;
		uf_init();
		for (int i = 0; i < n; i++)
		{
			cin >> bff[i];
			bff[i]--;
		}
		for (int i = 0; i < n; i++)
		{
			int cur = i;
			while (uf_find(cur) != uf_find(bff[cur]))
			{
				uf_join(cur, bff[cur]);
				cur = bff[cur];
			}
		}
		int ans = 0;
		int ans2 = 0;
		for (int i = 0; i < n; i++)
		{
			int cur = i;
			int p = uf_find(i);
			map<int, int> seen;
			seen[cur] = 1;
			while (!seen.count(bff[cur]))
			{
				seen[bff[cur]] = seen[cur] + 1;
				cur = bff[cur];
			}
			clen[p] = seen[cur] - seen[bff[cur]] + 1;
			ans = max(ans, clen[p]);
			if (clen[p] == 2 && bff[bff[i]] != i)
			{
				if (cur < bff[cur]) llen[p] = max(llen[p], seen[cur]);
				else l2en[p] = max(l2en[p], seen[cur]);
			}
		}
		set<int> seen;
		for (int i = 0; i < n; i++)
		{
			int p = uf_find(i);
			if (seen.count(p)) continue;
			//cout << p << ' ' << llen[p] << ' ' << l2en[p] << '\n';
			ans2 += llen[p] + l2en[p];
			if (llen[p] && l2en[p]) ans2 -= 2;
			if (clen[p] == 2 && !llen[p] && !l2en[p]) ans2 += 2;
			seen.insert(p);
		}
		//cout << ans << ' ' << ans2 << '\n';
		cout << "Case #" << C << ": " << max(ans, ans2) << '\n';
	}
	return 0;
}
