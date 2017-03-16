#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<int> solve()
{
	int n;
	cin >> n;
	int m = 2 * n - 1;
	int nm = n * m;

	set<int> s;
	for (int i = 0; i < nm; ++i)
	{
		int curr;
		cin >> curr;
		if (s.find(curr) != s.end())
			s.erase(curr);
		else
			s.insert(curr);
	}
	return s;
}

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		set<int> res = solve();
		cout << "Case #" << i + 1 << ": ";
		int j = 0;
		for (set<int>::iterator it = res.begin(), end = res.end(); it != end; ++it, ++j)
		{
			if (j)
				cout << " ";
			cout << *it;
		}
		cout << endl;
	}
	return 0;
}
