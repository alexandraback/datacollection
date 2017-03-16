#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;


int main()
{
	int i, j, T, t, N, M;
	int grass[100][100];
	int maxline[100];
	int maxcol[100];
	bool ok;
	
	scanf("%d\n", &T);
	
	for(t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		scanf("%d %d\n", &N, &M);
		
		for(i = 0; i < N; i++) maxline[i] = -1;
		for(j = 0; j < M; j++) maxcol[j] = -1;
		
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < M; j++)
			{
				scanf("%d", &grass[i][j]);
				if(grass[i][j] > maxline[i]) maxline[i] = grass[i][j];
				if(grass[i][j] > maxcol[j]) maxcol[j] = grass[i][j];
			}
		}
		ok = true;
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < M; j++)
			{
				if(grass[i][j] < maxline[i] && grass[i][j] < maxcol[j])
				{
				 	ok = false;
				}
			}
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
