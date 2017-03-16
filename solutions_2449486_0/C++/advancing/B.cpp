#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

const int MAX = 109;

int h[MAX][MAX], n, m;

bool check(int x, int y)
{
	int a = 1, b = 1;
	for(int i = 0; i < m; i ++)
	{
		if(i != y && h[x][i] > h[x][y]) a = 0;	
	}		
	for(int i = 0; i < n; i ++)
	{
		if(i != x && h[i][y] > h[x][y]) b = 0;	
	}
	
	return (a == 0 && b == 0);
}

bool solve()
{
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < m; j ++)
		{
			if(check(i, j))   return 0;
		}	
	}	
	return 1;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	
	int T;    cin >> T;
	for(int cas = 1; cas <= T; cas ++)
	{
		cin >> n >> m;
		for(int i = 0; i < n; i ++) 
		for(int j = 0; j < m; j ++)    cin >> h[i][j];
		
		printf("Case #%d: %s\n", cas, solve() ? "YES" : "NO");
	}

	
	return 0;	
}
