#include <stdio.h>

char map[4][5];

int check(char ch)
{
	int i, j;
	int flag;
	for (i = 0; i < 4; i++)
	{
		flag = 1;
		for (j = 0; j < 4; j++)
			if (map[i][j] != ch && map[i][j] != 'T')
				flag = 0;
		if (flag) return flag;
		flag = 1;
		for (j = 0; j < 4; j++)
			if (map[j][i] != ch && map[j][i] != 'T')
				flag = 0;
		if (flag) return flag;
	}
	flag = 1;
	for (i = 0; i < 4; i++)
		if (map[i][i] != ch && map[i][i] != 'T')
			flag = 0;
	if (flag) return flag;
	flag = 1;
	for (i = 0; i < 4; i++)
		if (map[i][3-i] != ch && map[i][3-i] != 'T')
			flag = 0;
	return flag;
} 

int main()
{
	int t, i, j, empty, cnt = 1;

	scanf("%d", &t);
	getchar();
	while (t--)
	{
		for (i = 0; i < 4; i++)
			gets(map[i]);
		getchar();

//		for (i = 0; i < 4; i++)
//			puts(map[i]);

		empty = 0;
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				if (map[i][j] == '.')
					empty++;
		
		printf("Case #%d: ", cnt++);
		if (check('X'))
			puts("X won");
		else if (check('O'))
			puts("O won");
		else if (empty == 0)
			puts("Draw");
		else
			puts("Game has not completed");
	}
	return 0;
}
