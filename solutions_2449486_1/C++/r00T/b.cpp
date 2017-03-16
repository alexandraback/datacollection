#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<deque>
#include<queue>
#include<map>
using namespace std;

typedef long long int L;
typedef unsigned long long int U;

int arr[105][105];
int row[105];
int col[105];
main()
{
	int tc;
	scanf("%d", &tc);
	for(int t = 1;t<=tc;t++)
	{
		int m,n;
		scanf("%d %d", &m, &n);
		for(int i = 0;i<m;i++)
			row[i] = 0;
		for(int i = 0;i<n;i++)
			col[i] = 0;
		for(int i = 0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
				scanf("%d", &arr[i][j]);
		}
		for(int i =0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				row[i] = max(row[i], arr[i][j]);
				col[j] = max(col[j], arr[i][j]);
			}
		}
		bool poss = 1;
		for(int i = 0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				if((arr[i][j] != row[i]) && (arr[i][j] < col[j]))
					poss = 0;
			}
		}
		
		if(poss)
			printf("Case #%d: YES\n",t);
		else
			printf("Case #%d: NO\n",t);
	}
}
