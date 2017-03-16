#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int n;
string a[4];

int check(string s)
{
	int res = 3;
	for (int i = 0; i < 4; i++)
	{
		if (s[i] == '.') return 0;
		if (s[i] == 'X') res &= 1;
		if (s[i] == 'O') res &= 2;
	}
	return res;
}

int main()
{
	freopen("alarge.in", "r", stdin); 
	freopen("alarge.out", "w", stdout);
	
	int test;
	cin >> test;
	for (int itest = 1; itest <= test; itest++)
	{
		for (int i = 0; i < 4; i++) cin >> a[i];
		int mask = 0, cntCell = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cntCell += a[i][j] != '.';
				
		for (int i = 0; i < 4; i++) mask |= check(a[i]);
		
		for (int j = 0; j < 4; j++)
		{
			string s = "";
			for (int i = 0; i < 4; i++) s += a[i][j];
			mask |= check(s);
		}
		
		string s = "";
		for (int i = 0; i < 4; i++) s += a[i][i];
		mask |= check(s);
		s = "";
		for (int i = 0; i < 4; i++) s += a[i][3 - i];
		mask |= check(s);
		
		printf("Case #%d: ", itest);
		if (mask == 1) puts("X won");
		else
			if (mask == 2) puts("O won");
			else puts(cntCell == 16 ? "Draw" : "Game has not completed");
	}
}
