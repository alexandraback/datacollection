#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>

#define INF 2147483647
#define PI acos(-1.0)

using namespace std;

int main(int argc, const char ** argv)
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test)
	{
		long long c, d, n;
		cin >> c >> d >> n;
		vector<long long> den;
		for(int i = 0; i < d; ++i)
		{
			long long a;
			cin >> a;
			den.push_back(a);
		}
		sort(den.begin(), den.end());
		reverse(den.begin(), den.end());
		int ans = 0;
		long long cur = 0;

		while(cur < n)
		{
			if(!den.empty() && den.back() == cur + 1)
				den.pop_back();
			else
				ans++;

			cur += (cur + 1ll) * c;

			while(cur < n && !den.empty() && den.back() <= cur)
			{
				cur += den.back() * c;
				den.pop_back();
			}
		}

		printf("Case #%d: %d\n", test, ans);
	}

	return 0;
}
