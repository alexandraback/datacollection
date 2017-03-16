#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ldouble;

char a[5][5];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int ts; scanf("%d\n", &ts);
	for (int tst = 0; tst < ts; tst++)
	{
		printf("Case #%d: ", tst + 1);
		for (int i = 0; i < 4; i++)
			gets(a[i]);
		scanf("\n");
		int pts = 0, xs = 0, os = 0;
		for (int i = 0; i < 4; i++)
		{
			xs = 0, os = 0;
			for (int j = 0; j < 4; j++)
				if (a[i][j] == 'X') xs++;
				else if (a[i][j] == 'O') os++;
				else if (a[i][j] == 'T') xs++, os++;
				else if (a[i][j] == '.') pts++;
			if (xs == 4 || os == 4) break;
		}
		if (xs == 4) { printf("X won\n"); continue; }
		if (os == 4) { printf("O won\n"); continue; }
		for (int j = 0; j < 4; j++)
		{
			xs = 0, os = 0;
			for (int i = 0; i < 4; i++)
				if (a[i][j] == 'X') xs++;
				else if (a[i][j] == 'O') os++;
				else if (a[i][j] == 'T') xs++, os++;
				else if (a[i][j] == '.') pts++;
			if (xs == 4 || os == 4) break;
		}
		if (xs == 4) { printf("X won\n"); continue; }
		if (os == 4) { printf("O won\n"); continue; }
		xs = 0, os = 0;
		for (int i = 0; i < 4; i++)
				if (a[i][i] == 'X') xs++;
				else if (a[i][i] == 'O') os++;
				else if (a[i][i] == 'T') xs++, os++;
		if (xs == 4) { printf("X won\n"); continue; }
		if (os == 4) { printf("O won\n"); continue; }
		xs = 0, os = 0;
		for (int i = 0; i < 4; i++)
			if (a[i][3 - i] == 'X') xs++;
			else if (a[i][3 - i] == 'O') os++;
			else if (a[i][3 - i] == 'T') xs++, os++;
		if (xs == 4) { printf("X won\n"); continue; }
		if (os == 4) { printf("O won\n"); continue; }
		if (pts != 0) printf("Game has not completed\n"); 
		else printf("Draw\n");
	}
	
	return 0;
}