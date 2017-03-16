#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <list>

#define uint64 unsigned long long
#define uint32 unsigned int

using namespace std;

ifstream inFile;

uint32 Xrow, Orow, Ts, Dots;
uint32 board[4][4] = {0};
//char board[4][4] = {0};
string line;



void fillBoard(void)
{
	for(int i = 0; i < 4; i++)
	{
		getline(inFile, line);
		for(int j = 0; j < 4; j++)
		{
			board[i][j] = (uint32) line[j];
			//cout << board[i][j] << " ";
		}
		//cout << "\n";
	}
}
bool checkStatus(void)
{
	Dots = 0;
	for(int i = 0; i < 4; i++)
	{
		Ts = 0;
		Xrow = 0;
		Orow = 0;
		for(int j = 0; j < 4; j++)
		{
			switch (board[i][j])
			{
			case (uint32)'T':
				Ts++;
				break;
			case (uint32)'X':
				Xrow++;
				break;
			case (uint32)'O':
				Orow++;
				break;
			default:
				Dots++;
				break;
			}
			//cout << board[i][j] << " ";
		}
		if (Xrow+Ts == 4)
		{
			cout << "X won\n";
			return true;
		}
		else if (Orow+Ts == 4)
		{
			cout << "O won\n";
			return true;
		}
	}
	
	for(int i = 0; i < 4; i++)
	{
		Ts = 0;
		Xrow = 0;
		Orow = 0;
		for(int j = 0; j < 4; j++)
		{
			switch (board[j][i])
			{
			case (uint32)'T':
				Ts++;
				break;
			case (uint32)'X':
				Xrow++;
				break;
			case (uint32)'O':
				Orow++;
				break;
			default:
				break;
			}
			//cout << board[j][i] << " ";
		}
		if (Xrow+Ts == 4)
		{
			cout << "X won\n";
			return true;
		}
		else if (Orow+Ts == 4)
		{
			cout << "O won\n";
			return true;
		}
	}
	Ts = 0;
	Xrow = 0;
	Orow = 0;
	for (int i = 0; i < 4; i++)
	{
		switch (board[i][i])
		{
		case (uint32)'T':
			Ts++;
			break;
		case (uint32)'X':
			Xrow++;
			break;
		case (uint32)'O':
			Orow++;
			break;
		default:
			break;
		}
	}	
	if (Xrow+Ts == 4)
	{
		cout << "X won\n";
		return true;
	}
	else if (Orow+Ts == 4)
	{
		cout << "O won\n";
		return true;
	}
	Ts = 0;
	Xrow = 0;
	Orow = 0;
	for (int i = 0; i < 4; i++)
	{
		switch (board[i][3-i])
		{
		case (uint32)'T':
			Ts++;
			break;
		case (uint32)'X':
			Xrow++;
			break;
		case (uint32)'O':
			Orow++;
			break;
		default:
			break;
		}
	}	
	if (Xrow+Ts == 4)
	{
		cout << "X won\n";
		return true;
	}
	else if (Orow+Ts == 4)
	{
		cout << "O won\n";
		return true;
	}
		
	if (Dots > 0)
		cout << "Game has not completed\n";
	else
		cout << "Draw\n";
}

int main(int argc, char* argv[])
{
	// Check if filename is passed to program
	
	if(argc < 2)
	{
		cout << "No files passed!\n";
		return 1;
	}
	
	uint32 datasetSize;
	
	inFile.open(argv[1]);
	inFile >> datasetSize;
	getline(inFile, line);
	clock_t time0 = clock();
	for(uint32 i = 0; i < datasetSize; i++)
	{
		fillBoard();
		cout << "Case #" << i+1 << ": ";
		checkStatus();
		getline(inFile, line);
	}
	cout << (double)(clock()-time0)/CLOCKS_PER_SEC << "\n";
	
	inFile.close();
	
	return 0;
}