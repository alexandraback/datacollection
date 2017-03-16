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

int main()
{
	ifstream ifs("b.in");
	ofstream ofs("b.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		int n;
		vector<int> v;
		ifs >> n;
		for (int i = 0; i < n; ++i)
		{
			int j;
			ifs >> j;
			v.push_back(j);
		}
		sort(v.begin(), v.end());
		int maxn = v.back();
		int res = maxn;
		for (int i = maxn-1; i >= 1; --i)
		{
			int cnt = 0;
			for (int j = 0; j < n; ++j)
				if (v[j] > i)
				{
					cnt += (v[j]-1) / i;
				}
			res = min(res, cnt + i);
		}
		ofs << "Case #" << test+1 << ": " << res << endl;
	}
	return 0;
}
