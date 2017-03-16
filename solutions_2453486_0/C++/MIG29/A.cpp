#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:16777216")

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <numeric>
#include <algorithm>
#include <utility>
#include <bitset>
#include <cmath>
#include <sstream>
#include <functional>

#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()

using namespace std; 

typedef long long int64;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector<double> vd;
typedef vector< vd > vvd;
typedef vector< string > vs;
typedef pair< int, int > pii;
typedef vector< pii > vpii;



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
	int T = 0;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		vector<string> field(4);
		for (int i = 0; i < 4; i++)
		{
			while (field[i].empty())
				getline(cin, field[i]);
		}
		bool isXWon = false, isOWon = false, hasEmptySymbol = false;
		for (int i = 0; i < 4; i++)
		{
			int xCnt = 0, oCnt = 0, tCnt = 0;
			for (int j = 0; j < 4; j++)
			{
				if		(field[i][j] == 'X')
					xCnt++;
				else if (field[i][j] == 'O')
					oCnt++;
				else if (field[i][j] == 'T')
					tCnt++;
				else if (field[i][j] == '.')
					hasEmptySymbol = true;
			}
			if (xCnt + tCnt == 4 && tCnt <= 1)
			{
				isXWon = true;
				break;
			}
			else if (oCnt + tCnt == 4 && tCnt <= 1)
			{
				isOWon = true;
				break;
			}
			xCnt = 0, oCnt = 0, tCnt = 0;
			for (int j = 0; j < 4; j++)
			{
				if		(field[j][i] == 'X')
					xCnt++;
				else if (field[j][i] == 'O')
					oCnt++;
				else if (field[j][i] == 'T')
					tCnt++;
			}
			if (xCnt + tCnt == 4 && tCnt <= 1)
			{
				isXWon = true;
				break;
			}
			else if (oCnt + tCnt == 4 && tCnt <= 1)
			{
				isOWon = true;
				break;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			int xCnt = 0, oCnt = 0, tCnt = 0;
			for (int j = 0; j < 4; j++)
			{
				char c = 0;
				if (i == 0)
					c = field[j][j];
				else
					c = field[3 - j][j];
				if		(c == 'X')
					xCnt++;
				else if (c == 'O')
					oCnt++;
				else if (c == 'T')
					tCnt++;
			}
			if (xCnt + tCnt == 4 && tCnt <= 1)
			{
				isXWon = true;
				break;
			}
			else if (oCnt + tCnt == 4 && tCnt <= 1)
			{
				isOWon = true;
				break;
			}
		}
		
		cout << "Case #" << t + 1 << ": ";
		if (isXWon)
			cout << "X won" << endl;
		else if (isOWon)
			cout << "O won" << endl;
		else if (hasEmptySymbol)
			cout << "Game has not completed" << endl;
		else 
			cout << "Draw" << endl;
	}

    return 0;
}