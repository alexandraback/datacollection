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


int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);	
#endif

	int T; cin >> T;
	for (int t = 1; t <= T; t ++)
	{
		int n, m, M;
		cin >> n >> m >> M;
		int white = n * m - M;
		
		cout << "Case #" << t << ": " << endl;
		
		//special cases
		if (n == 1)
		{		
			cout << "c";
			for (int i = 1; i < white; i ++)
				cout << ".";
			for (int i = 1; i <= m - white; i ++)	
				cout << "*";
			cout << endl;
			continue;
		}
		if (m == 1)
		{
			cout << "c" << endl;
			for (int i = 1; i < white; i ++)
				cout << "." << endl;
			for (int i = 1; i <= n - white; i ++)
				cout << "*" << endl;
			continue;
		}
		if (white == 1)
		{
			for (int i = 1; i <= n; i ++)
			{
				for (int j = 1; j <= m; j ++)
					if (i == 1 && j == 1)
						cout << "c";
					else cout << "*";	
				cout << endl;
			}
			continue;
		}
		
		bool ok = false;
		
		for (int x = 2; x <= white; x ++)	
		{	
			if (! (x <= m && white / x + (white % x ? 1 : 0) <= n && white / x > 1)) 
				continue;
			int row[100];
			int y = white / x;
			for (int i = 1; i <= white / x; i ++)
				row[i] = x;
			if (white % x)
				row[white / x + 1] = white % x, y ++;
			if (row[y] == 1)
				row[y] ++, row[y - 1] --;
	
			if ((row[1] != row[2] || row[y] > row[y - 1]))
				continue;

			for (int i = 1; i <= n; i ++)
			{
				for (int j = 1; j <= m; j ++)
					if (i <= y && j <= row[i])
					{
						if (i == 1 && j == 1)
							cout << "c";
						else
							cout << ".";
					}
					else cout << "*";
				cout << endl;
			}

			ok = true; break;
		}
		if (! ok)
		{
//			cout << n << " " << m << " " << M << endl;
			cout << "Impossible" << endl;
		}
	}
	return 0;
	
}
