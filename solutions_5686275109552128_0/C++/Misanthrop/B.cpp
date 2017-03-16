#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T; cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		int n; cin >> n;
		vector<int> a;
		a.resize(n);
		for(int i = 0; i < n; ++i) cin >> a[i];
		int m = *max_element(a.begin(), a.end());
		int best = m;
		for(int i = 1; i <= m; ++i)
		{
			int spec = 0;
			for(int x : a) spec += max(0, (x - 1)/i);
			int current = spec + i;
			best = min(best, current);
		}
		cout << "Case #" << t << ": " << best << endl;
	}
	return 0;
}
