#include "stdafx.h"

void SovleC(char * input)
{
	TRACE("started...");
	Int n; READ(n); NL;
	for (Int i = 0; i < n; i++)
	{
		PRINT("Case #%I64d:\n", i + 1);
		Int R,C,M;
		READ(R);READ(C);READ(M);NL;
		if (R * C == M + 1)
		{
			for (Int y = 0; y < R; y++)
			{
				for(Int x =0; x < C; x++)
				{
					if (x == 0 && y==0) PRINT("c");
					else PRINT("*");
				}
				PRINT("\n");
			}
			continue;
		}
		if (R == 1 || C == 1) {
			Int empty = R * C - M - 1;
			for (Int y = 0; y < R; y++)
			{
				for(Int x = 0; x < C; x++)
				{
					if (x == 0 && y==0) PRINT("c");
					else if (empty-- > 0)
					{
						PRINT(".");
					}
					else 
						PRINT("*");
				}
				PRINT("\n");
			}
			continue;
		}
		Int free = R * C - M;
		if (free < 4 || free == 5 || free == 7)
		{
			PRINT("Impossible\n");
			continue;
		}
		if (R == 2 || C == 2) {
			if (free & 1) {
				PRINT("Impossible\n");
				continue;
			}
			else if (C == 2)
			{
				Int empty = R * C - M - 1;
				for (Int y = 0; y < R; y++)
				{
					for(Int x = 0; x < C; x++)
					{
						if (x == 0 && y==0) PRINT("c");
						else if (empty-- > 0)
						{
							PRINT(".");
						}
						else 
							PRINT("*");
					}
					PRINT("\n");
				}			
			}
			else // R == 2
			{
				PRINT("c");
				Int x = 1;
				for (; x < free / 2; x++)
				{
					PRINT(".");
				}
				for (; x < C; x++)
				{
					PRINT("*");
				}
				PRINT("\n");
				x = 0;
				for (; x < free / 2; x++)
				{
					PRINT(".");
				}
				for (; x < C; x++)
				{
					PRINT("*");
				}
				PRINT("\n");
			}
			continue;
		}
		// Big cases, both sides are: 50 >= R,C > 2
		bool board[50][50];
		memset(board, 0, sizeof(board));
		Int y = 0;
		Int x = 0;
		Int pairs = free / 2;
		for (y = 0; y < R; y++)
		{
			if (y & 1 == 1) continue;
			if (y == R-1) 
			{
				for(x = 1; x < C; x+=2)
				{
					if (pairs > 0)
					{
						board[x-1][y] = true;
						board[x][y] = true;
						pairs--;
					}
					if (pairs == 0)		break;
				}
				if (pairs == 0)	break;
			}
			else
			{
				for(x = 0; x < C; x++)
				{
					if (pairs > 0)
					{
						board[x][y] = true;
						board[x][y+1] = true;
						pairs--;
					}
					if (pairs == 0)	break;
				}
				if (pairs == 0)	break;
			}
		}
		if (free % 2 == 0) {
			if (x == 0)
			{
				// (y != C-1)
				swap(board[0][y+1], board[1][y]);
			}
		}
		else
		{
			if (y == R-1) // was on last line
			{
				board[x+1][y] = true;
			}
			else
			{
				if (x == 0)
				{
					swap(board[x][y+1], board[x+1][y]);
					board[x+2][y] = true;
				}
				else if (y == 0)
				{
					swap(board[x][y+1], board[0][y+2]);
					swap(board[x][y], board[1][y+2]);
					board[2][y+2] = true;
				}
				else if (x == C - 1)
				{
					swap(board[x][y+1], board[0][y+2]);
					board[1][y+2] = true;
				}
				else
				{
					board[x+1][y] = true;
				}
			}
		}		
		for (Int y = 0; y < R; y++)
		{
			for(Int x = 0; x < C; x++)
			{
				if (x == 0 && y==0) PRINT("c");
				else if (board[x][y])
				{
					PRINT(".");
				}
				else 
					PRINT("*");
			}
			PRINT("\n");
		}			
	}
	TRACE("ended.");
}