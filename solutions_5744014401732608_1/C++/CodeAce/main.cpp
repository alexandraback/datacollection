#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;

int T;
ull n, M;

char g[100][100];

int main()
{
	cin >> T;
	
	for (int tc=1; tc<=T; tc++) {
		
		cin >> n >> M;
		
		cout << "Case #" << tc << ": ";
		
		if (M > (1 << (n-2)))
			cout << "IMPOSSIBLE" << endl;
		else {
			for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (j > i && j < n-1)
					g[i][j] = '1';
				else
					g[i][j] = '0';
					
			M--;
			g[0][n-1] = '1';
			for (int i=1; i<n; i++)
				if (M & (1 << (i-1)))
					g[i][n-1] = '1';
			
			cout << "POSSIBLE" << endl;
			
			for (int i=0; i<n; i++) {
				g[i][n] = '\0';
				cout << g[i] << endl;
			}
		}
	}
	
	return 0;
}
