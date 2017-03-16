
#include <iostream>
#include <istream>
#include <stdio.h>
#include <string>
#include <vector> 
#include <fstream>
#include <queue>
#include <algorithm>
#define INF 2147483647
#define BIG 1000000007

using namespace std; 

int main ()
{
    freopen ("B-small-attempt1 (1).in", "r", stdin);
	freopen ("B.out", "w", stdout); 
 	int tt; 
 	cin >> tt; 
 	for (int cases = 1; cases <= tt; cases++)
 	{
 		cout << "Case #" << cases << ": ";
 		int d; 
 		cin >> d;
 		int p [1001];
 		for (int x = 0; x < 1001; x++)
 			p[x] = 0;
 		int n = 0;
 		for (int x = 0; x < d; x++)
 		{
 			int temp; 
			cin >> temp; 
			p[temp]++;
			n = max (n, temp);	
		}
		int best[n+1];
		best[n] = n;
		for (int x = n - 1; x > 0; x--)
		{
			int spec = 0;
			for (int y = x + 1; y <= n; y++)
			{
				if (p[y] > 0)
				{
					//cout << "amt: " << y << " " << p[y]*(y/x) << "\n";;
					spec += p[y]*(y/x);
					if (y%x == 0)
						spec-=p[y];
				}
			}
			//cout << x << " " << spec << "\n";
			best[x] = spec + x;
		}
		int ans = best[n];
		for (int x = 1; x <= n; x++)
		{
			//cout << best[x] << " ";
			ans = min (ans, best[x]);
	 	}
	 cout << ans << "\n";
	}
}
