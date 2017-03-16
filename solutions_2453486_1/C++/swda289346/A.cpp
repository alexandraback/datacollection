#include <stdio.h>

int main()
{
	int t;
	char map[4][5];
	bool xWin, oWin, empty;
	scanf("%d", &t);
	for (int i=1;i<=t;++i)
	{
		xWin = oWin = empty = false;
		for (int j=0;j<4;++j)
			scanf("%s", map[j]);
		for (int j=0;j<4;++j)
			for (int k=0;k<4;++k)
			{
				if (map[j][k]=='T')
					continue;
				if (map[j][k]=='.')
				{
					empty = true;
					continue;
				}
				bool &userWin = map[j][k]=='X'?xWin:oWin;
				bool tWin = true;
				for (int l=0;l<4;++l)
					if (map[l][k]==map[j][k] || map[l][k]=='T')
						;
					else
						tWin = false;
				if (tWin)
					userWin = true;
				tWin = true;
				for (int l=0;l<4;++l)
					if (map[j][l]==map[j][k] || map[j][l]=='T')
						;
					else
						tWin = false;
				if (tWin)
					userWin = true;
				if (j==k)
				{
					tWin = true;
					for (int l=0;l<4;++l)
						if (map[l][l]==map[j][k] || map[l][l]=='T')
							;
						else
							tWin = false;
					if (tWin)
						userWin = true;
				}
				if (j+k==3)
				{
					tWin = true;
					for (int l=0;l<4;++l)
						if (map[l][3-l]==map[j][k] || map[l][3-l]=='T')
							;
						else
							tWin = false;
					if (tWin)
						userWin = true;
				}
			}
		printf("Case #%d: ", i);
		if (xWin)
			printf("X won");
		else if (oWin)
			printf("O won");
		else if (!empty)
			printf("Draw");
		else
			printf("Game has not completed");
		printf("\n");
	}
	return 0;
}
