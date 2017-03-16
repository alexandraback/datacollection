# include <cstdio>

char inp[4][5];

int work(int x,int y,int dx,int dy)
{
	int cntX=0,cntO=0,cntT=0;
	for(int i=0;i<4;i++)
	{
		if(inp[x+i*dx][y+i*dy]=='X')cntX++;
		else if(inp[x+i*dx][y+i*dy]=='O')cntO++;
		else if(inp[x+i*dx][y+i*dy]=='T')cntT++;
		else return 0;
	}
	if(cntX+cntT==4)return 1;
	else if(cntO+cntT==4)return -1;
	else return 0;
}

bool gameover()
{
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
		if(inp[i][j]=='.')return false;
	return true;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		for(int i=0;i<4;i++)
			scanf("%s",inp[i]);

		int winstate=0;
		for(int i=0;i<4;i++)
			winstate+=work(0,i,1,0)+work(i,0,0,1);
		winstate+=work(0,0,1,1)+work(0,3,1,-1);

		printf("Case #%d: ",t);
		if(winstate>0)printf("X won\n");
		else if(winstate<0)printf("O won\n");
		else if(gameover())printf("Draw\n");
		else printf("Game has not completed\n");
	}
	return 0;
}
