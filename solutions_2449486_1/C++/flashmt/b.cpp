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

int n, m, a[111][111];

int main()
{
	freopen("blarge.in", "r", stdin); 
	freopen("blarge.out", "w", stdout);
	int test;
	cin >> test;
	for (int itest = 1; itest <= test; itest++)
	{
		cin >> m >> n;
		int maxRow[111] = {0}, maxCol[111] = {0};
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)	
			{
				cin >> a[i][j];
				maxRow[i] = max(maxRow[i], a[i][j]);
				maxCol[j] = max(maxCol[j], a[i][j]);
			}
				
		int ans = 1;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				ans &= (a[i][j] == maxRow[i] || a[i][j] == maxCol[j]);
				
		printf("Case #%d: %s\n", itest, (ans ? "YES" : "NO"));
	}
}
