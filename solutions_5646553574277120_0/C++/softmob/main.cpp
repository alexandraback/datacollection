
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stdio.h>
#include <iomanip>
using namespace std;

class Solution
{
public:
	void run(int test)
	{
		int c, d, v;
		cin >> c >> d >> v;
		int ans = 0;
		vector<int> a(d);
		for (int i = 0; i < d; ++i)
		{
			cin >> a[i];
		}
		vector<set<int> > used(v + 1);
		for (int i = 0; i < d; ++i)
		{
			used[a[i]].insert(a[i]);
		}
		for (int i = 1; i <= v; ++i)
		{
			if (used[i].empty())
			{
				++ans;
				used[i].insert(i);
			}
			for (int j = 1; j <= v; ++j)
			{
				if (i == j)
					continue;
				set<int> q;
				int sum = 0;
				for (auto &x : used[i])
				{
					q.insert(x);
					sum += x;
				}
				for (auto &x : used[j])
				{
					q.insert(x);
					sum += x;
				}

				if (q.size() != used[i].size() + used[j].size())
					continue;

				if (i + j <= v && used[i+j].empty() && sum == i + j )
				{
					used[i + j] = q;
				}
			}
		}
		cout << "Case #" << test << ": " << ans << endl;
	}
private:

};

int main(void)
{
#if 1
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution test;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		test.run(i);
	}
	return 0;
}