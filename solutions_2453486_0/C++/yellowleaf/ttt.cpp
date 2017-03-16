#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;
//#define DEBUG

const int BUFSIZE = 2 * 1024 * 1024;

bool occupied(char ch1, char ch2)
{
	return (ch1 == ch2 || ch1 == 'T');
}

bool checkWon(char ch, vector<string> &matrix)
{
	for (int row = 0; row < 4; row++)
	{
		if (occupied(matrix[row][0], ch) && occupied(matrix[row][1], ch) 
		 && occupied(matrix[row][2], ch) && occupied(matrix[row][3], ch))
		{
			return true;
		}
	}

	for (int col = 0; col < 4; col++)
	{
		if (occupied(matrix[0][col], ch) && occupied(matrix[1][col], ch) 
		 && occupied(matrix[2][col], ch) && occupied(matrix[3][col], ch))
		{
			return true;
		}
	}

	if (occupied(matrix[0][3], ch) && occupied(matrix[1][2], ch) 
	 && occupied(matrix[2][1], ch) && occupied(matrix[3][0], ch) )
	{
		return true;
	}

	if (occupied(matrix[0][0], ch) && occupied(matrix[1][1], ch) 
	 && occupied(matrix[2][2], ch) && occupied(matrix[3][3], ch) )
	{
		return true;
	}

	return false;
}

string  processOneCase(ifstream &ifs)
{
	vector<string> matrix;
	char buf[BUFSIZE];
	for (int i = 0; i < 4; i++)
	{
		ifs.getline(buf, BUFSIZE);
		matrix.push_back(buf);
	}
	ifs.getline(buf, BUFSIZE);

	if (checkWon('O', matrix))
	{
		return "O won";
	}
	else if (checkWon('X', matrix))
	{
		return "X won";
	}
	else
	{
		for (int row = 0; row < 4; row++)
			for (int col = 0; col < 4; col++)
			{
				if (matrix[row][col] == '.')
					return "Game has not completed";
			}
		return "Draw";
	}
}

int main(int argc, char *argv[])
{
	ifstream ifs(argv[1]);
	char buf[BUFSIZE];
	ifs.getline(buf, BUFSIZE);
	int lines = atoi(buf);

	for (int i = 0; i < lines; i++)
	{   
		string result = processOneCase(ifs); 
		cout << "Case #" << (i+1) << ": " << result  << endl;
	}   
	return 0;
}
