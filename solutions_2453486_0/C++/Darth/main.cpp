#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("file.in");
ofstream fout ("file.out");

void Test(int caseNum);
bool CheckResult(int Xcount, int Ocount, int caseNum);

int main()
{
	int num;

	fin >> num;

	for (int i = 0; i < num; i++)
	{
		Test(i+1);
	}

	return 0;
}

void Test(int caseNum)
{
	char map[4][5];
	int i, r;
	int Ocount, Xcount;
	bool dots;
	char str[10];

	dots = false;
	fin.getline(str, 3);

	for (i = 0; i < 4; i++)
	{
		fin.getline(map[i], 5);
	}

	for (i = 0; i < 4; i++)
	{
		Ocount = 0; Xcount = 0;
		for (r = 0; r < 4; r++)
		{
			if (map[i][r] == 'X')
				Xcount++;
			if (map[i][r] == 'O')
				Ocount++;
			if (map[i][r] == 'T')
			{
				Xcount++; Ocount++;
			}
			if (map[i][r] == '.')
				dots = true;
		}
		if (CheckResult(Xcount, Ocount, caseNum))
			return;
	}
	
	for (r = 0; r < 4; r++)
	{
		Ocount = 0; Xcount = 0;
		for (i = 0; i < 4; i++)
		{
			if (map[i][r] == 'X')
				Xcount++;
			if (map[i][r] == 'O')
				Ocount++;
			if (map[i][r] == 'T')
			{
				Xcount++; Ocount++;
			}
		}
		if (CheckResult(Xcount, Ocount, caseNum))
			return;
	}

	Ocount = 0; Xcount = 0;
	for (i = 0; i < 4; i++)
	{
		if (map[i][i] == 'X')
			Xcount++;
		if (map[i][i] == 'O')
			Ocount++;
		if (map[i][i] == 'T')
		{
			Xcount++; Ocount++;
		}
	}
	if (CheckResult(Xcount, Ocount, caseNum))
			return;

	Ocount = 0; Xcount = 0;
	for (i = 0; i < 4; i++)
	{
		if (map[i][3-i] == 'X')
			Xcount++;
		if (map[i][3-i] == 'O')
			Ocount++;
		if (map[i][3-i] == 'T')
		{
			Xcount++; Ocount++;
		}
	}
	if (CheckResult(Xcount, Ocount, caseNum))
			return;

	if (dots)
	{
		fout << "Case #" << caseNum << ": " << "Game has not completed" << endl;
	} else {
		fout << "Case #" << caseNum << ": " << "Draw" << endl;
	}

}

bool CheckResult(int Xcount, int Ocount, int caseNum)
{
	if (Xcount == 4)
	{
		fout << "Case #" << caseNum << ": " << "X won" << endl;
		return true;
	}
	if (Ocount == 4)
	{
		fout << "Case #" << caseNum << ": " << "O won" << endl;
		return true;
	}
	return false;
}