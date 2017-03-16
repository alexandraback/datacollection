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

bool ok(unsigned long long m, unsigned long long fr, unsigned long long v)
{
	unsigned long long k = (2*fr+1) + (2*fr+1+4*(m-1)); 
	unsigned long long s = v*2 / m;
	return k <= s;
}

int main()
{
	ifstream ifs("a.in");
	ofstream ofs("a.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		unsigned long long fr, v;
		ifs >> fr >> v;
		unsigned long long maxr = (v+fr) / (fr+1);
		unsigned long long l = 0, r = maxr;
		while (r-l > 1)
		{
			unsigned long long m = (l+r) / 2;
			if (ok(m, fr, v))
			{
				l = m;
			}
			else 
			{
				r = m-1;
			}
		}
		if (ok(r, fr, v)) l = r;
		ofs << "Case #" << test+1 << ": " << l << endl;
	}
	return 0;
}
