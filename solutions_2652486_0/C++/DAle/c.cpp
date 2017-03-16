#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>

using namespace std;

map<int, int> mp;
int way[10];
int n, m;
int base;

bool check()
{
	++base;
	int res = 0;
	for (int mask = 0; mask < (1<<n); ++mask)
	{
		int p = 1;
		for (int j = 0; j < n; ++j)
			if (mask & (1<<j))
			{
				p *= way[j];
			}
			if (mp.find(p) != mp.end())
			{
				if (mp[p] != base) ++res;
				mp[p] = base;
			}
	}
	if (res == mp.size()) return true;
	return false;
}

bool Go(int step) {
	if (step == n)
	{
		if (check())
			return true;
		else
			return false;
	}
	for (int i = 2; i <= m; ++i)
	{
		way[step] = i;
		if (Go(step+1)) return true;
	}
	return false;
}

int main()
{
	ifstream ifs("c.in");
	ofstream ofs("c.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		ofs << "Case #" << test+1 << ":" << endl;
		int r, k;
		ifs >> r >> n >> m >> k;
		for  (int i = 0; i < r; ++i)
		{
			mp.clear();
			for (int j = 0; j < k; ++j)
			{
				int z;
				ifs >> z;
				mp[z] = 0;
			}
			Go(0);
			for (int i = 0; i < n; ++i)
				ofs << way[i];
			ofs << endl;
		}
		int res;

	}
	return 0;
}
