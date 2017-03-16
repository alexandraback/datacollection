#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char grid[4][5];
void print()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			printf("%c",grid[i][j]);
		printf("\n");
	}
}
bool check(char c)
{
	bool flag=true;
	if(c=='X')
		c='O';
	else
		c='X';
	for(int i=0;i<4;i++)
	{
		flag=true;
		for(int j=0;j<4;j++)
		{
			if(grid[i][j]==c||grid[i][j]=='.')
			{
				flag=false;
				break;
                                  
			}
		}
		if(flag==true)
		{
	//		printf("i m row wise %d \n",i);
			return true;
		}

			
	}
	for(int j=0;j<4;j++)
	{
		flag=true;
		for(int i=0;i<4;i++)
		{
	//		printf("c=%c ",grid[i][j]);
			if(grid[i][j]==c||grid[i][j]=='.')
			{
				flag=false;
				break;
			}
	//		printf("hi");

		}
		if(flag)
		{
	//	printf("i m col wise %d \n",j);
		return true;
		}
	}
	flag=true;
	for(int i=0;i<4;i++)
		if(grid[i][i]==c||grid[i][i]=='.')
			flag=false;
	if(flag)
	{
	//	printf("i m left->right cross\n");
		return flag;
	}
	flag=true;
	for(int i=0,j=3;i<4;i++,j--)
		if(grid[i][j]==c||grid[i][j]=='.')
			flag=false;
	//printf("i m right->left cross\n");
	return flag;
}
bool dot_check()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(grid[i][j]=='.')
				return true;
return false;
}
int main()
{
	int tc,t_r,t_c,pp=1,ppp;
	scanf("%d",&tc);
	ppp=tc;
	char c;
	scanf("%c",&c);
//	char c=getchar();
	while(tc--)
	{
		/*scanf("%s",grid[0][0]);
		scanf("%s",grid[1][0]);
		scanf("%s",grid[2][0]);
		scanf("%s",grid[3][0]);*/
		for(int i=0;i<4;i++)
			for(int j=0;j<5;j++)
			{
				scanf("%c",&c);
//				printf("c==%d ",c);
				grid[i][j]=c;

			}
	//	print();		
		if(check('X'))
			printf("Case #%d: X won\n",pp);
		else if(check('O'))
			printf("Case #%d: O won\n",pp);
		else if(dot_check())
			printf("Case #%d: Game has not completed\n",pp);
		else
			printf("Case #%d: Draw\n",pp);
		pp++;
		if(ppp<pp)
			break;
		scanf("%c",&c);
	
	
 	}


return 0;
}
