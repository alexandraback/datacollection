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
		int n, s, p;
		ifs >> n >> s >> p;
		int cnt = 0;
		for (int z = 0; z < n; ++z)
		{
			int sum;
			ifs >> sum;
			bool ok = false;
			bool good = false;
			for (int i = 0; i <= 10; ++i)
				for (int j = i; j <= min(10, i+2); ++j)
					for (int k = max(j, p); k <= min(10, i+2); ++k)
					{
						if (i+j+k == sum) {
							if (k-i > 1) good = true;
							else ok = true;
						}
					}	
			if (ok) {
				++cnt;
			}
			else if (good && s > 0)
			{
				++cnt;
				--s;
			}
		}
		ofs << "Case #" << test+1 << ": " << cnt << endl;
	}
	return 0;
}
