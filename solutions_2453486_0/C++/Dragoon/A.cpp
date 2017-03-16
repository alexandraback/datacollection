#include<stdio.h>

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int T, ks, i, j, dot, x, o;
	char word[10][10];

	scanf("%d", &T);
	for(ks = 1; ks <= T; ks++)
	{
		for(i = 0; i < 4; i++)
			scanf("%s", word[i]);

		dot = 0;
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
				dot |= word[i][j]=='.';

		x = o = 0;
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 4; j++)
				if(word[i][j]=='O' || word[i][j]=='.')
					break;

			x |= (j == 4);

			for(j = 0; j < 4; j++)
				if(word[i][j]=='X' || word[i][j]=='.')
					break;

			o |= (j == 4);

			for(j = 0; j < 4; j++)
				if(word[j][i]=='O' || word[j][i]=='.')
					break;

			x |= (j == 4);

			for(j = 0; j < 4; j++)
				if(word[j][i]=='X' || word[j][i]=='.')
					break;

			o |= (j == 4);
		}

		for(j = 0; j < 4; j++)
			if(word[j][j]=='O' || word[j][j]=='.')
				break;

		x |= (j==4);

		for(j = 0; j < 4; j++)
			if(word[j][j]=='X' || word[j][j]=='.')
				break;

		o |= (j==4);

		for(j = 0; j < 4; j++)
			if(word[3-j][j]=='O' || word[3-j][j]=='.')
				break;

		x |= (j==4);

		for(j = 0; j < 4; j++)
			if(word[3-j][j]=='X' || word[3-j][j]=='.')
				break;

		o |= (j==4);

		printf("Case #%d: ", ks);
		if(x) printf("X won\n");
		else if(o) printf("O won\n");
		else if(!dot) printf("Draw\n");
		else printf("Game has not completed\n");
	}

	return 0;
}