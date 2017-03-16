#pragma comment(linker, "/STACK:500000000")
#include <functional>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <ctype.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#define Int long long
#define inf 0x3f3f3f3f
#define eps 1e-9
using namespace std;
#define N 105

int A[N][N], B[N][N];

int main()
{
	freopen("i.txt", "rt", stdin);
	freopen("o.txt", "wt", stdout);
	int t, i, j, tt = 0, n, m;
	cin >> t;
	while(t--)
	{
		tt++;
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				scanf("%d", &A[i][j]), B[i][j] = 100;
		for(i = 0; i < n; i++)
		{
			int maxV = *max_element(A[i], A[i] + m);
			for(j = 0; j < m; j++)
			{
				if(B[i][j] > A[i][j])
					B[i][j] = maxV;
			}
			for(j = 0; j < m; j++)
				if(B[i][j] > A[i][j])
				{
					for(int ii = 0; ii < n; ii++)
						if(B[ii][j] > A[i][j])
							B[ii][j] = A[i][j];
				}
		}
		bool ok = true;
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				if(A[i][j] != B[i][j])
					ok = false;
		printf("Case #%d: ", tt);
		if(ok)
			puts("YES");
		else
			puts("NO");
	}
}  