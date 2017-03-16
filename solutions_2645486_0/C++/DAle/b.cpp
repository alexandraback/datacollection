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

int e, r, n;

vector<int> v;

int f[20][10];

int Go(int step, int cnt)
{
	int& res = f[step][cnt];
	if (res != -1) return res;
	if (step == n) return 0;	
	res = 0;
	for (int i = 0; i <= cnt; ++i)
	{
		res = max(res, v[step]*i + Go(step+1, min(e, cnt-i+r)));
	}
	return res;
}

int main()
{
	ifstream ifs("b.in");
	ofstream ofs("b.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		v.clear();
		memset(f, -1, sizeof(f));
		ifs >> e >> r >> n;
		for (int i = 0; i < n; ++i)
		{
			int j;
			ifs >> j;
			v.push_back(j);
		}
		int res = Go(0, e);
		ofs << "Case #" << test+1 << ": " << res << endl;
	}
	return 0;
}
