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
		int p[1050];

		for (int i = 0; i < n; i++) scanf("%d",p+i);

		
		sort(p, p + n);
		int ans = p[n-1];
		for (int h = p[n - 1]; h >= 1; h--)
		{
			int e = 0;
			for (int i = 0; i < n; i++)
				if (p[i]>h) e += (p[i] - 1) / h;
			ans = min(ans, h + e);
		}
		cout << ans << endl;
	}
	

	return 0;
}