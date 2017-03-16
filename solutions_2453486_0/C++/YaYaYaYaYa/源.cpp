#include <iostream>
using namespace std;

#define isOT(x) (((x) == 'T') || ((x) == 'O'))
#define isXT(x) (((x) == 'T') || ((x) == 'X'))

int main()
{
	int n;
	char map[10][10];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		gets(map[0]);
		char winner = 0;
		gets(map[0]);
		gets(map[1]);
		gets(map[2]);
		gets(map[3]);
		for (int j = 0; j < 4; ++j)
		{
			if ((isOT(map[j][0]) && isOT(map[j][1]) && isOT(map[j][2]) && isOT(map[j][3])) || (isOT(map[0][j]) && isOT(map[1][j]) && isOT(map[2][j]) && isOT(map[3][j])))
			{
				winner = 'O';
				break;
			}
			if ((isXT(map[j][0]) && isXT(map[j][1]) && isXT(map[j][2]) && isXT(map[j][3])) || (isXT(map[0][j]) && isXT(map[1][j]) && isXT(map[2][j]) && isXT(map[3][j])))
			{
				winner = 'X';
				break;
			}
		}
		if (winner == 0)
		{
			if ((isOT(map[0][0]) && isOT(map[1][1]) && isOT(map[2][2]) && isOT(map[3][3])) || (isOT(map[0][3]) && isOT(map[1][2]) && isOT(map[2][1]) && isOT(map[3][0])))
			{
				winner = 'O';
			}
			if ((isXT(map[0][0]) && isXT(map[1][1]) && isXT(map[2][2]) && isXT(map[3][3])) || (isXT(map[0][3]) && isXT(map[1][2]) && isXT(map[2][1]) && isXT(map[3][0])))
			{
				winner = 'X';
			}
		}
		if (winner == 0)
		{
			for (int j = 0; j < 4; ++j)
				for (int k = 0; k < 4; ++k)
					if (map[j][k] == '.')
						winner = 'N';
		}
		switch (winner)
		{
		case 'X':
			printf("Case #%d: X won\n", i);
			break;
		case 'O':
			printf("Case #%d: O won\n", i);
			break;
		case 'N':
			printf("Case #%d: Game has not completed\n", i);
			break;
		default:
			printf("Case #%d: Draw\n", i);
			break;
		}
	}
}