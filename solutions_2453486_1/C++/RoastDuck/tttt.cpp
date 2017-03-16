#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T;
char map[7][7];

bool Is(char x, char c)
{
	return (x==c || x=='T');
}

bool win(char c)
{
	if (Is(map[1][1],c) && Is(map[1][2],c) && Is(map[1][3],c) && Is(map[1][4],c)) return true;
	if (Is(map[2][1],c) && Is(map[2][2],c) && Is(map[2][3],c) && Is(map[2][4],c)) return true;
	if (Is(map[3][1],c) && Is(map[3][2],c) && Is(map[3][3],c) && Is(map[3][4],c)) return true;
	if (Is(map[4][1],c) && Is(map[4][2],c) && Is(map[4][3],c) && Is(map[4][4],c)) return true;
	
	if (Is(map[1][1],c) && Is(map[2][1],c) && Is(map[3][1],c) && Is(map[4][1],c)) return true;
	if (Is(map[1][2],c) && Is(map[2][2],c) && Is(map[3][2],c) && Is(map[4][2],c)) return true;
	if (Is(map[1][3],c) && Is(map[2][3],c) && Is(map[3][3],c) && Is(map[4][3],c)) return true;
	if (Is(map[1][4],c) && Is(map[2][4],c) && Is(map[3][4],c) && Is(map[4][4],c)) return true;
	
	if (Is(map[1][1],c) && Is(map[2][2],c) && Is(map[3][3],c) && Is(map[4][4],c)) return true;
	if (Is(map[1][4],c) && Is(map[2][3],c) && Is(map[3][2],c) && Is(map[4][1],c)) return true;
	
	return false;
}

int main()
{
	freopen("tttt.in","r",stdin);
	freopen("tttt.out","w",stdout);
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		for (int i=1;i<=4;i++) scanf("%s",map[i]+1);
		if (win('X'))
		{
			printf("X won\n");
			continue;
		}
		if (win('O'))
		{
			printf("O won\n");
			continue;
		}
		
		bool draw(true);
		for (int i=1;i<=4;i++)
			for (int j=1;j<=4;j++)
				if (map[i][j]=='.')
				{
					draw=false;
					break;
				}
		if (draw)
			printf("Draw\n");
		else
			printf("Game has not completed\n");
	}
	return 0;
}

