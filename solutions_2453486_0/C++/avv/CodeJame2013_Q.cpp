// CodeJame2013_Q.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "vector"
#include "string"
#include "set"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include <fstream>
using namespace std;


bool CheckWon(vector<string>& vec, ofstream& fout, int i)
{
	for (int j = 0; j < vec.size(); ++j)
	{
		
		
		if (vec[j][0] != '.' && vec[j][0] == vec[j][1] && vec[j][1] == vec[j][ 2] && vec[j][2] == vec[j][3])
		{
			fout << "Case #" << i + 1 << ": " << vec[j][0] << " won" << endl;
			return true;
		}


		if (vec[0][j] != '.' && vec[0][j] == vec[1][j] && vec[1][j] == vec[2][ j] && vec[2][j] == vec[3][j])
		{
			fout << "Case #" << i + 1 << ": " << vec[0][j] << " won" << endl;
			return true;
		}
	}

	if (vec[0][0] != '.' && vec[0][0] == vec[1][1] && vec[1][1] == vec[2][ 2] && vec[2][2] == vec[3][3])
	{
		fout << "Case #" << i + 1 << ": " << vec[0][0] << " won" << endl;
		return true;
	}
	if (vec[0][3] != '.' && vec[0][3] == vec[1][2] && vec[1][2] == vec[2][ 1] && vec[2][1] == vec[3][0])
	{
		fout << "Case #" << i + 1 << ": " << vec[0][3] << " won" << endl;
		return true;
	}

	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ofstream fout("out.txt");
	ifstream fin("in.txt");
	int T;
	fin >> T;
	vector<string> inputVec(4);
	vector<string> vec(4);
	string emptyLine;
	for (int i = 0; i < T; ++i)
	{
		fin >> inputVec[0];
		fin >> inputVec[1]; 
		fin >> inputVec[2];
		fin >> inputVec[3];

		bool finishGame = true;

		vec = inputVec;
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				if (inputVec[j][k] == 'T')
				{
					vec[j][k] = 'X';
				}
				if (inputVec[j][k] == '.')
				{
					finishGame = false;
				}
			}
		}

		bool someoneWon = CheckWon(vec, fout, i);
		if (!someoneWon)
		{
			for (int j = 0; j < 4; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					if (inputVec[j][k] == 'T')
					{
						vec[j][k] = 'O';
						break;
					}
				}
			}
			someoneWon = CheckWon(vec, fout, i);
		}

	
		if (!finishGame && !someoneWon)
		{
			fout << "Case #" << i + 1 << ": Game has not completed" << endl;
		}
		if (finishGame && !someoneWon)
		{
			fout << "Case #" << i + 1 << ": Draw" << endl;
		}

		//fin >> emptyLine;
	}
	return 0;
}

