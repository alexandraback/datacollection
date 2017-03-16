
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<cstdlib>
#include<string>
#include<set>
using namespace std;

#define MAX 10

char grid[MAX][MAX];

int check(char x)
{
	for(int i=0;i<4;i++)
	{
		int j;
		for(j=0;j<4;j++)
			if(grid[i][j]!=x&&grid[i][j]!='T')
				break;
		if(j==4)
			return 1;
	}
	for(int j=0;j<4;j++)
	{
		int i;
		for(i=0;i<4;i++)
			if(grid[i][j]!=x&&grid[i][j]!='T')
				break;
		if(i==4)
			return 1;
	}
	int i;
	for( i=0;i<4;i++)
		if(grid[i][i]!=x&&grid[i][i]!='T')
			break;
	if(i==4)
		return 1;
	for(i=0;i<4;i++)
		if(grid[i][3-i]!=x&&grid[i][3-i]!='T')
			break;
	if(i==4)
		return 1;
	return 0;
}

int main()
{
 //   freopen("A-small-attempt0.in","r",stdin);
   // freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int cas=0;cas<t;cas++)
	{
		int i,j;
		for(i=0;i<4;i++)
			scanf(" %s",grid[i]);
		if(check('X'))
			printf("Case #%d: X won\n",cas+1);
		else if(check('O'))
			printf("Case #%d: O won\n",cas+1);
		else
		{
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
					if(grid[i][j]=='.')
						break;
				if(j!=4)
				{
					printf("Case #%d: Game has not completed\n",cas+1);
					break;
				}
			}
			if(i==4)
				printf("Case #%d: Draw\n",cas+1);
		}
	}
    return 0;
}
