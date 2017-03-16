#include <cstdio>
int main()
{
	static char in[6][6];
	int t, cnt = 0;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
		for(int i = 1; i <= 4; i++)
			scanf("%s", in[i] + 1);
		bool xwin = 0, owin = 0, empty = 0;
		for(int i = 1; i <= 4; i++)
		{
			int cntx = 0, cnto = 0, cntt = 0;
			for(int j = 1; j <= 4; j++)
				if(in[i][j] == 'X')
					cntx++;
				else if(in[i][j] == 'O')
					cnto++;
				else if(in[i][j] == 'T')
					cntt++;
				else
					empty = 1;
			if(cntx + cntt == 4)
				xwin = 1;
			if(cnto + cntt == 4)
				owin = 1;
		}
		for(int i = 1; i <= 4; i++)
		{
			int cntx = 0, cnto = 0, cntt = 0;
			for(int j = 1; j <= 4; j++)
				if(in[j][i] == 'X')
					cntx++;
				else if(in[j][i] == 'O')
					cnto++;
				else if(in[j][i] == 'T')
					cntt++;
			if(cntx + cntt == 4)
				xwin = 1;
			if(cnto + cntt == 4)
				owin = 1;
		}
		int cntx = 0, cnto = 0, cntt = 0;
		for(int i = 1; i <= 4; i++)
			if(in[i][i] == 'X')
				cntx++;
			else if(in[i][i] == 'O')
				cnto++;
			else if(in[i][i] == 'T')
				cntt++;
		if(cntx + cntt == 4)
			xwin = 1;
		if(cnto + cntt == 4)
			owin = 1;
		cntx = 0, cnto = 0, cntt = 0;
		for(int i = 1; i <= 4; i++)
			if(in[i][4 - i + 1] == 'X')
				cntx++;
			else if(in[i][4 - i + 1] == 'O')
				cnto++;
			else if(in[i][5 - i] == 'T')
				cntt++;
		if(cntx + cntt == 4)
			xwin = 1;
		if(cnto + cntt == 4)
			owin = 1;
		printf("Case #%d: ", ++cnt);
		if(xwin && owin)
		{
			puts("Draw");
			continue;
		}
		if(xwin)
		{
			puts("X won");
			continue;
		}
		if(owin)
		{
			puts("O won");
			continue;
		}
		if(empty)
		{
			puts("Game has not completed");
			continue;
		}
		puts("Draw");
	}
}
