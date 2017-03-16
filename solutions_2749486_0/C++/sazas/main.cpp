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

#define FILE_NAME "B-small"

using namespace std;


int main()
{
	freopen(FILE_NAME ".in", "r", stdin);
	freopen(FILE_NAME ".out", "w", stdout);
	
	int numTestCaces = 0;
	cin >> numTestCaces;
	for(int Case = 1; Case <= numTestCaces; ++Case)
	{
		int x, y;
		cin >> x >> y;
		string res;
		if(x > 0)
			for(int i = 0; i < x; ++i)
				res += "WE";
		else
			for(int i = 0; i < -x; ++i)
				res += "EW";
		if(y > 0)
			for(int i = 0; i < y; ++i)
				res += "SN";
		else
			for(int i = 0; i < -y; ++i)
				res += "NS";

		cout << "Case #" << Case << ": " << res << endl;
	}

	return 0;
}
