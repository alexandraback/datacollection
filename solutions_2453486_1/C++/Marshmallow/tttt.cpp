
#include <fstream>
#include <iostream>
#include <sstream>
#include "tttt.h"

using namespace std;

void SolveTTTT()
{
	// Set up an input and output file
	ifstream file_in;
	file_in.open("C:\\Users\\John\\Desktop\\CodeJam\\tttt.in");
	ofstream file_out;
	file_out.open("C:\\Users\\John\\Desktop\\CodeJam\\tttt.out");

	// Load the number of test cases
	int test_cases;
	file_in >> test_cases;
	cout << test_cases << " cases" << endl;

	// Each case will have an array of 16 characters
	char game[16];

	// Loop over the cases
	for (int n = 0; n < test_cases; n++)
	{
		// Load the game
		cout << "Board " << (n+1) << ": ";
		for (int i = 0; i < 16; i++)
		{
			file_in >> game[i];
			cout << game[i];
		}
		cout << endl;

		// Now check to see if there's a win, case by case:
		bool finished = true;
		bool Xwon = false;
		bool Owon = false;

		char c;
		for (int i = 0; i < 4; i++)
		{
			// VERTICAL
			c = IsWin(game[i], game[i+4],game[i+8], game[i+12]);
			if (c == '.') finished = false;
			if (c == 'X') Xwon = true;
			if (c == 'O') Owon = true;

			// HORIZONTAL
			c = IsWin(game[4*i + 0], game[4*i + 1],game[4*i + 2],game[4*i + 3]);
			if (c == '.') finished = false;
			if (c == 'X') Xwon = true;
			if (c == 'O') Owon = true;
		}

		// TWO DIAGONALS
		c = IsWin(game[0], game[5], game[10], game[15]);
		if (c == '.') finished = false;
		if (c == 'X') Xwon = true;
		if (c == 'O') Owon = true;

		c = IsWin(game[3], game[6], game[9], game[12]);
		if (c == '.') finished = false;
		if (c == 'X') Xwon = true;
		if (c == 'O') Owon = true;


		file_out << "Case " << (n + 1) << ": ";
		cout << "Case " << (n + 1) << ": ";
		if (Xwon)
		{
			cout << "X won" << endl;
			file_out << "X won" << endl;
			continue;
		}
		if (Owon)
		{
			cout << "O won" << endl;
			file_out << "O won" << endl;
			continue;
		}
		if (finished) { cout << "Draw" << endl; file_out << "Draw" << endl; }
		else { cout << "Game has not completed" << endl; file_out << "Game has not completed" << endl; }
	}

	file_in.close();
	file_out.close();
	return;
}

char IsWin(char a, char b, char c, char d)
{
	bool Xcanwin = true;
	bool Ocanwin = true;

	char group[4] = {a, b, c, d};

	for (int i = 0; i < 4; i++)
	{
		if (group[i] == '.') return '.';
		else if (group[i] == 'O') Xcanwin = false;
		else if (group[i] == 'X') Ocanwin = false;
	}

	if (Xcanwin) return 'X';
	if (Ocanwin) return 'O';

	return 'F';
}

void DealWithChar(char c, bool &finished, bool &Xwon, bool &Owon)
{
	if (c == '.') finished = false;
	if (c == 'X') Xwon = true;
	if (c == 'O') Owon = true;
}




