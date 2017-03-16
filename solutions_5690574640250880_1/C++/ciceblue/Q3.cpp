#include <iostream>
#include <fstream>
#include <algorithm>
#define REP(i,s,n) for(int i=s;i<n;i++)
using namespace std;
ifstream fin("C-large.in");
ofstream fout("out.txt");
char mine[51][51];
int R, C, M;
void fillMine(int number)
{
	int pos = 0;
	int tR = R - pos;
	int tC = C - pos;
	int empty = number;
	bool hasTwo = false;
	cout << "fill" << empty << endl;
	while (empty > (tR + tC - 2) * 2)
	{
		hasTwo = true;
		REP(i, 0, tR)
		{
			mine[pos + i][pos + 0] = '.';
			mine[pos + i][pos + 1] = '.';
		}
		REP(i, 0, tC)
		{
			mine[pos + 0][pos + i] = '.';
			mine[pos + 1][pos + i] = '.';
		}
		empty -= (tR + tC - 2) * 2;
		tR -= 2; tC -= 2;
		pos += 2;
		if (tR == 1)
		{
			REP(i, 0, empty)
			{
				mine[pos][pos + i] = '.';
			}
			empty = 0;
		}
	}
	if (empty >= 2)
	{
		cout << "more?"<<empty << endl;
		int toR = 3;
		int toC = empty / 2 - 3;
		bool isCFull;
		isCFull = false;
		if (toC<0)
		{
			toR = toR + toC;
			toC = 0;
		}
		if (toC+2 > tC)
		{
			toR += toC+2 - tC;
			toC = tC-2;
			isCFull = true;
		}
		if (toR > tR)
		{
			toC += toR - tR;
			toR = tR;
		}
		REP(i, 0, toR)
		{
			mine[pos + i][pos + 0] = '.';
			mine[pos + i][pos + 1] = '.';
		}
		REP(i, 0, toC)
		{
			mine[pos][pos + i+2] = '.';
			mine[pos + 1][pos + i+2] = '.';
		}
		empty -= (toR + toC) * 2;
		if (empty)
		{
			cout << "empyt?"<<empty << endl;
			if (hasTwo)
			{
				if (isCFull)
				{
					mine[pos + toR][pos + 0] = '.';
				}
				else
				{
					mine[pos][pos + toC+2] = '.';
				}
			}
			else
			{
				mine[pos + 2][pos + 2] = '.';
			}
		}
	}
	else if (empty)
	{
		if (hasTwo)
		{
			mine[pos][pos] = '.';
		}
		else
		{
			mine[pos + 2][pos + 2] = '.';
		}
	}
}
int main()
{
	int T;
	fin >> T;
	int empty;
	bool isPossible;
	bool isTransed;
	REP(caseNumber, 1, T + 1)
	{
		fin >> R >> C >> M;
		isTransed = false;
		if (R > C)
		{
			int temp = R;
			R = C;
			C = temp;
			isTransed = true;
		}
		empty = R*C - M;
		isPossible = true;
		REP(i, 0, R)
		{
			REP(j, 0, C)
			{
				mine[i][j] = '*';
			}
		}
		if (empty <= 0)
		{
			isPossible = false;
		}
		else if (empty == 1)
		{
			mine[0][0] = '.';
			isPossible = true;
		}
		else
		{
			if (R == 1)
			{
				isPossible = true;
				REP(i, 0, empty)
				{
					mine[0][i] = '.';
				}
			}
			else if (R == 2)
			{
				if (empty >= 4 && empty % 2 == 0)
				{
					isPossible = true;
					REP(i, 0, (empty / 2))
					{
						mine[0][i] = '.';
						mine[1][i] = '.';
					}
				}
				else
				{
					isPossible = false;
				}
			}
			else
			{
				if (empty == 2 || empty == 3 || empty == 5 || empty == 7)
				{
					isPossible = false;
				}
				else
				{
					isPossible = true;
					fillMine(empty);
				}
			}
		}
		mine[0][0] = 'c';
		fout << "Case #" << caseNumber << ": \n";
		if (!isPossible)
		{
			fout << "Impossible\n";
		}
		else if (isTransed)
		{
			REP(i, 0, C)
			{
				REP(j, 0, R)
				{
					fout << mine[j][i];
				}
				fout << '\n';
			}
		}
		else
		{
			REP(i, 0, R)
			{
				REP(j, 0, C)
				{
					fout << mine[i][j];
				}
				fout << '\n';
			}
		}
	}
	return 0;
}