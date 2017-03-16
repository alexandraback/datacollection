#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <cstring>
#include <string>
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
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

int a[200][200];
int Row[200], Col[200];
int n, m;
int T;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
	cin >> T;
	for (int t = 1; t <= T; t ++)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				cin >> a[i][j];
		int flag = 1;
		cout << "Case #" << t << ": ";
		for (int H = 100; H; H --)
		{
			memset(Row, 0, sizeof(Row));
			memset(Col, 0, sizeof(Col));
			for (int i = 1; i <= n; i ++)
			{
				Row[i] = 1;
				for (int j = 1; j <= m; j ++)
					if (a[i][j] > H) Row[i] = 0;
			}
			for (int j = 1; j <= m; j ++)
			{
				Col[j] = 1;
				for (int i = 1; i <= n; i ++)
					if (a[i][j] > H) Col[j] = 0;
			}
			for (int i = 1; i <= n;i ++)
				for (int j = 1; j <= m; j ++)
					if (a[i][j] == H && ! Row[i] && ! Col[j])
						flag = 0;
		}
		if (flag)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}	
