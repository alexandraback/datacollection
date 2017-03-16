#include<cstdio>
#include<cstring>

char map[8][8];

bool CheckWin(char ch)
{
	int i, j, k;
	bool ok3 = true;
	bool ok4 = true;
	
	for(i = 0; i < 4; i ++)
	{
		bool ok1 = true;
		bool ok2 = true;
		
		for(j = 0; j < 4; j ++)
		{
			if(map[i][j] != ch && map[i][j] != 'T')ok1 = false;
			if(map[j][i] != ch && map[j][i] != 'T')ok2 = false;
		}
		if(ok1 || ok2)return true;
		if(map[i][i] != ch && map[i][i] != 'T')ok3 = false;
		if(map[i][3-i] != ch && map[i][3-i] != 'T')ok4 = false;
	}
	return (ok3 || ok4);
}

bool CheckDraw()
{
	int i, j, k;
	for(i = 0; i < 4; i ++)
	{
		for(j = 0; j < 4; j ++)
		{
			if(map[i][j] == '.')return false;
		}
	}
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	
	int Case;
	for(Case = 1;  Case <= T; Case ++)
	{
		char Ans[32];
		int i, j, k;
		for(i = 0; i < 4; i ++)
		{
			scanf("%s", map[i]);
		}
		if(CheckWin('X'))
		{
			strcpy(Ans, "X won");
		}
		else if(CheckWin('O'))
		{
			strcpy(Ans, "O won");
		}
		else if(CheckDraw())
		{
			strcpy(Ans, "Draw");
		}
		else 
		{
			strcpy(Ans, "Game has not completed");
		}
		
		printf("Case #%d: %s\n", Case, Ans);
	}
	return 0;
}
