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

int n, m, R, k;
set <int> a[6][6][6];

void att(vector <int> b)
{
	for (int i = 2; i <= m; i++)
		for (int j = 2; j <= m; j++)
			for (int k = 2; k <= m; k++)
			{
				int ok = 1;
				for (int p = 0; p < int(b.size()); p++) ok &= a[i][j][k].count(b[p]);
				if (ok)
				{
					cout << i << j << k << endl;
					return;
				}
			}
	puts("222");
}

int main()
{
	freopen("csmall.in", "r", stdin); 
	freopen("csmall.out", "w", stdout);
	int test, x;
	cin >> test;
	for (int itest = 1; itest <= test; itest++)
	{
		cin >> R >> n >> m >> k;
		for (int i = 2; i <= m; i++)
			for (int j = 2; j <= m; j++)
				for (int k = 2; k <= m; k++)
				{
					a[i][j][k].insert(1);
					a[i][j][k].insert(i);
					a[i][j][k].insert(j);
					a[i][j][k].insert(k);
					a[i][j][k].insert(i * j);
					a[i][j][k].insert(i * k);
					a[i][j][k].insert(j * k);
					a[i][j][k].insert(i * j * k);
				}
		
		printf("Case #%d:\n", itest);		
		while (R--)
		{
			vector <int> b;
			for (int i = 0; i < k; i++) cin >> x, b.push_back(x);
			att(b);
		}
	}
}
