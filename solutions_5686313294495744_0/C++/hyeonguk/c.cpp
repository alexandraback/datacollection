#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <cctype>
#include <functional>
#include <future>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

struct TestCase
{
	int n;
	vector<vector<string>> data;

	void input()
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;
			data.push_back({a, b});
		}
	}
	
	int answer = INT_MIN;

	void process()
	{
		for (int bits = 0; bits < (1 << n); bits++)
		{
			int fake = 0;
			set<string> first, second;
			for (int i = 0; i < n; i++)
			{
				if (bits & (1 << i))
				{
					first.insert(data[i][0]);
					second.insert(data[i][1]);
				}
				else
				{
					fake++;
				}
			}

			bool ok = true;
			for (int i = 0; i < n; i++)
			{
				if (!(bits & (1 << i)))
				{
					if (first.count(data[i][0]) &&
						second.count(data[i][1]))
					{
					}
					else
					{
						ok = false;
						break;
					}
				}
			}
			if (ok)
			{
				answer = max(answer, fake);
			}
		}
	}
	void output()
	{
		cout << answer;
	}
};

int main()
{
	int t;
	cin >> t;

	vector<TestCase> tc(t);
	vector<future<void>> f;
	for (int i = 0; i < t; i++) tc[i].input();
	for (int i = 0; i < t; i++)
		f.push_back(async(launch::async,
			[&](int p){ tc[p].process(); }, i));
	// for (int i = 0; i < t; i++) f[i].wait();
	for (int i = 0; i < t; i++)
	{
		f[i].wait();
		cout << "Case #" << i + 1 << ": ";
		tc[i].output();
		cout << endl;
	}
	return 0;
}
