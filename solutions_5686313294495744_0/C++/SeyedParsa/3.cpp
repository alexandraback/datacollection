//be naame khodaa

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cassert>
#include <iomanip>
typedef long long ll;
#define X first
#define Y second

using namespace std;
typedef pair <int, int> pii;
pair <string, string> s[20];

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int it = 1; it <= t; it++){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> s[i].X >> s[i].Y;
		int ans = 0;
		for (int i = 0; i < (1 << n); i++){
			map < pair <string, string>, bool > mp;
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
				{
					if (((i >> j)&1) && ((i >> k)&1))
						mp[make_pair(s[j].first, s[k].second)] = true;
				}
			bool ok = true;
			for (int j = 0; j < n; j++)
				if (!((i >> j)&1) && mp.find(s[j]) == mp.end())
					ok = false;
			if (ok) ans = max(ans, n - int(__builtin_popcount(i)));
		}
		cout << "Case #" << it << ": " << ans << endl;
	}
	return 0;
}
