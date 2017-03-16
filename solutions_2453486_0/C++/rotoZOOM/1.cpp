#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

char brd[4][5];

bool isWin (char c)
{
	int i,j;
	for (i=0;i<4;i++)
	{
		for (j=0;j<4 && (brd[i][j]==c || brd[i][j]=='T');j++);
		if (j==4) return true;
		for (j=0;j<4 && (brd[j][i]==c || brd[j][i]=='T');j++);
		if (j==4) return true;
	}
	for (i=0;i<4 && (brd[i][i]==c || brd[i][i]=='T');i++);
	if (i==4) return true;
	for (i=0;i<4 && (brd[i][3-i]==c || brd[i][3-i]=='T');i++);
	return i==4;
}

bool isEmptyExists()
{
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
			if (brd[i][j]=='.') return true;
	return false;
}

int main ()
{
	freopen ("input.txt","rt",stdin);
	freopen ("output.txt","wt",stdout);
	int test;

	scanf ("%d",&test);
	for (int step=1;step<=test;step++)
	{
		for (int i=0;i<4;i++) scanf ("%s", brd[i]);
		printf ("Case #%d: ",step);
		if (isWin('X')) printf ("X won");
		else if (isWin('O')) printf ("O won");
		else if (isEmptyExists()) printf ("Game has not completed");
		else printf ("Draw");
		printf ("\n");
	}
	return 0;
}