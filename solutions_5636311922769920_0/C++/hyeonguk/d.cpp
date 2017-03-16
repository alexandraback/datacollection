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
	vector<LL> answer;

	LL k, c, s;
	void input()
	{
		cin >> k >> c >> s;
	}
	void process()
	{
		if (c * s < k)
		{
			return;
		}
		for (LL begin = 0; begin < k; begin += c)
		{
			LL end = begin + c - 1;
			end = min(end, k - 1);
			LL step = 1;
			for (LL l = 1; l < c; l++)
			{
				step *= k;
			}
			LL index = 1;
			for (LL j = begin; j <= end; j++)
			{
				index += step * j;
				step /= k;
			}
			answer.push_back(index);
		}
	}
	void output()
	{
		if (answer.size() == 0)
		{
			cout << "IMPOSSIBLE";
		}
		else
		{
			for (auto &i : answer)
			{
				cout << i << " ";
			}
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
