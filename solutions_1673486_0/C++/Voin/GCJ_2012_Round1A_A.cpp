#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int t, a, b, x, d[8][3];
double p[100000], ans, s[8];

int st(int k)
{
	int x = 1;
	for (int i = 0; i < k; i++)
		x *= 2;
	return x;
}

void pod(int k)
{
	for (int i = 0; i < st(k); i++)
	{
		int x = i;
		s[i] = 1;
		for (int j = 0; j < k; j++)
		{
			d[i][j] = x % 2;
			if (!(x % 2)) s[i] *= p[j];
			else
				s[i] *= 1 - p[j];
			x /= 2;
		}
	}
}

bool pr(int j, int k)
{
	for (int i = 0; i < a - k; i++)
	{
		if (d[j][i]) return false;
	}
	return true;
}
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	cout.precision(10);
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		for (int j = 0; j < a; j++)
		{
			cin >> p[j];
		}
		ans = b + 2;
		pod(a);
		for (int j = 0; j <= a; j++)
		{
			double ans1 = 0;
			for (int k = 0; k < st(a); k++)
			{
				if (pr(k, j))
				{
					ans1 += s[k] * (b - a + 2 * j + 1);
				}
				else
				{
					ans1 += s[k] * (2 * b + 2 * j + 2 - a);
				}
			}
			ans = min(ans, ans1);
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}