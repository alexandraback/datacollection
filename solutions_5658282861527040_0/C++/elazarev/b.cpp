#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
using namespace std;
int t;
int a, b, k;

void solve()
{
	int ans = 0;
	cin >> a >> b >> k;
	for (int i = 0; i < a; ++i)
		for (int j = 0; j < b; ++j)
			if ((i & j) < k)
				ans++;
	cout << ans << endl;
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	return 0;
}