#include<cstdio>
#include<iostream>
#define N 4
using namespace std;

string map[4];
int check(const string map[])
{
	int x,o,t,e=0;
	for (int i=0;i<N;i++)
	{
		x=0;o=0;t=0;
		for (int j=0;j<N;j++)
			if (map[i][j]=='X') x++;
			else if (map[i][j]=='O') o++;
			else if (map[i][j]=='T') t++;
			else e++;
		if ( (x==3 && t==1) || x==4) return 1;
		if ( (o==3 && t==1) || o==4) return 2;
	}
	for (int i=0;i<N;i++)
	{
		x=0;o=0;t=0;
		for (int j=0;j<N;j++)
			if (map[j][i]=='X') x++;
			else if (map[j][i]=='O') o++;
			else if (map[j][i]=='T') t++;
		if ( (x==3 && t==1) || x==4) return 1;
		if ( (o==3 && t==1) || o==4) return 2;
	}
	x=0;o=0;t=0;
	for (int i=0;i<N;i++)
	{
		if (map[i][i]=='X') x++;
		else if (map[i][i]=='O') o++;
		else if (map[i][i]=='T') t++;
		if ( (x==3 && t==1) || x==4) return 1;
		if ( (o==3 && t==1) || o==4) return 2;
	}
	x=0;o=0;t=0;
	for (int i=0;i<N;i++)
	{
		if (map[i][N-i-1]=='X') x++;
		else if (map[i][N-i-1]=='O') o++;
		else if (map[i][N-i-1]=='T') t++;
		if ( (x==3 && t==1) || x==4) return 1;
		if ( (o==3 && t==1) || o==4) return 2;
	}

	if (e) return 0;
	return 3;
}
int main()
{
	int T;
	cin>>T;
	for (int run=1;run<=T;run++)
	{
		printf("Case #%d: ",run);
		for (int i=0;i<N;i++) cin>>map[i];
		int flag=check(map);
		if (flag==1) puts("X won");
		else if (flag==2) puts("O won");
		else if (flag==3) puts("Draw");
		else puts("Game has not completed");
	}
	return 0;
}
