#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int a, n;
int motes[100];

int check(int i, int sz)
{
	if (i == n)
		return 0;

	int ngrow = 0, sznew = sz;

	while (sznew <= motes[i])
	{
		++ngrow;
		sznew += sznew - 1;
	}

	int work = ngrow + check(i + 1, sznew + motes[i]);

	return min(n - i, work);
}

int solve()
{
	if (a == 1)
		return n;

	return check(0, a);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;

	cin >> t;

	for (int i=0; i<t; ++i)
	{
		cin >> a >> n;

		for (int j=0; j<n; ++j)
		{
			cin >> motes[j];
		}

		sort(motes, motes + n);

		int res = solve();

		cout << "Case #" << i+1 << ": " << res << endl;
	}

	return 0;
}