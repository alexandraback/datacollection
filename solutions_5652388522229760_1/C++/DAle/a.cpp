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
	ifstream ifs("a.in");
	ofstream ofs("a.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		long long n;
		ifs >> n;
		ofs << "Case #" << test+1 << ": ";
		if (n == 0) ofs << "INSOMNIA\n";
		else {
			set<int> s;
			int i;
			for (i = 1; s.size() < 10; ++i) {
				long long k = n * i;
				while (k > 0) {
					s.insert(k % 10);
					k /= 10;
				}
			}

			ofs << n*(i-1) << endl;
		}
	}
	return 0;
}
