#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

char data[7][7];

inline void Init()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
}

bool func(char ch)
{
	int i,j,x,y;

	for(i=0;i<4;i++)
	{
		x = 0;
		y = 0;
		for(j=0;j<4;j++)
		{
			if(data[i][j]==ch)
				x++;
			if(data[i][j]=='T')
				y++;
		}
		if(x==4 || (x==3 && y==1))
			return true;
	}

	for(i=0;i<4;i++)
	{
		x = 0;
		y = 0;
		for(j=0;j<4;j++)
		{
			if(data[j][i]==ch)
				x++;
			if(data[j][i]=='T')
				y++;
		}
		if(x==4 || (x==3 && y==1))
			return true;
	}
	
	x = 0;
	y = 0;
	for(i=0;i<4;i++)
	{
		if(data[i][i]==ch)
			x++;
		if(data[i][i]=='T')
			y++;
	}
	if(x==4 || (x==3 && y==1))
		return true;

	x = 0;
	y = 0;
	for(i=0;i<4;i++)
	{
		if(data[i][3-i]==ch)
			x++;
		if(data[i][3-i]=='T')
			y++;
	}
	if(x==4 || (x==3 && y==1))
		return true;

	return false;
}

int main(void)
{
	Init();
	int i,j,T,cases;
	scanf("%d",&cases);
	for(T=1;T<=cases;T++)
	{
		for(i=0;i<4;i++)
		{
			scanf("%s",data[i]);
		}
		printf("Case #%d: ",T);
		if(func('X')==true)
		{
			printf("X won\n");
		}
		else if(func('O')==true)
		{
			printf("O won\n");
		}
		else
		{
			int state = 0;
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(data[i][j]=='.')
					{
						state = 1;
						break;
					}
				}
			}
			if(state==0)
				printf("Draw\n");
			else
				printf("Game has not completed\n");
		}
	}
	return 0;
}