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
	int j, p, s, k;
	void input()
	{
		cin >> j >> p >> s >> k;
	}
	
	vector<tuple<int, int, int>> answer;

	void process()
	{
		map<pair<int, int>, int> jp, ps, js;

		for (int a = 0; a < j; a++)
		{
			for (int b = 0; b < p; b++)
			{
				for (int c = 0; c < s; c++)
				{
					if (jp[{a, b}] < k && ps[{b, c}] < k && js[{a, c}] < k)
					{
						jp[{a, b}]++;
						ps[{b, c}]++;
						js[{a, c}]++;
						answer.emplace_back(a, b, c);	
					}
				}
			}
		}
	}
	void output()
	{
		cout << answer.size();
		for (const auto &i : answer)
		{
			cout << endl << get<0>(i) + 1 << " " << get<1>(i) + 1 << " " << get<2>(i) + 1;
		}
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
