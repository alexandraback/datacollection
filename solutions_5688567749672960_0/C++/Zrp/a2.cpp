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
long long f[10000001];
long long solve(long long now)
{
	long long snow = now;
	int vn = 0, a[1001] = {0};
	for (int i = 0; now > 0; i++)
	{
		a[i] = now % 10;
		now /= 10;
		vn = i;
	}
	long long ret = 0;
	for (int i = 0; i <= vn; i++)
	{
		ret *= 10;
		ret += a[i];
		
	}
	return ret;
}
int in[3000001] ={0};
int q[3000001] = {0};
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a2.out", "w", stdout);
	int tot;
	cin >> tot;
	for (int i = 1; i <= 2000000; i++)
	{
		in[i] = 0;
		f[i] = 10000000;
	}
	f[1] = 0;
	int close = 0, open = 1;
	q[close] = 1;
	in[1] = 1;
	while (close < open)
	{
		int k = q[close++];
		if (k + 1 <= 2000000)
			if (f[k+1] > f[k] + 1)
			{
				f[k+1] = f[k] + 1;
				if (!in[k+1])
				{
					in[k+1] = 1;
					q[open++] = k+1;
				}
			}
		int p = solve(k);
		if (p <= 2000000)
			if (f[p] > f[k] + 1)
			{
				f[p] = f[k] + 1;
				if (!in[p])
				{
					in[p] = 1;
					q[open++] = p;
				}
			}
	}
	for (int t = 1; t<= tot; t++)
	{
		long long n, ans = 0;
		cin >> n;
		cout << "Case #" << t << ": " << f[n] + 1 << endl;
	}
	return 0;
}
