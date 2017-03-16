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

#define FILE_NAME "C-small"

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
		vector<int> v(n);
		for(int i = 0; i < n; ++i)
			cin >> v[i];
		map<int, vector<int> > m;
		int res = 0;
		vector<int> s;
		for(int i = 1; i < (1 << n); ++i)
		{
			int sum = 0;
			s.clear();
			int mask = i;
			int j = 0;
			while(mask > 0)
			{
				if(mask & 1)
				{
					s.push_back(v[j]);
					sum += v[j];
				}
				mask >>= 1;
				++j;
			}
			if(m.count(sum) > 0)
			{
				res = sum;
				break;
			}
			m[sum] = s;
		}

		cout << "Case #" << Case << ": " << endl;
		if(res > 0)
		{
			for(int i = 0; i < s.size(); ++i)
			{
				cout << s[i] << ' ';
			}
			cout << endl;
			s = m[res];
			for(int i = 0; i < s.size(); ++i)
			{
				cout << s[i] << ' ';
			}
			cout << endl;
		}
		else
		{
			cout << "Impossible" << endl;
		}
	}

	return 0;
}
