#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring> 
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <LL> VL;

const int MAXN = 55;

char G[MAXN][MAXN];


int main()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	
	int T;	cin >> T;
	for (int cas = 1; cas <= T; ++ cas)
	{
		int R, C, M;
		cin >> R >> C >> M;
		M = R * C - M;
		cout << "Case #" << cas << ":" << endl;
		for (int i = 0; i < R; ++ i) 
			for (int j = 0; j < C; ++ j)
				G[i][j] = '*';
		if (min (R, C) == 1 || M == 1)
		{
			for (int i = 0; M > 0 && i < R; ++ i)	
				for (int j = 0; M > 0 && j < C; ++ j)
					G[i][j] = '.', -- M;
			G[0][0] = 'c';
			for (int i = 0; i < R; ++ i, cout << endl)
				for (int j = 0; j < C; ++ j)
					cout << G[i][j];
		}	
		else
		{
			bool ok = false;
			for (int n = R; n >= 2; -- n)
			{
				int m = M / n;
				int r = M % n;
				if (m < 2)	continue;
				if (r == 0 && m <= C)	ok = true;
				if (r > 1 && m < C)	ok = true;
				if (ok)
				{
					for (int i = 0; i < n; ++ i)
						for (int j = 0; j < m; ++ j)
							G[i][j] = '.';
					for (int j = 0; j < r; ++ j)
					{
						G[j][m] = '.';	
					}	
					G[0][0] = 'c';
					for (int i = 0; i < R; ++ i, cout << endl)
						for (int j = 0; j < C; ++ j)
							cout << G[i][j];
					break;
				}
				
				if (r == 1 && m >= 3 && m < C && n >= 3)	
				{
					ok = true;
					for (int i = 0; i < n; ++ i)
						for (int j = 0; j < m; ++ j)
							G[i][j] = '.';
					for (int j = 0; j <= r; ++ j)
					{
						G[j][m] = '.';	
					}	
					G[0][0] = 'c';
					G[n - 1][m - 1] = '*';
					for (int i = 0; i < R; ++ i, cout << endl)
						for (int j = 0; j < C; ++ j)
							cout << G[i][j];
					break;
				}
			}	
			
			if (!ok)	cout << "Impossible" << endl;
		}
	}
	
	
	
	return 0;	
}
