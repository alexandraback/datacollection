#include <iostream>

using namespace std;
typedef long long int ll;

int t;
ll k;
ll c;
ll s;
ll d;
ll e;

int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> k >> c >> s;
		if ((k + c - 1) / c > s)
		{
			cout << "Case #" << i << ": IMPOSSIBLE" << endl;
			continue;
		}
		cout << "Case #" << i << ":";
		for (int l = 0; l < ((k + c - 1) / c); l++)
		{
			d = 1;
			e = 1;
			for (int j = 1; (j <= c) && (j <= k - l * c); j++)
			{
				d += e * (j - 1 + l * c);
				e *= k;
			}
			cout << ' ' << d;
		}
		cout << endl;
	}
	return 0;
}
