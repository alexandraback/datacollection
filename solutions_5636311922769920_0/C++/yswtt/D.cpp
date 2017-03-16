#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		long long k, c, s;
		cin >> k >> c >> s;
		cout << "Case #" << t << ":";
		if (c * s < k)
		{
			cout << " IMPOSSIBLE" << endl;
			continue;
		}
		long long cur = 1;
		vector<long long> v;
		for (int i = 0; i < s; ++i)
		{
			long long res = 1;
			for (int j = 0; j < c; ++j)
			{
				res = (res - 1) * k + cur;
				cur = cur % k + 1;
			}
			v.push_back(res);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for (int i = 0; i < v.size(); ++i)
			cout << " " << v[i];
		cout << endl;
	}

    return 0;
}
