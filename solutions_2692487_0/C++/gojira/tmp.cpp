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

using namespace std;

int biggest[101][101]; // [i][j] = what max size you can get if you eat i smallest motes and use j operations

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, k, n, T, a;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> a >> n;
		vector<int> x(n);
		for(i = 0; i < n; i++)
			cin >> x[i];
		sort(x.begin(), x.end());
		memset(biggest, -1, sizeof(biggest));
		biggest[0][0] = a;
		for(i = 0; i < n; i++)
			for(j = 0; j <= n; j++)
			{
				if (biggest[i][j] == -1) continue;
				if (j < n)
				{
					int newSize = 2 * biggest[i][j] - 1;
					if (biggest[i][j + 1] == -1 || biggest[i][j + 1] < newSize)
						biggest[i][j + 1] = newSize;
					if (biggest[i + 1][j + 1] == -1 || biggest[i + 1][j + 1] < biggest[i][j])
						biggest[i + 1][j + 1] = biggest[i][j];
				}
				if (biggest[i][j] <= x[i]) continue;
				if (biggest[i + 1][j] == -1 || biggest[i + 1][j] < biggest[i][j] + x[i])
					biggest[i + 1][j] = biggest[i][j] + x[i];
			}
		for(j = 0; j <= n; j++)
			if (biggest[n][j] != -1) break;
		printf("Case #%d: %d\n", t, j);
	}

	return 0;
}