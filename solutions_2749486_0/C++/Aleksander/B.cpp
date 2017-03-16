#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

const int MID = 5000;

vector < int > ansX, ansY;
int f[505][10005];
int p[505][10005];
int xFinal, yFinal;
bool xRev, yRev;
int fCol;

void getAnsVector (int endPos, int ind, vector < int > & ans)
{
	ans.clear();

	int cur = endPos;

	while (p[ind][cur] != -1)
	{
		int prv = p[ind][cur];

		if (cur - prv > 0)
			ans.push_back(1);
		else
			ans.push_back(-1);

		cur = prv;
		ind--;
	}

	reverse(ans.begin(), ans.end() );
}

void tryAdd (int pos, int val)
{
	if (pos + val > 10000)
		return ;

	f[val][pos + val] = fCol;
	p[val][pos + val] = pos;
}

void trySub (int pos, int val)
{
	if (pos - val < 0)
		return ;

	f[val][pos - val] = fCol;
	p[val][pos - val] = pos;
}

void getAns (int endPos, vector < int > & ans, int s)
{
	for (int i = 0; i <= 10000; i++)
		f[s - 1][i] = 0;
	f[s - 1][MID] = fCol;
	p[s - 1][MID] = -1;

	endPos += MID;

	for (int i = s; i <= 500; i++)
	{
		for (int j = 0; j <= 10000; j++)
		{
			if (f[i - 1][j] != fCol)
				continue;

			tryAdd(j, i);
			trySub(j, i);
		}

		if (f[i][endPos] == fCol)
		{
			getAnsVector(endPos, i, ans);
			return ;
		}
	}

	throw 42;
}

void solve ()
{
	xRev = false; yRev = false;

	if (xFinal < 0)
	{
		xFinal *= -1;
		xRev = true;
	}
	if (yFinal < 0)
	{
		yFinal *= -1;
		yRev = true;
	}
	
	getAns(xFinal, ansX, 1);
	getAns(yFinal, ansY, ansX.size() + 1);

	for (int i = 0; i < ansX.size(); i++)
	{
		if ( (ansX[i] == 1) ^ (xRev) )
			printf("E");
		else
			printf("W");
	}
	for (int i = 0; i < ansY.size(); i++)
	{
		if ( (ansY[i] == 1) ^ (yRev) )
			printf("N");
		else
			printf("S");
	}
}

int main ()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int test, t;

	scanf("%d\n", &test);
	for (t = 0; t < test; t++)
	{
		if (t)
			printf("\n");

		printf("Case #%d: ", t + 1);

		// input

		scanf("%d%d", &xFinal, &yFinal);

		fCol = t + 1;

		// #input

		solve();
	}

	return 0;
}