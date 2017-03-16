#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bitset>
#include <utility>

using namespace std;

int main()
{
	ofstream cout ("TTTl.out");
        ifstream cin ("A-large.in");

	int trials;
	cin >> trials;

	for (int i = 0; i < trials; i++)
	{
		while (true)
		{
		bool complete = true;
		char game[4][4];
		cin >> game[0];
		cin >> game[1];
		cin >> game[2];
		cin >> game[3];

		bool seak = false;

		bool xc = true;
		bool oc = true;


		for (int j = 0; j < 4; j++)
		{
			xc = true;
			oc = true;
			for (int k = 0; k < 4; k++)
			{
				if (game[j][k] == '.' || game[j][k] == 'X')
					oc = false;
			    	if (game[j][k] == '.' || game[j][k] == 'O')
					xc = false;
			}
			if (xc == true)
				cout << "Case #" << i+1 << ": X won" << endl;
			if (oc == true)
				cout << "Case #" << i+1 << ": O won" << endl;
			if (oc || xc)
				seak = true;
		}
		if (seak)
			break;
		for (int j = 0; j < 4; j++)
		{
			xc = true;
			oc = true;
			for (int k = 0; k < 4; k++)
			{
				if (game[k][j] == '.' || game[k][j] == 'X')
					oc = false;
			    	if (game[k][j] == '.' || game[k][j] == 'O')
					xc = false;
			}
			if (xc == true)
				cout << "Case #" << i+1 << ": X won" << endl;
			if (oc == true)
				cout << "Case #" << i+1 << ": O won" << endl;
			if (oc || xc)
				seak = true;
		}
		if (seak)
			break;
		
		if ((game[0][0] == 'T' || game[0][0] == 'X')&&(game[1][1] == 'T' || game[1][1] == 'X')&&(game[2][2] == 'T' || game[2][2] == 'X')&&(game[3][3] == 'T' || game[3][3] == 'X'))
		{
			cout << "Case #" << i+1 << ": X won" << endl;
			seak = true;
		}
		if ((game[0][3] == 'T' || game[0][3] == 'X')&&(game[1][2] == 'T' || game[1][2] == 'X')&&(game[2][1] == 'T' || game[2][1] == 'X')&&(game[3][0] == 'T' || game[3][0] == 'X'))
		{
			cout << "Case #" << i+1 << ": X won" << endl;
			seak = true;
		}
		if (seak)
			break;

		if ((game[0][0] == 'T' || game[0][0] == 'O')&&(game[1][1] == 'T' || game[1][1] == 'O')&&(game[2][2] == 'T' || game[2][2] == 'O')&&(game[3][3] == 'T' || game[3][3] == 'O'))
		{
			cout << "Case #" << i+1 << ": O won" << endl;
			seak = true;
		}
		if ((game[0][3] == 'T' || game[0][3] == 'O')&&(game[1][2] == 'T' || game[1][2] == 'O')&&(game[2][1] == 'T' || game[2][1] == 'O')&&(game[3][0] == 'T' || game[3][0] == 'O'))
		{
			cout << "Case #" << i+1 << ": O won" << endl;
			seak = true;
		}
		if (seak)
			break;

		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (game[j][k] == '.')
					complete = false;
			}
		}
		if (!complete)
			cout << "Case #" << i+1 << ": Game has not completed" << endl;
		else
			cout << "Case #" << i+1 << ": Draw" << endl;
		break;
		}
	}

	return 0;	
}
