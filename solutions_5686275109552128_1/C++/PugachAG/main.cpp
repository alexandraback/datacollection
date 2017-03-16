#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <queue>
#include <ctime>
#include <functional>
#include <cstring>
#include <map>
#include <cctype>

using namespace std;

int test_case(vector<int> &d)
{
	auto it = d.end();
	--it;
	int res = *it;
	for (int s = *it - 1; s > 1; s--)
	{
		int t = 0;
		for (int &v : d)
		{
			t += v / s;
			if (v % s == 0)
				t--;
		}
		res = min(res, t + s);
	}
	return res;
}


int main()
{
	freopen("INPUT.TXT", "r", stdin); freopen("OUTPUT.TXT", "w", stdout);
	int t, n, val;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		vector<int> d;
		for (int i = 0; i < n; i++)
		{
			cin >> val;
			d.push_back(val);
		}
		sort(d.begin(), d.end());
		int res = test_case(d);
		cout << "Case #" << i + 1 << ": " << res << endl;
	}
}