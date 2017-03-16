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

int main()
{	
	//test(); return 0;
	int Case, cases = 0;
	scanf("%d" , &Case);

	while (Case--)
	{
		int n;
		string in;
		cin >> n >> in;

		int ans = 0;
		int cur = in[0]-48;

		for (int i = 1; i < n+1; ++i)
		{
			int t = in[i]-48;
			if (cur < i)
			{
				ans += i-cur;
				cur += i-cur;
			}
			cur += t;
		}


		printf("Case #%d: %d\n" , ++cases, ans);
	}

	return 0;
}