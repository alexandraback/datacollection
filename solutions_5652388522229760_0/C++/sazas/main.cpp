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

#define FILE_NAME "A-small"

using namespace std;

int main()
{
	freopen(FILE_NAME ".in", "r", stdin);
	freopen(FILE_NAME ".out", "w", stdout);
	
	int numTestCaces = 0;
	cin >> numTestCaces;
	for(int Case = 1; Case <= numTestCaces; ++Case)
	{
		int n;
		cin >> n;

		cout << "Case #" << Case << ": ";
		if(n == 0)
		{
			cout << "INSOMNIA" << endl;
			continue;
		}
		
		std::vector<int> digs(10, 0);
		int cnt = 0;
		int i = 0;
		while(cnt < 10)
		{
			++i;
			int cur = i * n;
			while(cur > 0)
			{
				if(digs[cur % 10] == 0)
				{
					++cnt;
					digs[cur % 10] = 1;
				}
				cur /= 10;
			}
		}

		cout << i * n << endl;
	}

	return 0;
}
