#pragma comment(linker, "/STACK:500000000")
#include <functional>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <ctype.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#define Int long long
#define inf 0x3f3f3f3f
#define eps 1e-9
using namespace std;
#define N 1005

char A[5][5];

int main()
{
	freopen("i.txt", "rt", stdin);
	freopen("o.txt", "wt", stdout);
	int t, i, j;
	scanf("%d", &t);
	int tt = 0;
	while(t--)
	{
		tt++;
		for(i = 0; i < 4; i++)
			scanf("%s", &A[i]);
		bool isEmpty = false, X = false, O = false;
		for(i = 0; i < 4; i++)
		{
			bool xok = true, ook = true;
			for(j = 0; j < 4; j++)
			{
				if(A[i][j] != 'X' && A[i][j] != 'T')
					xok = false;
				if(A[i][j] != 'O' && A[i][j] != 'T')
					ook = false;
				if(A[i][j] == '.')
					isEmpty = true;
			}
			if(xok)
				X = true;
			if(ook)
				O = true;
		}

		for(j = 0; j < 4; j++)
		{
			bool xok = true, ook = true;
			for(i = 0; i < 4; i++)
			{
				if(A[i][j] != 'X' && A[i][j] != 'T')
					xok = false;
				if(A[i][j] != 'O' && A[i][j] != 'T')
					ook = false;
			}
			if(xok)
				X = true;
			if(ook)
				O = true;
		}

		bool xok = true, ook = true;
		for(i = 0; i < 4; i++)
		{
			if(A[i][i] != 'X' && A[i][i] != 'T')
				xok = false;
			if(A[i][i] != 'O' && A[i][i] != 'T')
				ook = false;
		}
		if(xok)
			X = true;
		if(ook)
			O = true;

		xok = true, ook = true;
		for(i = 0; i < 4; i++)
		{
			if(A[3 - i][i] != 'X' && A[3 - i][i] != 'T')
				xok = false;
			if(A[3 - i][i] != 'O' && A[3 - i][i] != 'T')
				ook = false;
		}
		if(xok)
			X = true;
		if(ook)
			O = true;

		printf("Case #%d: ", tt);
		if(X && !O)
			puts("X won");
		else
			if(O && !X)
				puts("O won");
			else
				if((X && O) || (!X && !O && !isEmpty))
					puts("Draw");
				else
					puts("Game has not completed");
	}
}  