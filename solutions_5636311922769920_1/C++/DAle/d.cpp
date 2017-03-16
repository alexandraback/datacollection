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
	ifstream ifs("d.in");
	ofstream ofs("d.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		long long k, c, s;
		ofs << "Case #" << test+1 << ":";
		ifs >> k >> c >> s;
		if (c == 1) {
			if (k == s) {
				for (int i = 0; i < k; ++i) ofs << ' ' << i+1;
				ofs << endl;
			} else {
				ofs << " IMPOSSIBLE\n";
			}
		} else {
			if (s * 2 < k) {
				ofs << " IMPOSSIBLE\n";
			} else {
				long long all = 1;
				for (int i = 0; i < c; ++i) all *= k;
				long long shift = all / k;
				for (int i = 0; i+1 < k; i += 2) {
					long long pos = shift*i + i+1 + 1;
					ofs << ' ' << pos;
				}	
				if (k % 2 == 1) {
					ofs << ' ' << all;
				}
				ofs << endl;
			}
		}
	}
	return 0;
}
