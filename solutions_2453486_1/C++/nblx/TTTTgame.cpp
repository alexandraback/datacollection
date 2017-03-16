#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// state: 0->not over; 1->draw; 2->O; 3->X
void check_board(const vector<string> &board, int &state)
{
	int sums[10] = {0}, i, j;	
	for (i=0; i<4; i++)
	{
		for (j=0; j<4; j++)
			sums[i] += board[i][j];
		for (j=0; j<4; j++)
			sums[4+i] += board[j][i];
		sums[8] += board[i][i];
		sums[9] += board[i][3-i];
	}
	bool has_dot = false;
	for (i=0; i<10; i++)
	{
		if (316==sums[i] || 321==sums[i])
		{
			state = 2;
			return;
		}
		if (348==sums[i] || 352==sums[i])
		{
			state = 3;
			return;
		}
		if (sums[i]<316)		has_dot = true;
	}
	if (has_dot)
	{
		state = 0;
		return;
	}
	state = 1;
	return;
}

int main()
{
	ifstream inFile;
	inFile.open("A-large.in");
	ofstream outFile;
	outFile.open("TTTT_large.out");
	int nCases;		// #cases
	inFile >> nCases;
	inFile.ignore(10,'\n');			// skip new line character...
	vector<string> board;
	string temp;
	int state=-1;
	for (int i=0; i<nCases; i++)
	{
		board.clear();		// clear the board
		for (int j=0; j<4; j++)
		{
			temp.clear();
			getline(inFile,temp,'\n');
			board.push_back(temp);
		}
		inFile.ignore(10,'\n');		// skip an empty line
		check_board(board,state);		// state: 0->not over; 1->draw; 2->O; 3->X
		outFile << "Case #" << i+1 << ": ";
		if (state==0)
		{
			outFile << "Game has not completed" << endl;
		} else if (state==1)
		{
			outFile << "Draw" << endl;
		} else if (state==2)
		{
			outFile << "O won" << endl;
		}else
		{
			outFile << "X won" << endl;
		}
	}
	inFile.close();
	outFile.close();
	return 1;
}