#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int n;
string s;

int solve()
{
	cin >> n >> s;
	n++;
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int x = (int)(s[i] - '0');
		if (x == 0) continue;
		if (sum < i)
		{
			ans += i - sum;
			sum = i;
		}
		sum += x;
	}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
		printf("Case #%d: %d\n", i, solve());

	return 0;
}
