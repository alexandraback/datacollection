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

int n, E, R, v[10100], f[10][100];
pair <int,int> a[10100];

int main()
{
	freopen("bsmall3.in", "r", stdin); 
	freopen("bsmall3.out", "w", stdout);
	
	int test;
	cin >> test;
	for (int itest = 1; itest <= test; itest++)
	{
		cin >> E >> R >> n;
		for (int i = 0; i < n; i++) cin >> v[i];
		memset(f, 0, sizeof(f));
		
		int ans = 0;
		if (R >= E)
			for (int i = 0; i < n; i++) ans += v[i] * E;
		else
		{
			for (int j = R; j <= E; j++) f[0][min(E - j + R, E)] = j * v[0];
			for (int i = 1; i < n; i++)
				for (int j = R; j <= E; j++)
					for (int k = 0; k <= j; k++)
						f[i][min(E, j - k + R)] = max(f[i][min(E, j - k + R)], f[i - 1][j] + k * v[i]);
						
			ans = f[n - 1][R];
		}
		printf("Case #%d:", itest);
		cout << ' ' << ans << endl;
	}
}
