#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int a[102][102];
int main()
{
	int T, m, n;
	freopen("QB.in", "r", stdin);
	freopen("QB.out", "w", stdout);
	cin >> T;
	for(int tt = 1 ; tt <= T ; tt++)
	{
		memset(a, 0, sizeof(a));
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= m ; j++)
				cin >> a[i][j];
		cout << "Case #" << tt << ": ";
		int can = 1;
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= m ; j++)
			{
				int b = 1, c = 1;
				for(int k = 1 ; k <= m ; k++)
					if(a[i][k] > a[i][j]) b = 0;
				for(int k = 1 ; k <= n ; k++)
					if(a[k][j] > a[i][j]) c = 0;
				if(!b && !c)
				{
					can = 0;
					break;
				}
			}
			if(can == 0) break;
		}
		if(can)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
