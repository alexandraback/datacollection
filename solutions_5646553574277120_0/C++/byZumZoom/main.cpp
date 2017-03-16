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

vector <int> den;
vector <bool> can;

void rec(int cur, int i)
{
	if(cur < can.size())
		can[cur] = true;

	if(i == den.size())
		return;

	rec(cur, i + 1);
	cur += den[i];
	rec(cur, i + 1);
}

int main(int argc, const char ** argv)
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test)
	{
		int c, d, n;
		cin >> c >> d >> n;
		den.resize(d);
		can.resize(n + 1);
		can.assign(n + 1, false);
		for(int i = 0; i < d; ++i)
		{
			cin >> den[i];
		}

		rec(0, 0);

		int ans = 0;

		for(int i = 1; i <= n; ++i)
		{
			if(!can[i])
			{
				ans++;
				for(int j = n - i; j >= 0; --j)
					if(can[j])
						can[i + j] = true;
			}
		}

		printf("Case #%d: %d\n", test, ans);
	}

	return 0;
}
