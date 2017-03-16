#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

/**
 * Solves Google Codejam "Minesweeper Master"
 * Because sometimes you just have to rewrite the whole damn thing in C to get it right.
 * 	Although it's probably still wrong.
 * http://code.google.com/codejam
 * Sam Moore (matches)
 * 2014-04-11
 */

void SolveBoard(char ** board, int W, int H, int x, int y)
{
	char c;
	int xx;
	int yy;

	int count = 0;

	for (xx = x-1; xx <= x+1; ++xx)
	{
		if (xx < 0 || xx >= W)
			continue;
		for (yy = y-1; yy <= y+1; ++yy)
		{
			if ((yy == y && xx == x) || yy < 0 || yy >= H)
				continue;

			//printf("%d,%d | %d,%d\n", xx, yy, W, H);
			if (board[xx][yy] == '*')
			{
				count += 1;
			}				
		}
	}
	
	board[x][y] = (count == 0) ? '.' : '0'+count;
	if (count == 0)
	{
		for (xx = x-1; xx <= x+1; ++xx)
		{
			if (xx < 0 || xx >= W)
				continue;
			for (yy = y-1; yy <= y+1; ++yy)
			{
				if ((yy == y && xx == x) || yy < 0 || yy >= H)
					continue;
				if (board[xx][yy] == '?')
					SolveBoard(board, W, H, xx, yy);
			}
		}		
	}

}

void ResetBoard(char ** board, int W, int H)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < W; ++x)
	{
		for (y = 0; y < H; ++y)
		{
			char c = board[x][y];
			board[x][y] = (c == '*') ? c : '?';
		}
	}
}

bool BoardIsSolved(char ** board, int W, int H)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < W; ++x)
	{
		for (y = 0; y < H; ++y)
		{
			if (board[x][y] == '?')
				return false;
		}
	}
	return true;
}

void ReduceBoard(int * M, int * W, int * H)
{
	while (*M > 1)
	{
		int Mm = *M;
		if (*M >= *H && *W > 2)
		{
			*M -= *H;
			*W -= 1;
		}
		if (*M >= *W && *H > 2)
		{
			*M -= *W;
			*H -= 1;
		}
		if (Mm == *M)
			break;
	}
}

int main(int argc, char ** argv)
{
	setbuf(stdin, NULL); setbuf(stdout, NULL);
	int cases;
	int R, C, M;
	char buf[BUFSIZ];
	fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "%d\n", &cases);

	int c = 1;
	for (c = 1; c <= cases; ++c)
	{
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%d %d %d\n", &R, &C, &M);

		int W = C;
		int H = R;
		int Mo = M;
		bool transp = W > H;
		if (transp)
		{
			W = R;
			H = C;
			R = C;
			C = W;
		}

		// Decrease size of board
		int Ma = M; int Wa = W; int Ha = H;
		int Mb = M; int Wb = W; int Hb = H;
		ReduceBoard(&Ma, &Wa, &Ha);
		ReduceBoard(&Mb, &Hb, &Wb);

		if (Ma <= Mb)
		{
			M = Ma;	W = Wa; H = Ha;
		}
		else
		{
			M = Mb;	W = Wb; H = Hb;
		}
		


		printf("Case #%d:\n",c); // %d %d %d => %d %d %d transposed = %d\n", c, R, C, Mo, W, H, M, transp);


		char ** board = malloc(C * sizeof(char*));
		int x = 0;
		int y = 0;
		for (x = 0; x < C; ++x)
		{
			board[x] = malloc(R * sizeof(char)); 
			for (y = 0; y < R; ++y)
			{
				board[x][y] = (x < W && y < H) ? '?' : '*';
			}
		}
		
		int Mleft = M;
		// Try and fill in the remaining mines
		x = W-1;
		y = H-1;
		while (M > 0 && x >= 0 && y >= 0)
		{
			board[x][y] = '*';
			--M;
			if (y > 2)
			{
				--y;
			}
			else if (x > 2)
			{
				--x;
				y = H-1;
			}
			else
			{
				--y;
				if (y < 0)
				{
					y = H-1;
					--x;
				}
			}
			
		}

		SolveBoard(board, C,R,0,0);
		board[0][0] = 'c';

		
		bool solved = (BoardIsSolved(board, C,R) && M == 0);
		

		FILE * output = stdout;
		if (!solved)
		{
			printf("Impossible\n");
			output = stderr;
			fprintf(output, "Case #%d (R,C,M = %d %d %d => W,H,M = %d %d %d):\n", c, R, C, Mo, W, H, Mleft);
		}
		//else
		{
			W = (transp) ? R : C;
			H = (transp) ? C : R;
			M = 0;
			for (y = 0; y < H; ++y)
			{
				for (x = 0; x < W; ++x)
				{
					char o = '?';
					if (transp)
						o = board[y][x];						
					else
						o = board[x][y];
					if (o == '*')
						M++;
					else
						o = (o != '?') ? '.' : o;
					o = (x+y == 0 && o == '.') ? 'c' : o;
					fprintf(output,"%c",o);
				}
				fprintf(output,"\n");
			}
			if (solved && M != Mo)
			{
				fprintf(stderr,"Mismatch in mine number on Case #%d (R,C,M = %d %d %d => W,H,M = %d %d %d):\n", c, R, C, Mo, W, H, M);
				exit(EXIT_FAILURE);
			}
		}

		for (x = 0; x < C; ++x)
		{
			free(board[x]);
		}
		free(board);

	}
}
