#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>


#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;

inline long double get_time(){   
	return (long double)clock()/CLOCKS_PER_SEC;
};


int board[4][4];
char line[25];

int main()
{
	int t;int css = 1;
	freopen("tic-tac-toe-tomek.in","r",stdin);
	freopen("tic-tac-toe-tomek.out","w",stdout);
	//program
	scanf("%d\n", &t);
	while (t--)
	{
		for (int i = 0; i < 4; ++i)
		{
			scanf("%s\n", line);
			for (int j = 0; j < 4; ++j)
			{
				if (line[j] == '.') board[i][j] = 0;
				if (line[j] == 'T') board[i][j] = 9;
				if (line[j] == 'O') board[i][j] = 1;
				if (line[j] == 'X') board[i][j] = 2;
			}
		}
		int dots = 0;
		//rows
		for (int i = 0; i < 4; ++i)
		{
			int O = 0;
			int X = 0;
			for (int j = 0; j < 4; ++j)
			{
				if (board[i][j] == 1) O++;
				if (board[i][j] == 2) X++;
				if (board[i][j] == 9) O++, X++;
				if (board[i][j] == 0) dots++;
			}
			if (O >= 4) {printf("Case #%d: O won\n", css++); goto endtest;}
			if (X >= 4) {printf("Case #%d: X won\n", css++); goto endtest;}
		}
		//cols
		for (int j = 0; j < 4; ++j)
		{
			int O = 0;
			int X = 0;
			for (int i = 0; i < 4; ++i)
			{
				if (board[i][j] == 1) O++;
				if (board[i][j] == 2) X++;
				if (board[i][j] == 9) O++, X++;
			}
			if (O >= 4) {printf("Case #%d: O won\n", css++); goto endtest;}
			if (X >= 4) {printf("Case #%d: X won\n", css++); goto endtest;}
		}
		//leftdiag
		{
			int O = 0;
			int X = 0;
			for (int i = 0; i < 4; ++i)
			{
				if (board[i][i] == 1) O++;
				if (board[i][i] == 2) X++;
				if (board[i][i] == 9) O++, X++;
			}
			if (O >= 4) {printf("Case #%d: O won\n", css++); goto endtest;}
			if (X >= 4) {printf("Case #%d: X won\n", css++); goto endtest;}
		}
		//rightdiag
		{
			int O = 0;
			int X = 0;
			for (int i = 0; i < 4; ++i)
			{
				if (board[3-i][i] == 1) O++;
				if (board[3-i][i] == 2) X++;
				if (board[3-i][i] == 9) O++, X++;
			}
			if (O >= 4) {printf("Case #%d: O won\n", css++); goto endtest;}
			if (X >= 4) {printf("Case #%d: X won\n", css++); goto endtest;}
		}
		if (dots) printf("Case #%d: Game has not completed\n", css++);
		else printf("Case #%d: Draw\n", css++);
endtest:
		scanf("\n");
	}
	//end program
	return 0;
}






