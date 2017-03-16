#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <deque>
#include <stack>
typedef long long ll;
using namespace std;
char mp[5][5];
int main(){
	int tt,cas=1;
	scanf("%d",&tt);
	while (tt--)
	{
		for (int i=0;i<4;i++)
		{
			for (int j=0;j<4;j++)
			{
				scanf(" %c ",&mp[i][j]);
			}
		}
		int res=0;
		int j;
		for (int i=0;i<4;i++)
		{
			for (j=0;j<4;j++)
			{
				if (!(mp[i][j]=='X'||mp[i][j]=='T'))
				{
					break;
				}
			}
			if (j==4)
			{
				res=1;
			}
			for (j=0;j<4;j++)
			{
				if (!(mp[i][j]=='O'||mp[i][j]=='T'))
				{
					break;
				}
			}
			if (j==4)
			{
				res=2;
			}
		}
		for (int i=0;i<4;i++)
		{
			for (j=0;j<4;j++)
			{
				if (!(mp[j][i]=='X'||mp[j][i]=='T'))
				{
					break;
				}
			}
			if (j==4)
			{
				res=1;
			}
			for (j=0;j<4;j++)
			{
				if (!(mp[j][i]=='O'||mp[j][i]=='T'))
				{
					break;
				}
			}
			if (j==4)
			{
				res=2;
			}
		}
		for (j=0;j<4;j++)
		{
			if (!(mp[j][j]=='X'||mp[j][j]=='T'))
			{
				break;
			}
		}
		if (j==4)
		{
			res=1;
		}
		for (j=0;j<4;j++)
		{
			if (!(mp[j][j]=='O'||mp[j][j]=='T'))
			{
				break;
			}
		}
		if (j==4)
		{
			res=2;
		}
		for (j=0;j<4;j++)
		{
			if (!(mp[j][3-j]=='X'||mp[j][3-j]=='T'))
			{
				break;
			}
		}
		if (j==4)
		{
			res=1;
		}
		for (j=0;j<4;j++)
		{
			if (!(mp[j][3-j]=='O'||mp[j][3-j]=='T'))
			{
				break;
			}
		}
		if (j==4)
		{
			res=2;
		}
		if (res==0)
		{
			for (int i=0;i<4;i++)
			{
				for (j=0;j<4;j++)
				{
					if (mp[i][j]=='.')
					{
						res=-1;
					}
				}
			}
		}
		printf("Case #%d: ",cas++);
		switch(res){
			case -1:printf("Game has not completed");break;
			case 0:printf("Draw");break;
			case 1:printf("X won");break;
			case 2:printf("O won");break;
		}
		printf("\n");
	}
	return 0;
}