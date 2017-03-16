#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define FILENAME "C-small-attempt5"
__int64 ti, tn, n, m, i, j, k;
__int64 ans, s;
struct node {
	__int64 num;
	__int64 kind;
}a[100], b[100];
__int64 minn(__int64 x, __int64 y)
{
	return x < y ? x: y;
}
__int64 maxn(__int64 x, __int64 y)
{
	return x > y ? x: y;
}
__int64 find(int f, int t, int kind)
{
	__int64 i;
	__int64 ret = 0;
	for (i = f; i < t; ++i)
		if (b[i].kind == kind)
			ret += b[i].num;
	return ret;
}
int main()
{
	
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti) {
		cout << "Case #" << ti << ":";
		cin >> n >> m;
		for (i = 0; i < n; ++i)
			cin >> a[i].num >> a[i].kind;
		for (i = 0; i < m; ++i)
			cin >> b[i].num >> b[i].kind;
		for (i = 0; i < n; ++i) {
			while (i + 1 < n && a[i + 1].kind == a[i].kind) {
				a[i].num += a[i + 1].num;
				for (j = i + 1; j < n - 1; ++j)
					a[j] = a[j + 1];
				--n;
			}
		}
		for (i = 0; i < m; ++i) {
			while (i + 1 < m && b[i + 1].kind == b[i].kind) {
				b[i].num += b[i + 1].num;
				for (j = i + 1; j < m - 1; ++j)
					b[j] = b[j + 1];
				--m;
			}
		}
		for (ans = i = 0; i < n; ++i) {
			ans = maxn(ans, minn(a[i].num, find(0, m, a[i].kind)));
		}
		if (n >= 2) {
			for (i = 0; i < n; ++i)
				for (j = i + 1; j < n; ++j) {
					if (a[i].kind == a[j].kind)
						ans = maxn(ans, minn(a[i].num + a[j].num, find(0, m, a[i].kind)));
					else
						for (k = 0; k <= m; ++k) {
							ans = maxn(ans, minn(a[i].num, find(0, k, a[i].kind)) + minn(a[j].num, find(k, m, a[j].kind)));
						}
				}
		}
		if (n >= 3) {
			for (i = 0; i <= m; ++i)
				for (j = i; j <= m; ++j)
					ans = maxn(ans, minn(a[0].num, find(0, i, a[0].kind)) + minn(a[1].num, find(i, j, a[1].kind)) + minn(a[2].num, find(j, m, a[2].kind)));
		}
		cout << " " << ans << endl;
	}
	return 0;
}