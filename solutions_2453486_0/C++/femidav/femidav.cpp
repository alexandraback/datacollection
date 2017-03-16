// gcc version 4.6.1 (tdm-1)
// g++ -I tr1 femidav.cpp -O2 -Wall -std=c++0x -o femidav.exe
// femidav < small-attempt0.in > small-attempt0.out
// femidav < large.in > large.out

#include <cstdio>
#include <iostream>
#include <string>

#define FOR(I, N) for( int I = 0, end_ = (N); I < end_; ++I )
int rin() { int r; scanf( "%d\n", &r ); return r; }

int vars [10][4] = {
	{0,1,2,3}, {4,5,6,7}, {8,9,10,11}, {12,13,14,15},
	{0,4,8,12}, {1,5,9,13}, {2,6,10,14}, {3,7,11,15},
	{3,6,9,12}, {0,5,10,15}
};

char pl[2] = {'X', 'O'};

int main()
{
    FOR(i, rin())
    {
		char buf[17];
		FOR(j, 4)
			scanf("%4s", buf + j*4);

		char won = '.';
		for(int p = 0; p < 2 && won == '.'; ++p)
		{
			for(int v = 0; v < 10 && won == '.'; ++v)
			{
				int f = 0;
				for(; f < 4 && won == '.'; ++f)
					if (buf[vars[v][f]] != pl[p] && buf[vars[v][f]] != 'T')
						break;

				if (f == 4)
					won = pl[p];
			}
		}
		if (won != '.')
			printf("Case #%d: %c won\n", i + 1, won);
		else
		{
			bool draw = true;
			for(int f = 0; f < 16; ++f)
				if (buf[f] == '.') {draw = false; break;}

			printf("Case #%d: %s\n", i + 1, draw ? "Draw" : "Game has not completed");
		}
    }
}