#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

vector<long long> coin;
long long c, d, v;

int main()
{
	int cases;
	cin >> cases;
	for (int tcase = 1; tcase <= cases; ++tcase)
	{
		cin >> c >> d >> v;
		coin.resize(d);
		for (int i = 0; i < d; ++i)
			cin >> coin[i];
			
		sort(coin.begin(), coin.end());
		long long now = 0;
		long long ans = 0;
		long long last = 0;
		coin.push_back(v + 1);
		for (int i = 0; i < d + 1; ++i)
		{
			while (now < v && now + 1 < coin[i])
			{
				ans++;
				now = (now + 1) * c + now;
			}
			now = coin[i] * c + now;
			if (now >= v)
				break;
		}
		cout << "Case #" << tcase << ": " << ans << endl;
	}
}
