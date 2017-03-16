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
	int answer;
	char cake[128];
	void input()
	{
		scanf("%s", cake);
	}
	void process()
	{
		int length;
		length = strlen(cake);
		for (;; answer++)
		{
			bool ok = true;
			for (int i = 0; i < length; i++)
			{
				if (cake[i] == '-')
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				break;
			}
			int j;
			for (j = 0; j < length; j++)
			{
				if (j == length - 1 || cake[j] != cake[j + 1]) 
				{
					break;
				}
			}
			for (; j >= 0; j--)
			{
				cake[j] = cake[j] == '+' ? '-' : '+';
			}
		}
	}
	void output()
	{
		printf("%d", answer);
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
