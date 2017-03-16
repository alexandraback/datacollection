#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int LEN = 360;

typedef pair<int, int> pii;

vector<pii> v;

int main()
{
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; tc++)
	{
		v.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x, cnt, m;
			cin >> x >> cnt >> m;
			for (int j = 0; j < cnt; j++)
				v.push_back(pii(m + j, x));
		}
		cout << "Case #" << tc << ": ";
		sort(v.begin(), v.end());
		if (v.size() == 1)
			cout << 0 << endl;
		else
		{
			long long dist = v[1].second - v[0].second + LEN;
			long long dist2 = LEN - v[1].second;
			if (dist2 * (v[1].first - v[0].first) < dist * (v[0].first))
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}
	}
}
