#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define UNINIT -1
#define DRAW 0
#define XWON 1
#define OWON 2
#define GAMENOTCOMPLETED 3

char table[4][4];
int T;
int case_i;

bool game_ended()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (table[i][j] == '.')
				return false;
		}
	}
	return true;
}

int who_won_line(char text[4])
{
	int won = UNINIT;
	for (int i = 0; i < 4; ++i)
	{
		if (text[i] == 'X' && won == UNINIT)
		{
			won = XWON;
		} 
		else if (text[i] == 'X' && won == OWON) 
		{
			return DRAW;
		}

		if (text[i] == 'O' && won == UNINIT)
		{
			won = OWON;
		} 
		else if (text[i] == 'O' && won == XWON) 
		{
			return DRAW;
		}

		if (text[i] == '.')
		{
			won = DRAW;
		}
	}
	return won;
}

int who_won()
{
	int won = DRAW;
	for (int i = 0; i < 4; ++i) 
	{
		char s[4];
		s[0] = table[i][0];
		s[1] = table[i][1];
		s[2] = table[i][2];
		s[3] = table[i][3];
		int r = who_won_line(s);
		if (r != DRAW)
			return r;
	}

	for (int i = 0; i < 4; ++i) 
	{
		char s[4];
		s[0] = table[0][i];
		s[1] = table[1][i];
		s[2] = table[2][i];
		s[3] = table[3][i];
		int r = who_won_line(s);
		if (r != DRAW)
			return r;
	}

	char s[4];
	s[0] = table[0][0];
	s[1] = table[1][1];
	s[2] = table[2][2];
	s[3] = table[3][3];
	int r = who_won_line(s);
	if (r != DRAW)
		return r;

	s[0] = table[0][3];
	s[1] = table[1][2];
	s[2] = table[2][1];
	s[3] = table[3][0];
	r = who_won_line(s);
	if (r != DRAW)
		return r;

	if (!game_ended())
		return GAMENOTCOMPLETED;

	return DRAW;
}

void do_case() 
{
	int r = who_won();
	if (r == DRAW) 
	{
		printf("Case #%d: Draw\n", case_i);
	} 
	else if (r == GAMENOTCOMPLETED)
	{
		printf("Case #%d: Game has not completed\n", case_i);
	} 
	else if (r == XWON)
	{
		printf("Case #%d: X won\n", case_i);
	} 
	else if (r == OWON)
	{
		printf("Case #%d: O won\n", case_i);
	}
}

int main() 
{
	cin >> T;
	for (case_i = 1; case_i <= T; ++case_i)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				char c;
				cin >> c;
				while (c != 'X' && c != '.' && c != 'O' && c != 'T')
					cin >> c;

				table[i][j] = c;
			//	printf("%c", c);
			}
		//	printf("\n");
		}

		do_case();
	}

	return 0;
}