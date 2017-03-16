#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <cstring>
#include <string>
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
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

string o, s[4];
int flag;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
	int T; cin >> T;
	getline(cin, o);
	for (int t = 1; t <= T; t ++)
	{
		for (int i = 0; i < 4; i ++)
			getline(cin, s[i]);
		getline(cin, o);
		cout << "Case #" << t << ": ";
		flag = 0;
		for (int i = 0; i < 4; i ++)
			for (int j = 0; j < 4; j ++)
				if (s[i][j] == '.')
					flag = 1;
		
		int winX = 0, winO = 0;
		//horizontal
		for (int i = 0; i < 4; i ++)
		{
			int sx, so, st;
			sx = so = st = 0;
			for (int j = 0; j < 4; j ++)
				switch (s[i][j])
				{	
					case 'X' : sx ++; break;
					case 'O' : so ++; break;
					case 'T' : st ++; break;
				}
			if (sx == 4 || sx == 3 && st == 1) winX = 1;
			if (so == 4 || so == 3 && st == 1) winO = 1;
		}
		//vertical
		for (int j = 0; j < 4; j ++)
		{
			int sx, so, st;
			sx = so = st = 0;
			for (int i = 0; i < 4; i ++)
				switch (s[i][j])
				{	
					case 'X' : sx ++; break;
					case 'O' : so ++; break;
					case 'T' : st ++; break;
				}
			if (sx == 4 || sx == 3 && st == 1) winX = 1;
			if (so == 4 || so == 3 && st == 1) winO = 1;
		}
			
		//diagonal
		int sx, so, st;
		sx = so = st = 0;
		for (int i = 0; i < 4; i ++)
			switch (s[i][i])
			{	
				case 'X' : sx ++; break;
				case 'O' : so ++; break;
				case 'T' : st ++; break;
			}
		if (sx == 4 || sx == 3 && st == 1) winX = 1;
		if (so == 4 || so == 3 && st == 1) winO = 1;

		sx = so = st = 0;
		for (int i = 0; i < 4; i ++)
			switch (s[i][3 - i])
			{	
				case 'X' : sx ++; break;
				case 'O' : so ++; break;
				case 'T' : st ++; break;
			}
		if (sx == 4 || sx == 3 && st == 1) winX = 1;
		if (so == 4 || so == 3 && st == 1) winO = 1;
		
		if (winX && ! winO) cout << "X won";
			else if (winO && ! winX) cout << "O won";
				else if (flag) cout << "Game has not completed";
					else cout << "Draw";
		cout << endl;
	}
	return 0;
}
