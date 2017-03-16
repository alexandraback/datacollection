#include <stdio.h>
char mp[6][6];

int ck(char ch)
{
	for (int i = 0; i < 4; ++i)
	{
		bool win = true;
		for (int j = 0; j < 4; ++j)
		{
			if ((mp[i][j] != ch) && (mp[i][j] != 'T'))
			{
				win = false;
				break;
			}
		}
		if (win == true)
			return true;
	}

	for (int i = 0; i < 4; ++i)
	{
		bool win = true;
		for (int j = 0; j < 4; ++j)
		{
			if ((mp[j][i] != ch) && (mp[j][i] != 'T'))
			{
				win = false;
				break;
			}
		}
		if (win == true)
			return true;
	}

	bool win = true;
	for (int j = 0; j < 4; ++j)
	{
		if ((mp[j][j] != ch) && (mp[j][j] != 'T'))
		{
			win = false;
			break;
		}
	}
	if (win == true)
		return true;

	win = true;
	for (int j = 0; j < 4; ++j)
	{
		if ((mp[3-j][j] != ch) && (mp[3-j][j] != 'T'))
		{
			win = false;
			break;
		}
	}
	if (win == true)
		return true;

	return false;
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	int nt = 0;
	while(T--)
	{
		for (int i = 0; i < 4; ++i)
			scanf("%s", mp[i]);

		if (ck('O'))
			printf("Case #%d: O won\n", ++nt);
		else if(ck('X'))
			printf("Case #%d: X won\n", ++nt);
		else
		{	
			bool over = true;
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					if (mp[i][j] == '.')
					{
						over = false;
						i = 10;
						break;
					}
			if (over == false)
				printf("Case #%d: Game has not completed\n", ++nt);
			else
				printf("Case #%d: Draw\n", ++nt);
		}
	}
	return 0;
}