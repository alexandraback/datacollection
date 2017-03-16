// GCJ2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
int T,N,E,R;
int dp[11][6];
int v[100];
int cal(int x, int y) // 剩y体力
{
	if(y<0) return -99999;
	if(x == 0) return 0;
	if(dp[x][y] != -99999) return dp[x][y];
	int ret = -99998;
	for(int i= y;i<=E;++i)
	{
		int val = (i-y)* v[x];
		int tp = val;
		if(x>1) tp += cal(x-1,i-R);
		if(tp > ret) ret = tp;
	}
	dp[x][y] = ret;
	return ret;
	
}
int main()
{

	freopen ( "B-small-attempt1.in", "r", stdin );
	freopen ( "out.out", "w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d%d%d",&E,&R,&N);
		if(R>E) R=E;
		for(int i=1;i<=N;++i)
				scanf("%d",&v[i]);
		int out = 0;
		for(int i=0;i<11;++i)
			for(int j =0;j<6;++j)
				dp[i][j] = -99999;
		for(int i=0;i<=E;++i)
		{
			int res = cal(N,i);
			if(out < res) out = res;
		}
		printf("Case #%d: %d\n", t,out);
	}
	return 0;
}

