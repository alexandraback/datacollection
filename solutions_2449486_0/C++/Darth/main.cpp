#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("file.in");
ofstream fout("file.out");

void Test(int caseNum);

int main()
{
	int num;

	fin >> num;

	for (int caseNum = 0; caseNum < num; caseNum++)
	{
		Test(caseNum);
	}

	return 0;
}

int map[100][100];
int x, y;
bool TestLine(int posX, int posY);

void Test(int caseNum)
{
	int i, r;
	
	fin >> y >> x;
	
	int maxNum = -1;

	for (r = 0; r < y; r++)
	{
		for (i = 0; i < x; i++)
		{
			fin >> map[i][r];
			if (map[i][r] > maxNum)
			{
				maxNum = map[i][r];
			}
		}
	}

	for (i = 0; i < x; i++)
	{
		for (r = 0; r < y; r++)
		{
			if (TestLine(i, r) == false)
			{
				fout << "Case #" << caseNum+1 << ": NO" << endl;
				return;
			}
		}
	}
	fout << "Case #" << caseNum+1 << ": YES" << endl;
}

bool TestLine(int posX, int posY)
{
	bool bad = false;
	for (int i = 0; i < x; i++)
	{
		if (map[i][posY] > map[posX][posY])
			bad = true;
	}
	if (bad)
	{
		for (int r = 0; r < y; r++)
		{
			if (map[posX][r] > map[posX][posY])
			{
				return false;
			}
		} 
	}

	return true;
}