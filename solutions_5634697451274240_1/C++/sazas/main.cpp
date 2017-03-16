#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define FILE_NAME "B-large"

using namespace std;

int main()
{
	freopen(FILE_NAME ".in", "r", stdin);
	freopen(FILE_NAME ".out", "w", stdout);
	
	int numTestCaces = 0;
	cin >> numTestCaces;
	for(int Case = 1; Case <= numTestCaces; ++Case)
	{
		string s;
		cin >> s;
		s += '+';
		int res = 0;
		for(int i = 1; i < s.size(); ++i)
			if(s[i] != s[i-1])
				++res;


		cout << "Case #" << Case << ": ";
		cout << res << endl;
	}

	return 0;
}
