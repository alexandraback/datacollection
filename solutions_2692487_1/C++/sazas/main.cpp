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
		int A, n;
		cin >> A >> n;
		vector<int> m(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> m[i];
		}
		sort(m.begin(), m.end());
		
		int res = 0;
		int res1 = n;
		vector<int> r;
		r.push_back(res + res1);
		for(int i = 0; i < n;)
		{
			if(A > m[i])
			{
				A += m[i];
				--res1;
				++i;
			}
			else if(A == 1)
				break;
			else
			{
				A += A - 1;
				++res;
			}
			r.push_back(res + res1);
		}

		cout << "Case #" << Case << ": " << *min_element(r.begin(), r.end()) << endl;
	}

	return 0;
}
