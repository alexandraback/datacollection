// GCJ.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
#include <iostream>

int main()
{
	int T;
	char board[4][5];

	freopen ( "A-small-attempt0.in", "r", stdin );
	freopen ( "out.out", "w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		bool com = true;
		bool Xwin = false;
		bool Owin = false;
		for(int i=0;i<4;++i)
			scanf("%s",board[i]);
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j)
				if(board[i][j] =='.') com = false;
		for(int i=0;i<4;++i)
		{
			Xwin = true;
			for(int j=0;j<4;++j)
			{
				if(!(board[i][j] == 'X' || board[i][j] == 'T'))
					Xwin = false;
			}
			if(Xwin) break;
			Xwin = true;
			for(int j=0;j<4;++j)
			{
				if(!(board[j][i] == 'X' || board[j][i] == 'T'))
					Xwin = false;
			}
			if(Xwin) break;
		}
		if(!Xwin)
		{
			Xwin = true;
			for(int i=0;i<4;++i)
			{
				if(!(board[i][i] == 'X' || board[i][i] == 'T'))
						Xwin = false;
			}
			if(!Xwin)
			{
				Xwin = true;
				for(int i=0;i<4;++i)
				{
					if(!(board[i][3-i] == 'X' || board[i][3-i] == 'T'))
							Xwin = false;
				}
			}
		}

		for(int i=0;i<4;++i)
		{
			Owin = true;
			for(int j=0;j<4;++j)
			{
				if(!(board[i][j] == 'O' || board[i][j] == 'T'))
					Owin = false;
			}
			if(Owin) break;
			Owin = true;
			for(int j=0;j<4;++j)
			{
				if(!(board[j][i] == 'O' || board[j][i] == 'T'))
					Owin = false;
			}
			if(Owin) break;
		}
		if(!Owin)
		{
		Owin = true;
		for(int i=0;i<4;++i)
		{
			if(!(board[i][i] == 'O' || board[i][i] == 'T'))
					Owin = false;
		}
		if(!Owin)
		{
		Owin = true;
		for(int i=0;i<4;++i)
		{
			if(!(board[i][3-i] == 'O' || board[i][3-i] == 'T'))
					Owin = false;
		}
		}
		}
		printf("Case #%d: ", t);
		if(Xwin) printf("X won\n");
		else if(Owin) printf("O won\n");
		else if(com == false) printf("Game has not completed\n");
		else printf("Draw\n");
	}
	return 0;
}

