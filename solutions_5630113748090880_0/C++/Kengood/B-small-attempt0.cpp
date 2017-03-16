#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;




int main(int aN, char **aG)
{	
	int Case, cases = 0;
	scanf("%d" , &Case);
	while (Case--)	
	{
		int n;
		cin >> n;
		vector< vector<int> > in(n*2-1, vector<int>(n));
		

		map<int,int> cnt;
		for (int i = 0; i < n*2-1; ++i)
		{
			for (int j = 0 ; j < n; ++j)
			{
				cin >>in[i][j];
				++cnt[ in[i][j] ];
			}
		}

		

		printf("Case #%d: " , ++cases );
		for (auto iter = cnt.begin(); iter != cnt.end(); ++iter)
		{
			if (iter->second&1)
				cout << iter->first << " ";
		}
		cout << endl;
	}

	return 0;
}

