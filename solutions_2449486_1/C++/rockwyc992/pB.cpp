/*************************************************************************
    > File Name: pB.cpp
    > Author: rockwyc992
    > Mail: rockwyc992@gmail.com 
    > Created Time: 2013年04月13日 (週六) 09時18分56秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

int T, n, m, flag;
char map[110][110];
char x[110], y[110];

int main()
{
	scanf("%d", &T);
	for(int t=1 ; t<=T ; t++)
	{
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		flag = 1;

		scanf("%d%d", &n, &m);
		for(int i=0 ; i<n ; i++)
			for(int j=0 ; j<m ; j++)
			{
				scanf("%d", &map[i][j]);
				if(map[i][j] > x[i])
					x[i] = map[i][j];
				if(map[i][j] > y[j])
					y[j] = map[i][j];
			}

		for(int i=0 ; i<n && flag ; i++)
			for(int j=0 ; j<m && flag ; j++)
				if(map[i][j] < x[i] && map[i][j] < y[j])
					flag = 0;

		printf("Case #%d: %s\n", t, flag ? "YES" : "NO");
	}
	return 0;
}

