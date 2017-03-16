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

int ones(int i) { int j =0; while (i) { i &= i-1; ++j;} return j;}

int main()
{
	ifstream ifs("c.in");
	ofstream ofs("c.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		int n;
		ifs >> n;
		vector<string> f(n), s(n);
		for (int i = 0; i < n; ++i) {
			ifs >> f[i] >> s[i];
		}

		int res = 0;
		for (int i = 0; i < (1<<n); ++i) {
			int sum = 0;
			set<string> fs;
			set<string> ss;
			for (int j = 0; j < n; ++j) {
				if (i & (1<<j)) {
					fs.insert(f[j]);
					ss.insert(s[j]);
				}
			}
			for (int j = 0; j < n; ++j) {
				if (!(i & (1<<j))) {
					if (fs.count(f[j]) > 0 && ss.count(s[j]) > 0) ++sum;
				}
			}
			res = max(res, sum );
		}
		ofs << "Case #" << test+1 << ": " << res << endl;
	}
	return 0;
}
