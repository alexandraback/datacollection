#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 33000005
#define INF 1000000000
#define MAXR ((1 << 23) - 1)

int n;
int a[MAXN];
int b[MAXN];
int l;
int days[MAXN];
int w[MAXN];
int e[MAXN];
int ww[MAXN];
int ee[MAXN];
int s[MAXN];
int pos[MAXN];
int len;
int all[MAXN];

inline bool cmp(int i1, int i2)
{
	return days[i1] < days[i2];
}

inline int get_min(int v, int l, int r, int ql, int qr)
{
	if (qr < l || r < ql) return INF;
	if (ql <= l && r <= qr)
		return a[v];

	a[v + v] = max(a[v + v], b[v]);
	a[v + v + 1] = max(a[v + v + 1], b[v]);
	b[v + v] = max(b[v + v], b[v]);
	b[v + v + 1] = max(b[v + v + 1], b[v]);
	b[v] = 0;

	int m = (l + r) >> 1;
	int t1 = get_min(v + v, l, m, ql, qr);
	int t2 = get_min(v + v + 1, m + 1, r, ql, qr);

	a[v] = min(a[v + v], a[v + v + 1]);

   return min(t1, t2);
}

inline void update(int v, int l, int r, int ql, int qr, int val)
{
	if (qr < l || r < ql) return;
	if (ql <= l && r <= qr)
	{
		a[v] = max(a[v], val);
		b[v] = max(b[v], val);
//		cout << " updating " << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << val << ' ' << a[v] << " v = " << v << endl;
		return;
	}

	a[v + v] = max(a[v + v], b[v]);
	a[v + v + 1] = max(a[v + v + 1], b[v]);
	b[v + v] = max(b[v + v], b[v]);
	b[v + v + 1] = max(b[v + v + 1], b[v]);
	b[v] = 0;

	int m = (l + r) >> 1;
	update(v + v, l, m, ql, qr, val);
	update(v + v + 1, m + 1, r, ql, qr, val);
   a[v] = min(a[v + v], a[v + v + 1]);
//	cout << " in the road " << l << ' ' << r << ' ' << a[v]  << " bet " << a[v + v] << ' ' << a[v + v + 1] << "  v + v =" << v + v<< endl;
}

inline int solve()
{
	scanf("%d", &n);

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	l = 0;
	len = 0;

	for (int i = 0; i < n; ++i)
	{
		int t1, t2, t3, t4, t5, t6, t7, t8;
		scanf("%d%d%d%d%d%d%d%d", &t1, &t2, &t3, &t4, &t5, &t6, &t7, &t8);
		for (int j = 0; j < t2; ++j)
		{
			days[l] = t1;
			w[l] = t3;
			e[l] = t4 - 1;
         s[l] = t5;
			pos[l] = l;

			all[len++] = w[l] - 1;
			all[len++] = w[l];
			all[len++] = w[l] + 1;
			all[len++] = e[l] - 1;
			all[len++] = e[l];
			all[len++] = e[l] + 1;

			++l;
			t1 += t6;
			t3 += t7;
			t4 += t7;
			t5 += t8;
		}
	}

	sort(all, all + len);
	len = unique(all, all + len) - all;

	sort(pos, pos + l, cmp);

	for (int i = 0; i < l; ++i)
	{
		ww[i] = lower_bound(all, all + len, w[i]) - all;
		ee[i] = lower_bound(all, all + len, e[i]) - all;
	}

	int ans = 0, last_i = 0;
	for (int i = 0; i < l; ++i)
	{
		while(days[pos[last_i]] < days[pos[i]])
		{
			update(1, 0, MAXR, ww[pos[last_i]], ee[pos[last_i]], s[pos[last_i]]);
			++last_i;
		}
		int ind = pos[i];
//		cout << ww[ind] << ' ' << ee[ind] << ' ' << s[ind] << ' ' << get_min(1, 0, MAXR, ww[ind], ee[ind]) << endl;
		if (get_min(1, 0, MAXR, ww[ind], ee[ind]) < s[ind])
		{
			++ans;
		}
	}
	return ans;
}

int main()
{
	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
		printf("Case #%d: %d\n", t + 1, solve());
	return 0;
}
