#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>
#include <climits>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int cs = 1; cs <= t; cs++)
	{
		printf("Case #%d: ",cs);
		int n;
		cin >> n;
		string s;
		cin >> s;

		int ans = 0;
		int cur=s[0]-'0';
		for (int i = 1; i <= n; i++)
		{
			if (s[i] > '0' && cur < i)
			{
				ans += i - cur;
				cur = i;
			}
			cur += s[i] - '0';
		}
		cout << ans << endl;
	}
	

	return 0;
}