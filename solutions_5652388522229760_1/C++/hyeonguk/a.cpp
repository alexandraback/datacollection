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
	LL n;
	LL k;
	LL answer = -1;
	void input()
	{
		int p;
		scanf("%d", &p);
		k = p;
	}

	void process()
	{
		n = 0;
		bool check[10];
		for (int i = 0; i < 10; i++)
		{
			check[i] = false;
		}
		for (int i = 0; i < 1000000000; i++)
		{
			LL m = n;
			while (m > 0)
			{
				check[m % 10] = true;
				m /= 10;
			}
			bool ok = true;
			for (LL i = 0; i < 10; i++)
			{
				if (check[i] == false)
				{
					ok = false;
					break;			
				}
			}
			if (ok)
			{
				answer = n;
			}
			if (answer >= 0)
			{
				break;
			}
			n += k;
		}
	}
	void output()
	{
		if (answer < 0)
		{
			printf("INSOMNIA");
			return;
		}
		printf("%lld", n);
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
