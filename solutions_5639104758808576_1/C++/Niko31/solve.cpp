#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": ";
		int n;
		string s;
		cin >> n >> s;
		int ans = 0;
		int cur = 0;
		for (int i = 0; i <= n; i++) {
			ans = max(ans, i - cur);
			cur += s[i] - '0';

		}
		cout << ans << endl;
	}
}