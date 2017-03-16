#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int T;
	cin >> T;
	for (int cn = 1; cn <= T; ++cn)
	{
		int n;
		string s;
		cin >> n >> s;

		int ret = 0;
		int sum = 0;
		for (int i = 0; i <= n; ++i)
		{
			int v = s[i] - '0';
			if (v > 0)
			{
				if (ret < i - sum) ret = i - sum;
			}			
			sum += v;
		}
		printf("Case #%d: %d\n", cn, ret);
	}
	return 0;
}