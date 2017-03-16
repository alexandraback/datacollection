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
		int n;
		string s;
		ifs >> n >> s;
		int res = 0;
		int cur = 0;
		for (int i = 0; i <= s.size(); ++i)
		{
			if (cur < i) { cur++; res++; }
			cur += s[i] - '0';
		}
		ofs << "Case #" << test+1 << ": " << res << endl;
	}
	return 0;
}
