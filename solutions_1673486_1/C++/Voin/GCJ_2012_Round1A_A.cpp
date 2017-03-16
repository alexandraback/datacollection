#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int t, a, b;
double p[100000], d[100000], ans;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	cout.precision(10);
	for (int k = 0; k < t; k++)
	{
		cin >> a >> b;
		for (int j = 0; j < a; j++)
		{
			cin >> p[j];
		}

		ans = b + 2;
		d[0] = 1;
		for (int i = 1; i <= a; i++)
			d[i] = d[i - 1] * p[i - 1];
		for (int i = 0; i <= a; i++)
		{
			double ans1 = d[a - i] * (b - a + 2 * i + 1) + (1 - d[a - i]) * (2 * b - a + 2 * i + 2);
			ans = min(ans1, ans);
		}
		cout << "Case #" << k + 1 << ": " << ans << endl;
	}
	return 0;
}