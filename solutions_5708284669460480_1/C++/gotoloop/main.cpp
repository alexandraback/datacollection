#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		int k, l, s;
		cin >> k >> l >> s;
		string s1, s2;
		cin >> s1;
		cin >> s2;
		int minw = l;
		for (int i = 1; i < l; i++)
		{
			bool ok = true;
			for (int j = 0; j < l - i; j++)
			{
				if (s2[i + j] != s2[j])
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				minw = i;
				break;
			}
		}
		int ww = (s - l) / minw + 1;
		double w = 1.0;
		for (int i = 0; i < l; i++)
		{
			int n = 0;
			for (int j = 0; j < k; j++)
			{
				if (s2[i] == s1[j])
				{
					n++;
				}
			}
			w *= (double)n / (double)k;
			if (n == 0)
			{
				ww = 0;
				break;
			}
		}
		double ans = (double)ww - w * (double)(s - l + 1);
		printf("Case #%d: %.8lf\n", q + 1, ans);
	}
}
