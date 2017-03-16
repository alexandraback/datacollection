// GCJ2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
int T,N,M;
int board[100][100];

bool judge()
{
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
		{
			bool heng = true; 
			for(int k=0;k<M;++k)
				if(board[i][j] < board[i][k])
					heng = false;
			bool shu = true;
			for(int k=0;k<N;++k)
				if(board[i][j] < board[k][j])
					shu = false;
			if ((heng || shu)==false) return false;
		}
	return true;
}
int main()
{

	freopen ( "B-small-attempt3.in", "r", stdin );
	freopen ( "out.out", "w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d%d",&N,&M);

		for(int i=0;i<N;++i)
			for(int j=0;j<M;++j)
				scanf("%d",&board[i][j]);
		bool res = judge();
		printf("Case #%d: ", t);
		if(res) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

