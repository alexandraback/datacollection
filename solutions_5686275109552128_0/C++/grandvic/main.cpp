#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long Num;

int sol(vector<Num> & h, int start)
{
	while (start && !h[start])
		--start;
	Num cnt = h[start];
	int value = start;

	int result = value;
	for (int i = 2; i * i <= value; ++i)
	{
		int v1 = value / i;
		int v2 = v1 + 1;
		Num c2 = (Num)(value % i);
		Num c1 = (Num)i - c2 - 1;
		c1 *= cnt;
		c2 *= cnt;
		if (c1 + c2 >= (Num)result)
		{
			continue;
		}

		h[v1] += c1 + 1;
		h[v2] += c2;
		result = min(result, (int)(c1 + c2) + sol(h, start - 1));
		h[v1] -= (c1 + 1);
		h[v2] -= c2;
	}
	return result;
}

void solve()
{
	int d; cin >> d;
	vector<Num> h(1001);
	for (int i = 0, index; i < d; ++i)
	{
		cin >> index;
		++h[index];
	}
	cout << sol(h, 1000) << endl;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
#ifdef GRANDVIC_DEBUG
	//freopen("d:/input.txt", "rt", stdin);
#endif
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
}
