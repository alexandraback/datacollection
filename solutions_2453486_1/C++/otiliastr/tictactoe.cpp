#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

char a[10][10];

void setT(char p, int &tx, int &ty)
{
	for (int i = 0; i<4; ++i)
		for (int j = 0; j<4; ++j)
			if (a[i][j] == 'T')
			{
				tx = i;
				ty = j;
				a[i][j] = p;
				return;
			}
}

void restoreT(int tx, int ty)
{
	if (tx<5)
		a[tx][ty] = 'T';
}

bool win(char p)
{
	int tx = 5, ty;
	setT(p,tx,ty);
	
	//diag
	if (a[0][0] == p && a[0][0] == a[1][1] && a[0][0] == a[2][2] && a[0][0] == a[3][3])
	{
		restoreT(tx,ty);
		return true;
	}
	if (a[0][3] == p && a[1][2] == p && a[2][1] == p && a[3][0] == p)
	{
		restoreT(tx,ty);
		return true;
	}

	//randuri si coloane
	for (int i = 0; i<4; ++i)
		for (int j = 0; j<4; ++j)
			if ((a[i][0] == p && a[i][1] == p && a[i][2] == p && a[i][3] == p)
			  || (a[0][i] == p && a[1][i] == p && a[2][i] == p && a[3][i] == p))
			{
				restoreT(tx,ty);
				return true;
			}
	restoreT(tx,ty);
	return false;
}

bool iscomplete()
{
	for (int i = 0; i<4; ++i)
		for (int j = 0; j<4; ++j)
			if (a[i][j] == '.')
				return false;
	return true;
}

char * solve()
{
	bool xwin,owin,complet;
	xwin = win('X');
	owin = win('O');
	complet = iscomplete();

	if (!xwin && !owin)
		if (complet) return "Draw";
		else return "Game has not completed";
	if (xwin && owin)
		return "Draw";
	if (xwin)
		return "X won";
	
	return "O won";
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("tictac.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t = 1;t<=T;++t)
	{
		for (int i = 0; i<4; ++i)
			scanf("%s",&a[i]);
		printf("Case #%d: %s\n",t,solve());
	}
	return 0;
}
