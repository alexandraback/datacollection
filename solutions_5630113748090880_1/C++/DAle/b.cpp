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
		ifs >> n;
		ofs << "Case #" << test+1 << ":";
		map<int, int> m;
		for (int i = 0; i < 2*n-1; ++i) {
			for (int j = 0; j < n; ++j)
			{
				int k;
				ifs >> k;
				m[k]++;
			}
		}
		for (auto mi : m) {
			if (mi.second % 2 == 1) {
				ofs << ' ' << mi.first;
			}
		}
		ofs << endl;
	}
	return 0;
}
