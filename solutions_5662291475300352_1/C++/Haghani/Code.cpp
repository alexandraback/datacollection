#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	vector<pair<long long, long long> > hikers;
	for (int _ = 1; _ <= t; _++)
	{
		int n;
		cin >> n;
		hikers.clear();
		for (int i = 0; i < n; i++)
		{
			int pos, cnt, time;
			cin >> pos >> cnt >> time;
			for (int j = 0; j < cnt; j++)
				hikers.push_back(make_pair(time + j, pos));
		}
		sort(hikers.begin(), hikers.end());
		long long mx = 0;
		int ans = 0;
		for (int i = 0; i < hikers.size(); i++)
		{
			bool bad = false;
			for (int j = i + 1; j < hikers.size(); j++)
				if (hikers[i].first * (720 - hikers[i].second) <= hikers[j].first * (360 - hikers[j].second))
				{
					bad = true;
					break;
				}
			if (bad)
				ans++;
		}
		cout << "Case #" << _ << ": " << ans << endl;
	}
	return 0;
}
