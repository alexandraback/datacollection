#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const double PI = acos(-1.0);

int n;

int main()
{
	freopen("asmall.in", "r", stdin); 
	freopen("asmall.out", "w", stdout);
	int test;
	cin >> test;
	for (int itest = 1; itest <= test; itest++)
	{
		long long t, r;
		cin >> r >> t;
		long long low = 1, high = 2000000000, ans = 0;
		while (low <= high)
		{
			long long mid = (low + high) / 2;
			if (t * 2 / mid >= 4LL * r - 2 + 4LL * mid) ans = mid, low = mid + 1;
			else high = mid - 1;
		}
		printf("Case #%d:", itest);
		cout << ' ' << ans << endl;
	}
}
