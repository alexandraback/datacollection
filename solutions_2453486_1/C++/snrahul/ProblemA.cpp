#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>
#include <list>
#include <deque>
#include <map>
#include <bitset>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;

int main()
{
	int n;
	ifstream in("A-large.in");
	ofstream out("output.out");
	in >> n;
	char a[4][4];
	for(int cases = 1; cases <= n; cases++)
	{
		bool isEmpty=false;
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				in >> a[i][j];
				if (a[i][j] == '.')
					isEmpty = true;
			}
		}
		bool playerX = false, playerO = false;
		bool gamewon = false;
		for(int i = 0; i < 4; i++)
		{
			int countX = 0, countO = 0;
			bool presentT = false;
			for(int j = 0; j < 4; j++)
			{
				if (a[i][j] == 'T')
					presentT = true;
				if (a[i][j] == 'X')
					countX++;
				if (a[i][j] == 'O')
					countO++;
			}
			if (presentT)
			{
				if(countX == 3)
				{
					out << "Case #" << cases << ": " << "X won" << endl;
					gamewon = true;
				}
				else if(countO == 3)
				{
					out << "Case #" << cases << ": " << "O won" << endl;
					gamewon = true;
				}
			}
			else
			{
				if(countX == 4)
				{
					out << "Case #" << cases << ": " << "X won" << endl;
					gamewon = true;
				}
				else if(countO == 4)
				{
					out << "Case #" << cases << ": " << "O won" << endl;
					gamewon = true;
				}
			}
			if (gamewon)
				break;
		}

		if (!gamewon)
		{
			for(int i = 0; i < 4; i++)
			{
				int countX = 0, countO = 0;
				bool presentT = false;
				for(int j = 0; j < 4; j++)
				{
					if (a[j][i] == 'T')
						presentT = true;
					if (a[j][i] == 'X')
						countX++;
					if (a[j][i] == 'O')
						countO++;
				}
				if (presentT)
				{
					if(countX == 3)
					{
						out << "Case #" << cases << ": " << "X won" << endl;
						gamewon = true;
					}
					else if(countO == 3)
					{
						out << "Case #" << cases << ": " << "O won" << endl;
						gamewon = true;
					}
				}
				else
				{
					if(countX == 4)
					{
						out << "Case #" << cases << ": " << "X won" << endl;
						gamewon = true;
					}
					else if(countO == 4)
					{
						out << "Case #" << cases << ": " << "O won" << endl;
						gamewon = true;
					}
				}
				if (gamewon)
					break;
			}
		}
		if (!gamewon)
		{
			int countX = 0, countO = 0;
			bool presentT = false;
			for(int i = 0; i < 4; i++)
			{
				if (a[i][i] == 'T')
					presentT = true;
				if (a[i][i] == 'X')
					countX++;
				if (a[i][i] == 'O')
					countO++;
			}
			if (presentT)
			{
				if(countX == 3)
				{
					out << "Case #" << cases << ": " << "X won" << endl;
					gamewon = true;
				}
				else if(countO == 3)
				{
					out << "Case #" << cases << ": " << "O won" << endl;
					gamewon = true;
				}
			}
			else
			{
				if(countX == 4)
				{
					out << "Case #" << cases << ": " << "X won" << endl;
					gamewon = true;
				}
				else if(countO == 4)
				{
					out << "Case #" << cases << ": " << "O won" << endl;
					gamewon = true;
				}
			}
		}
		if(!gamewon)
		{
			int countX = 0, countO = 0;
			bool presentT = false;
			for(int i = 0; i < 4; i++)
			{
				if (a[i][3-i] == 'T')
					presentT = true;
				if (a[i][3-i] == 'X')
					countX++;
				if (a[i][3-i] == 'O')
					countO++;
			}
			if (presentT)
			{
				if(countX == 3)
				{
					out << "Case #" << cases << ": " << "X won" << endl;
					gamewon = true;
				}
				else if(countO == 3)
				{
					out << "Case #" << cases << ": " << "O won" << endl;
					gamewon = true;
				}
			}
			else
			{
				if(countX == 4)
				{
					out << "Case #" << cases << ": " << "X won" << endl;
					gamewon = true;
				}
				else if(countO == 4)
				{
					out << "Case #" << cases << ": " << "O won" << endl;
					gamewon = true;
				}
			}
		}
		if (!gamewon)
		{
			if (isEmpty)
				out << "Case #" << cases << ": " << "Game has not completed" << endl;
			else
				out << "Case #" << cases << ": " << "Draw" << endl;
		}
	}
	system("pause");
	return 0;
}