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

#define FILE_NAME "D-small"

using namespace std;

int main()
{
	freopen(FILE_NAME ".in", "r", stdin);
	freopen(FILE_NAME ".out", "w", stdout);
	
	int numTestCaces = 0;
	cin >> numTestCaces;
	for(int Case = 1; Case <= numTestCaces; ++Case)
	{
		int k, c, s;
		cin >> k >> c >> s;

		cout << "Case #" << Case << ": ";

		if(s * c < k)
			cout << "IMPOSSIBLE" << endl;
		else
		{
			std::vector<long long> kc(c);
			kc[0] = 1;
			for(int i = 1; i < c; ++i)
				kc[i] = kc[i-1] * k;
			for(int j = 0; j*c < k; ++j)
			{
				int ind = 0;
				for(int i = 0; i < c && i + j*c < k; ++i)
					ind += (j*c+i) * kc[c-1-i];
				cout << ind + 1 << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}
