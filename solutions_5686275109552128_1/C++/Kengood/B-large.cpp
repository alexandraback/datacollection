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

// I HATE MATHS
int main()
{	
	int Case, cases = 0;
	scanf("%d" , &Case);

	while (Case--)
	{
		int n;
		
		cin >> n;
		vector<int> in(n);
		int maxFood = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> in[i];
			maxFood = max(maxFood,in[i]);
		}
		int ans = maxFood;
		for(int foodOnDish = 1; foodOnDish <= maxFood; ++foodOnDish)
		{
			int t = foodOnDish; //make all the number of pancake same
			for (int i = 0; i < n; ++i)
			{
				if (foodOnDish < in[i]) //need to divide it
				{
					t += in[i]/foodOnDish;
					if (in[i]%foodOnDish==0)
						--t;
				}				
			}

			ans = min(t,ans);
		}

		printf("Case #%d: %d\n" , ++cases, ans);
	}

	return 0;
}
