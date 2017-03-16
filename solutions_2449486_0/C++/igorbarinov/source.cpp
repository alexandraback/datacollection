#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("file.in");
ofstream fout("file.out");

// map and size
int lawn[100][100];
int x, y;

// functions
void Calculate(int caseNum);
bool CheckLine(int posX, int posY);

int main()
{
	int num;

	fin >> num;

	for (int caseNum = 0; caseNum < num; caseNum++)
	{
		Calculate(caseNum);
	}

	return 0;
}

void Calculate(int caseNum)
{
	int i, r;
	int maxNum = -1;
	
	fin >> y >> x;

	for (r = 0; r < y; r++) {
		for (i = 0; i < x; i++){
			fin >> lawn[i][r];

			if (lawn[i][r] > maxNum)
			{
				maxNum = lawn[i][r];
			}
		}
	}

	for (i = 0; i < x; i++) 
		for (r = 0; r < y; r++)
			if (CheckLine(i, r) == false)
			{
				fout << "Case #" << (caseNum + 1) << ": NO" << endl;
				return;
			}

	fout << "Case #" << (caseNum + 1) << ": YES" << endl;
}

bool CheckLine(int posX, int posY)
{
	bool incorrect = false;
	for (int i = 0; i < x; i++)
		if (lawn[i][posY] > lawn[posX][posY])
			incorrect = true;

	if (incorrect)
	{
		for (int r = 0; r < y; r++)
			if (lawn[posX][r] > lawn[posX][posY])
				return false;
	}

	return true;
}