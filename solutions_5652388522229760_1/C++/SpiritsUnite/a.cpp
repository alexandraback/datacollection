#include <bits/stdc++.h>

using namespace std;

int T, n;
set<int> seen;

int main()
{
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		cout << "Case #" << C << ": ";
		cin >> n;
		int m = n;
		if (n == 0)
		{
			cout << "INSOMNIA\n";
			continue;
		}
		seen.clear();
		while (true)
		{
			int x = n;
			while (x) {
				seen.insert(x % 10);
				x /= 10;
			}
			if (seen.size() == 10)
			{
				cout << n << '\n';
				break;
			}
			n += m;
		}
	}
	return 0;
}

