// File Name: a.cpp
// Author: Missa
// Created Time: 2013/4/13 ÐÇÆÚÁù 11:38:13

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<cstdlib>
#include<map>
#include<set>
using namespace std;
#define CL(x,v) memset(x,v,sizeof(x));
#define R(i,st,en) for(int i=st;i<en;++i)
#define LL long long
#define inf 0x3f3f3f3f

const int maxn = 5;
char a[maxn][maxn];
int t;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&t);
	for (int cas = 1; cas <= t; ++cas)
	{
		memset(a,0,sizeof(a));
		bool Owin = false,Xwin = false,draw = true;
		for (int i = 0; i < 4; ++i)
			scanf("%s",&a[i]);
		//for (int i = 0; i < 4; ++i)
		//	cout<<a[i]<<endl;
		for (int i = 0; i <4; ++i)
			for (int j = 0; j < 4; ++j)
				if(a[i][j]=='.')
					draw = false;
		for (int i = 0; i < 4; ++i)
		{
			if ((a[i][0] == 'O' || a[i][0] == 'T') && (a[i][1] == 'O' || a[i][1] == 'T') && (a[i][2] == 'O' || a[i][2] == 'T') && (a[i][3] == 'O' || a[i][3] == 'T'))
				Owin = true;
			if ((a[i][0] == 'X' || a[i][0] == 'T') && (a[i][1] == 'X' || a[i][1] == 'T') && (a[i][2] == 'X' || a[i][2] == 'T') && (a[i][3] == 'X' || a[i][3] == 'T'))
				Xwin = true;
			if ((a[0][i] == 'O' || a[0][i] == 'T') && (a[1][i] == 'O' || a[1][i] == 'T') && (a[2][i] == 'O' || a[2][i] == 'T') && (a[3][i] == 'O' || a[3][i] == 'T'))
				Owin = true;
			if ((a[0][i] == 'X' || a[0][i] == 'T') && (a[1][i] == 'X' || a[1][i] == 'T') && (a[2][i] == 'X' || a[2][i] == 'T') && (a[3][i] == 'X' || a[3][i] == 'T'))
				Xwin = true;
		}
			if ((a[0][0] == 'O' || a[0][0] == 'T') && (a[1][1] == 'O' || a[1][1] == 'T') && (a[2][2] == 'O' || a[2][2] == 'T') && (a[3][3] == 'O' || a[3][3] == 'T'))
				Owin = true;
			if ((a[0][0] == 'X' || a[0][0] == 'T') && (a[1][1] == 'X' || a[1][1] == 'T') && (a[2][2] == 'X' || a[2][2] == 'T') && (a[3][3] == 'X' || a[3][3] == 'T'))
				Xwin = true;
			if ((a[0][3] == 'O' || a[0][3] == 'T') && (a[1][2] == 'O' || a[1][2] == 'T') && (a[2][1] == 'O' || a[2][1] == 'T') && (a[3][0] == 'O' || a[3][0] == 'T'))
				Owin = true;
			if ((a[0][3] == 'X' || a[0][3] == 'T') && (a[1][2] == 'X' || a[1][2] == 'T') && (a[2][1] == 'X' || a[2][1] == 'T') && (a[3][0] == 'X' || a[3][0] == 'T'))
				Xwin = true;
			printf("Case #%d: ",cas);
			if (Owin)
				printf("O won\n");
			else if (Xwin)
				printf("X won\n");
			else if(draw)
				printf("Draw\n");
			else
				printf("Game has not completed\n");
	}
    return 0;
}
