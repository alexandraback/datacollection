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

#define FILE_NAME "A-large"

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
		vector< pair<int, int> > v(n);
		int sum = 0;
		for(int i = 0; i < n; ++i)
		{
			cin >> v[i].first;
			v[i].second = i;
			sum += v[i].first;
		}
		sort(v.begin(), v.end());
		double s2 = 2.0*sum;
		vector<double> res(n, 0.0);
		for(int i = 0; i < n; ++i)
		{
			if((s2 / (n-i) - (double)v[n-1-i].first) / sum < 0)
			{
				res[v[n-1-i].second] = 0;
				s2 -= v[n-1-i].first;
			}
			else
			{
				for(int j = 0; j < n - i; ++j)
				{
					res[v[j].second] = (s2 / (n-i) - (double)v[j].first) / sum;
				}
				break;
			}
		}

		cout << "Case #" << Case << ": ";
		for(int i = 0; i < n; ++i)
		{
			printf("%.6lf ", 100.0*res[i]);
		}
		cout << endl;
	}

	return 0;
}
