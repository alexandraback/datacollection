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
		int n, J;
		cin >> n >> J;

		cout << "Case #" << Case << ": ";
		
		cout << endl;
		for(int j = 0; j < J; ++j)
		{
			cout << "11";
			for(int i = 0; i < (n - 4)/2; ++i)
			{
				if(j & (1 << i))
					cout << "11";
				else
					cout << "00";
			}
			cout << "11";
			for(int i = 3; i < 12; ++i)
				cout << ' ' << i ;
			cout << endl;
		}
	}

	return 0;
}
