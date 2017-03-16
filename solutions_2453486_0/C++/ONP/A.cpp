#include <cstdio>
#include <cstring>
#include <cstdlib>

const int dx[] = {1,1,1,0,-1,-1,-1,0};
const int dy[] = {1,0,-1,1,1,0,-1,-1};

char s[10][10];

int main()
{
	int T, caseNum = 1;
	for (scanf("%d", &T);T --;)
	{
		for (int i = 0; i < 4; ++ i)
		{
			scanf("%s",s[i]);
		}
		
		int empty = 0;
		bool win_o = false, win_x = false;
		for (int i = 0; i < 4; ++ i)
		{
			for (int j = 0; j < 4; ++ j)
			{
				empty += s[i][j] == '.';
				if (s[i][j] == 'O' || s[i][j] == 'X')
				{
					for (int k = 0; k < 8; ++ k)
					{
						int x = i, y = j;
						int length = 0, numberT = 0;
						while (x >= 0 && y >= 0 && x < 4 && y < 4 && (s[x][y] == 'T' || s[x][y] == s[i][j]))
						{
							++ length;
							if (s[x][y] == 'T')
							{
								++ numberT;
							}
							x += dx[k];
							y += dy[k];
						}
						if (length == 4 && numberT <= 1)
						{
							if (s[i][j] == 'O')
							{
								win_o = true;
							}else if (s[i][j] == 'X')
							{
								win_x = true;
							}
						}
					}
				}
			}
		}
		printf("Case #%d: ",caseNum++);
		if (win_o)
		{
			puts("O won");
		}else if (win_x)
		{
			puts("X won");
		}else if (empty > 0)
		{
			puts("Game has not completed");
		}else
		{
			puts("Draw");
		}
	}
	return 0;
}
