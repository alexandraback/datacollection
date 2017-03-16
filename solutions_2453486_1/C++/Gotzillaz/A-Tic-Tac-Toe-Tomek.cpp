#include<cstdio>

char map[10][10];

//Number return
// 1 X won
// 2 O won
// 3 Draw
// 4 Game has not completed
// 5 Next Check

//Answer

bool ans(int caseN,int ret)
{
	if(ret==1)
	{
		printf("Case #%d: X won\n",caseN);
		return true;
	}
	else if(ret==2)
	{
		printf("Case #%d: O won\n",caseN);
		return true;
	}
	else if(ret==3)
	{
		printf("Case #%d: Draw\n",caseN);
		return true;
	}
	else if(ret==4)
	{
		printf("Case #%d: Game has not completed\n",caseN);
		return true;
	}
	else
	{
		return false;
	}
}

//Check Diagonal
int chkDiagonal()
{
	int x,o,dot,t;
	x=o=dot=t=0;
	for(int i=0;i<4;i++)
	{
		if(map[i][i]=='X')
			x++;
		else if(map[i][i]=='O')
			o++;
		else if(map[i][i]=='.')
			dot++;
		else if(map[i][i]=='T')
			t++;
	}
	if(x+t==4)
		return 1;
	else if(o+t==4)
		return 2;
	else 
	{
		x=o=dot=t=0;
		for(int i=0;i<4;i++)
		{
			if(map[i][3-i]=='X')
				x++;
			else if(map[i][3-i]=='O')
				o++;
			else if(map[i][3-i]=='.')
				dot++;
			else if(map[i][3-i]=='T')
				t++;
		}
		if(x+t==4)
			return 1;
		else if(o+t==4)
			return 2;
		else
			return 5;
	}
}

//Check row & col
int chkRnC()
{
	int x,o,dot,t;
	x=o=dot=t=0;
	//Row
	for(int i=0;i<4;i++)
	{	
		x=o=t=0;
		for(int j=0;j<4;j++)
		{
			if(map[i][j]=='X')
				x++;
			else if(map[i][j]=='O')
				o++;
			else if(map[i][j]=='.')
				dot++;
			else if(map[i][j]=='T')
				t++;
		}
		if(x+t==4)
			return 1;
		else if(o+t==4)
			return 2;
	}
	//x=o=dot=t=0;
	for(int i=0;i<4;i++)
	{	
		x=o=t=0;
		for(int j=0;j<4;j++)
		{
			if(map[j][i]=='X')
				x++;
			else if(map[j][i]=='O')
				o++;
			else if(map[j][i]=='.')
				dot++;
			else if(map[j][i]=='T')
				t++;
		}
		if(x+t==4)
			return 1;
		else if(o+t==4)
			return 2;
	}
	if(dot==0)
		return 3;
	else
		return 4;
}

int main()
{
	int testcase,tt=1;
	scanf("%d",&testcase);
	while(tt<=testcase)
	{
		for(int i=0;i<4;i++)
			scanf("%s",map[i]);
		if(ans(tt,chkDiagonal()))
		{
			tt++;
			continue;
		}
		if(ans(tt,chkRnC()))
		{
			tt++;
		}
		else
			tt++;
	}

}