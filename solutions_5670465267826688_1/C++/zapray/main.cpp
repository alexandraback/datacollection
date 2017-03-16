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
typedef long long ll;


// 1 i j k -1 -i -j -k
int m[4][4] =
{ 
{ 0, 1, 2, 3 },
{ 1, 4, 3, 6 },
{ 2, 7, 4, 1 },
{ 3, 2, 5, 4 } };


int main()
{
	int t;
	cin >> t;
	for (int cs = 1; cs <= t; cs++)
	{
		printf("Case #%d: ",cs);
		int l;
		ll X;
		cin >> l >> X;
		if (X>12) X= X % 12 + 12;
		int x = X;
		string s;
		cin >> s;
		int p = 0;
		int ifirst = INT_MAX;
		int klast = -1;
		for (int i = 0; i < x * l; i++)
		{
			int sign = (p & 4);
			p &= 3;
			int tmp = m[p][s[i%l] - 'i' + 1];
			tmp ^= sign;
			if (tmp == 1) ifirst = min(ifirst, i);
			if (tmp == 3) klast = max(klast, i);

			p = tmp;
		}

		puts((p == 4 && ifirst < klast) ? "YES" : "NO");
	}
	

	return 0;
}