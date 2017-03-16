#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
long long ss(long long *a, long long *b, long long *mi, int vn)
{
	long long ans = 0;
	for (int i = 0; i < vn; i++)
	{
		if (a[i] <= b[i]) break;
		ans += mi[min(i, vn - i)+1];
		a[i] = 0;
		a[i+1]++;
	}
	for (int i = 0; i <= vn; i++)
		ans += mi[min(i, vn - i)] * (b[i] - a[i]);
	return ans;
}
long long solve(long long now, long long next)
{
	long long ans = next - now, news = 1, news2 = 2;
	
	long long mi[1001];
	mi[0] = 1;
	for (int i = 1; i <= 15; i++)
		mi[i] = mi[i-1] * 10;
	if (ans == 0) return 0;
	long long a[20], b[20];
	int vn;
	for (int i = 0; now > 0 || next > 0; i++)
	{
		a[i] = now % 10;
		b[i] = next % 10;
		now /= 10;
		next /= 10;
		vn = i;
	}

	if (b[0] != 0)
		news2 = 2LL + ss(a, b, mi, vn);
	else
		news2 = 10000000;
	
	for (int i = 0; i <= vn / 2; i++)
	{
		int tmp = a[i];
		a[i] = a[vn - i];
		a[vn - i] = tmp;
	}
	news = 1ll + ss(a, b, mi, vn);
	news = news < news2 ? news : news2;
	return news < ans ? news : ans;
}
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int tot;
	cin >> tot;
	for (int t = 1; t<= tot; t++)
	{
		long long n, ans = 0;
		cin >> n;
		long long now = 1, next = 10;
		while (next <= n)
		{
			ans += solve(now, next - 1);
			now = next - 1;
			if (now < n)
			{
				ans++;
				now = next;
			}
			next *= 10;
		}
		if (now != n)
		{
			if (n % 10 == 0)
				ans += solve(now, n-1) + 1;
			else
				ans += solve(now, n);
		}
		cout << "Case #" << t << ": " << ans + 1 << endl;
	}
	return 0;
}
