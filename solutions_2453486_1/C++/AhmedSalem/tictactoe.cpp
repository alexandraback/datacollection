#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std ;


char grid[10][10];

bool isWinner(char ch)
{
	int ts,ps;
	for (int i=0;i<4;i++){
		ts=ps=0;
		for (int j=0;j<4;j++){
			ts+=grid[i][j]=='T';
			ps+=grid[i][j]==ch;
		}
		if (ps+ts == 4 && ts <= 1)return 1;
	}
	for (int j=0;j<4;j++){
		ts=ps=0;
		for (int i=0;i<4;i++){
			ts+=grid[i][j]=='T';
			ps+=grid[i][j]==ch;
		}
		if (ps+ts == 4 && ts <= 1)return 1;
	}
	ts=ps=0;
	for (int i=0,j=0;i<4;i++,j++){
		ts+=grid[i][j]=='T';
		ps+=grid[i][j]==ch;
	}
	if (ps+ts == 4 && ts <= 1)return 1;
	ts=ps=0;
	for (int i=0,j=3;i<4;i++,j--){
		ts+=grid[i][j]=='T';
		ps+=grid[i][j]==ch;
	}
	if (ps+ts == 4 && ts <= 1)return 1;
	return 0;
}

int main()
{
	freopen("tictactoe.in","r",stdin);
	freopen("tictactoe.out","w",stdout);
	int c,c2;
	int tests;
	scanf("%d",&tests);
	for (int test=1;test<=tests;test++){
		int empty=0;
		for (c=0;c<4;c++)
			for (c2=0;c2<4;c2++){
				scanf(" %c",&grid[c][c2]);
				empty+= (grid[c][c2] == '.');
			}
		printf("Case #%d: ",test);
		if (isWinner('X'))printf("X won\n");
		else if (isWinner('O'))printf("O won\n");
		else if (empty)printf("Game has not completed\n");
		else printf("Draw\n");
	}
	
	
	return 0;
}
