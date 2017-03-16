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
		string s;
		ifs >> s;
		int groups = 1;
		for (int i = 1; i < s.size(); ++i) 
			if (s[i] != s[i-1]) ++groups;
		int res = s[s.size()-1] == '+' ? groups - 1 : groups; 

		ofs << "Case #" << test+1 << ": " << res << endl;
	}
	return 0;
}
