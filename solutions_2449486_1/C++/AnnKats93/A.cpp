#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[105][105];
int colx[105];
int coly[105];

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int t;
	scanf("%d", &t);

	for(int tt = 0; tt < t; tt++) 
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
	
		for(int i = 0; i < n; i++)
		{
			coly[i] = a[i][0]; 
			for(int j = 0; j < m; j++)
				coly[i] = max(coly[i], a[i][j]);
		}
		for(int i = 0; i < m; i++)
		{
			colx[i] = a[0][i]; 
			for(int j = 0; j < n; j++)
				colx[i] = max(colx[i], a[j][i]);
		}
		bool fo = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(a[i][j] != coly[i] && a[i][j] != colx[j])
					fo = 1;
		
		if(fo)
			printf("Case #%d: NO\n", tt + 1);
		else
			printf("Case #%d: YES\n", tt + 1);
	}

	return 0;
}