/*************************************************************************
    > File Name: pA.cpp
    > Author: rockwyc992
    > Mail: rockwyc992@gmail.com 
    > Created Time: 2013年04月13日 (週六) 07時54分59秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

char map[5][4];
int n, t;
char is_end;
char tmp_x, tmp_y;

inline int check()
{
	for(int i=0 ; i<4 ; i++)
	{
		if(map[i][0]=='.' || map[0][i]=='.')
			continue;
		if(map[i][0]==map[i][1] && map[i][0]==map[i][2] && map[i][0]==map[i][3])
		{
			printf("Case #%d: %c won\n",t, map[i][0]);
			return 1;
		}
		if(map[0][i]==map[1][i] && map[0][i]==map[2][i] && map[0][i]==map[3][i])
		{
			printf("Case #%d: %c won\n",t, map[0][i]);
			return 1;
		}
	}
	
	if(map[0][0]!='.' && map[0][0]==map[1][1] && map[0][0]==map[2][2] && map[0][0]==map[3][3])
	{
		printf("Case #%d: %c won\n",t, map[0][0]);
		return 1;
	}

	if(map[0][3]!='.' && map[0][3]==map[1][2] && map[0][3]==map[2][1] && map[0][3]==map[3][0])
	{
		printf("Case #%d: %c won\n",t, map[0][3]);
		return 1;
	}

	return 0;
}

int main()
{
	scanf("%d", &n);
	
	for(t=1 ; t<=n ; t++)
	{
		is_end = tmp_x = tmp_y = -1;

		for(int i=0 ; i<4 ; i++)
			scanf("%s", map[i]);
		for(int i=0 ; i<4 ; i++)
			for(int j=0 ; j<4 ; j++)
			{
				if(map[i][j] == '.')
					is_end = 1;
				if(map[i][j] == 'T')
					tmp_x = i, tmp_y = j;
			}

		if(tmp_x == -1)
		{
			if(check())
				continue;
		}
		else
		{
			map[tmp_x][tmp_y] = 'X';
			
			if(check())
				continue;

			map[tmp_x][tmp_y] = 'O';
			
			if(check())
				continue;
		}		
		printf("Case #%d: %s\n",t , is_end==-1 ? "Draw" : "Game has not completed");
	}

	return 0;
}


