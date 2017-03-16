#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<string.h>
#include<utility>
#include<stdlib.h>
#include<cstdio>
using namespace std;
string grid[5];
int whoWon(int cnt1, int cnt2, bool t1, bool t2)
{
	if (cnt1 > 3 || cnt2 > 3 || (cnt1 == 3 && t1) || (cnt2 == 3 && t2))
		return 1;
	else if (cnt1 < -3 || cnt2 < -3 || (cnt1 == -3 && t1) || (cnt2 == -3 && t2))
		return 2;
	return 0;
}
int checkDiagonals()
{
	int cnt1 = 0, cnt2 = 0;
	bool t1 = false, t2 = false;
	for (int i = 0; i < 4; ++ i)
	{
		if (grid[i][3 -i] == 'X')
			cnt2 ++;
		else if (grid[i][3-i] == 'O')
			cnt2 --;
		else if (grid[i][3-i] == 'T')
			t2 = true;
		if (grid[i][i] == 'X')
			cnt1 ++;
		else if (grid[i][i] == 'O')
			cnt1 --;
		else if (grid[i][i] == 'T')
			t1 = true;
	}
	return whoWon(cnt1, cnt2,t1,t2);
}
int checkRowsCol()
{
	for (int i = 0; i < 4; ++ i)
	{
		int cnt1 = 0, cnt2 = 0;
		bool t1 = false, t2 = false;
		for (int j = 0; j < 4; ++ j)
		{
			if (grid[i][j] == 'X')
				cnt1 ++;
			else if (grid[i][j] == 'O')
				cnt1 --;
			else if (grid[i][j] == 'T')
				t1 = true;
			if (grid[j][i] == 'X')
				cnt2 ++;
			else if (grid[j][i] == 'O')
				cnt2 --;
			else if (grid[j][i] == 'T')
				t2 = true;
		}
		int who = whoWon(cnt1, cnt2,t1,t2);
		if (who == 0)
			continue;
		return who;
	}
	return 0;
}
int main()
{
	int t;
	ifstream in ("A-large.in");
	ofstream out ("output.txt");
	in >> t;
	in.ignore();
	for (int z = 1; z <= t; ++ z)
	{
		for (int i = 0; i < 5; ++ i)
			getline(in, grid[i]);
		int r = checkRowsCol(), d = checkDiagonals();
		if (r == 1 || d == 1)
			out << "Case #" << z << ": X won\n";
		else if (r == 2 || d == 2)
			out << "Case #" << z << ": O won\n";
		else
		{
			bool notFinished = false;
			for (int i = 0; i < 4; ++ i)
				for (int j = 0; j < 4; ++ j)
					if(grid[i][j] == '.'){
						notFinished = true;
						break;
					}
			if (notFinished)
				out << "Case #" << z << ": Game has not completed\n";
			else
				out << "Case #" << z << ": Draw\n";
		}
	}
}