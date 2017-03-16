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

int ABS(int a)
{
	if (a < 0) return -a;
	return a;
}

struct TestCase
{
	string a, b;

	string answerA, answerB;

	void input()
	{
		cin >> a >> b;
	}
	void process()
	{
		function<void(int)> step;
		vector<pair<int, bool>> plan;

		int best = INT_MAX;

		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == '?')
			{
				plan.push_back({ i, true });
			}
		}
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i] == '?')
			{
				plan.push_back({ i, false });
			}
		}

		step = [&](int current)
		{
			if (current == plan.size())
			{
				int value = ABS(stoi(a) - stoi(b));
				if (best > value)
				{
					best = value;
					answerA = a;
					answerB = b;
				}
				return;
			}

			const auto k = plan[current].first;
			if (plan[current].second)
			{
				for (int i = 0; i <= 9; i++)
				{
					a[k] = i + '0';
					step(current + 1);
				}
			}
			else 
			{
				for (int i = 0; i <= 9; i++)
				{
					b[k] = i + '0';
					step(current + 1);
				}
			}
		};

		step(0);
	}
	void output()
	{
		cout << answerA << " " << answerB;
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
