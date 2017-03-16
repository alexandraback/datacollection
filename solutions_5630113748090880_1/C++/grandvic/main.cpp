#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iterator>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	vector<int> h(2501);
	int n; cin >> n;
	for (int i = 0; i < 2 * n - 1; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int x; cin >> x;
			h[x] ^= 1;
		}
	}
	vector<int> answer;
	for (int i = 1; i < 2501; ++i)
		if (h[i])
			cout << i << " ";
	cout << endl;
}

int main()
{
//	freopen("i:/input.txt", "rt", stdin);
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
