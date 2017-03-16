#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": ";
		int n, m, k;
		cin >> n >> m >> k;
		int res = k;
		for (int i = 1; i < n - 1; i++)
			for (int j = 1; j < m - 1; j++)
				res = min(res, 2 * i + 2 * j + max(0, k - 2 * i - 2 * j - i * j));
		cout << res << "\n";
	}
}