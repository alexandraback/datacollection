#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <mutex>
#include <thread>
#include <iostream>
#include <algorithm>
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

typedef __int128 LL;

int j;
const LL D = 1024;

mutex outputMutex;

struct TestCase
{
	LL n;
	LL m;

	void process()
	{
		LL begin = ((1LL << (n - 1)) / D) * m;
		LL end = begin + ((1LL << (n - 1)) / D);

		begin += (1LL << (n - 1)) + 1;
		end += (1LL << (n - 1));

		for (LL i = begin; i < end; i += 2)
		{
			// fprintf(stderr, "%lld\n", i);	
			bool prime = false;
			vector<LL> div;
			for (LL b = 2; b <= 10; b++)
			{
				LL j = i;

				LL digit = 1;
				LL v = 0;
				while (j > 0)
				{
					v += (j & 1) * digit;
					j >>= 1;
					digit *= b;
				}
				bool ok = false;
				for (LL d = 2; d * d <= v && d < v; d++)
				{
					if (v % d == 0)
					{
						div.push_back(d);
						ok = true;
						break;
					}
				}
				if (ok == false)
				{
					prime = true;
					break;
				}
			}
			if (prime == false)
			{
				lock_guard<std::mutex> lock(outputMutex);
				if (j == 0)
				{
					exit(0);
					return;
				}
				for (LL m = (1LL << (n - 1)); m > 0; m >>= 1)
				{
					printf("%d", !!(i & m));
				}
				for (auto j : div)
				{
					printf(" ");
					vector<int> k;
					while (j > 0)
					{
						k.push_back(j % 10);
						j /= 10;
					}
					reverse(k.begin(), k.end());
					for (auto &b : k)
					{
						printf("%d", b);
					}
				}
				printf("\n");
				--j;
			}
		}
	}
};

int main()
{
	int t, n;
	cin >> t >> n >> j;

	t = D;

	vector<TestCase> tc(t);
	vector<future<void>> f;
	for (int i = 0; i < t; i++)
	{
		tc[i].n = n;
		tc[i].m = i;
	}
	cout << "Case #" << 1 << ": " << endl;

	for (int i = 0; i < t; i++)
		f.push_back(async(launch::async,
			[&](int p){ tc[p].process(); }, i));

	for (int i = 0; i < t; i++)
	{
		f[i].wait();
	}
	return 0;
}
