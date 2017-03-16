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
		long long ans = 0;
		long long a, b, k;
		cin >> a >> b >> k;
		ans = a * min(k, b) + b * min(k, a) - min(k, a) * min(k, b);
		for (int i = k; i < a; i++)
			for (int j = k; j < b; j++)
				if ((i & j) < k) ans++;
		cout << ans << "\n";
	}
}